#include "RootWindow.h"
#include "App.h"
#include "Config.h"

const int WIDTH = std::max(ROW_LENGTH * CELL_SIZE + 100, 250);
const int HEIGHT = std::max((DEFAULT_ROWS + 1) * CELL_SIZE, 150);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Cellular Automata v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{
	simulation = new CellularAutomata(DEFAULT_RULE, DEFAULT_ROWS);

	parent = new wxPanel(this, wxID_ANY);
	left_panel = new LeftPanel(parent);
	grid = new Grid(parent, simulation->getCells());

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 1, wxEXPAND | wxALL, 5);
	hbox->Add(grid, 1, wxEXPAND | wxALL, 5);

	parent->SetSizer(hbox);
	this->Center();
}
