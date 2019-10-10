#include "RootWindow.h"
#include "App.h"
#include "Config.h"

const int WIDTH = std::max(ROW_LENGTH * CELL_SIZE + 100, 250);
const int HEIGHT = std::max((DEFAULT_ROWS + 1) * CELL_SIZE, 150);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Cellular Automata v%d.%d"), MAJOR_VERSION, MINOR_VERSION), wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{
	parent = new wxPanel(this, wxID_ANY);
	left_panel = new LeftPanel(parent);
	grid = new Grid(parent);
	simulation = new CellularAutomata(DEFAULT_RULE);

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 1, wxEXPAND | wxALL, 5);
	hbox->Add(grid, 1, wxEXPAND | wxALL, 5);

	parent->SetSizer(hbox);
	this->Center();
}
