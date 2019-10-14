#include "Grid.h"

Grid::Grid(wxPanel* parent, const t_cells* cells)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
	, parent(parent)
	, cells(cells)
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(Grid::OnPaint));
	this->Center();
}

void Grid::drawCells()
{
	wxPaintDC dc(this);
	dc.SetPen(wxPen(wxColor(0, 0, 0)));

	wxBrush blackBrush = wxBrush(wxColor(0, 0, 0));
	wxBrush whiteBrush = wxBrush(wxColor(255, 255, 255));

	std::size_t cells_size = cells->size();
	for (int row_index = 0; row_index != cells_size; ++row_index)
	{
		const std::vector<int> row = cells->at(row_index);
		std::size_t row_size = row.size();
		for (int column = 0; column < row_size; ++column)
		{
			dc.SetBrush(row[column] > 0 ? blackBrush : whiteBrush);
			dc.DrawRectangle(column * CELL_SIZE, row_index * CELL_SIZE, CELL_SIZE, CELL_SIZE);
		}
	}
}

void Grid::OnPaint(wxPaintEvent& event)
{
	drawCells();
}
