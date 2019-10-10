#include "Grid.h"

Grid::Grid(wxPanel* parent)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	this->parent = parent;

	Connect(wxEVT_PAINT, wxPaintEventHandler(Grid::OnPaint));

	this->Center();
}

void Grid::drawCells()
{
	wxPaintDC dc(this);
	dc.SetPen(wxPen(wxColor(0, 0, 0)));

	for (int i = 0; i < DEFAULT_ROWS + 1; i++) {
		for (int j = 0; j < ROW_LENGTH; j++) {
			dc.DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
		}
	}
}

void Grid::OnPaint(wxPaintEvent& event)
{
	drawCells();
}
