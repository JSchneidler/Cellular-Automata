#pragma once

#include <wx/wx.h>
#include "CellularAutomata.h"


class Grid : public wxPanel
{
public:
	Grid(wxPanel* parent);

	void drawCells();
	void OnPaint(wxPaintEvent& event);

private:
	wxPanel* parent;
};

