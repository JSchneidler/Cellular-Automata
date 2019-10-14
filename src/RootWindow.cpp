#include "RootWindow.h"
#include "App.h"
#include "Config.h"

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Cellular Automata v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, wxSize(calculateWidth(ROW_LENGTH), calculateHeight(DEFAULT_ROWS)))
	, simulation(new CellularAutomata(DEFAULT_RULE, DEFAULT_ROWS))
	, parent(new wxPanel(this, wxID_ANY))
	, left_panel(new LeftPanel(parent))
	, grid(new Grid(parent, simulation->getCells()))
{
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 1, wxEXPAND | wxALL, 5);
	hbox->Add(grid, 2, wxEXPAND | wxALL, 5);

	parent->SetSizer(hbox);
	this->Center();
}

void RootWindow::setSimulationParameters(const int rule, const int rows)
{
	if (simulation->getRule() == rule && simulation->getRows() == rows) return;

	simulation->setRule(rule);
	simulation->setRows(rows);
	redraw();
}

int RootWindow::calculateWidth(int row_length)
{
	return std::max((row_length * CELL_SIZE) + 200, 250);
}

int RootWindow::calculateHeight(int rows)
{
	return std::max((rows + 1) * CELL_SIZE, 150);
}

void RootWindow::redraw()
{
	int rows = simulation->getRows();
	int row_length = (rows * 2) + 1;

	this->SetSize(wxSize(calculateWidth(row_length), calculateHeight(rows)));
	simulation->execute();
	grid->drawCells();
}