#pragma once

#include <wx/wx.h>
#include "CellularAutomata.h"


class Grid : public wxPanel
{
public:
	Grid(wxPanel* parent, const t_cells* cells);

	void drawCells();
	void OnPaint(wxPaintEvent& event);

private:
	wxPanel* parent;
	const t_cells* cells;
};

