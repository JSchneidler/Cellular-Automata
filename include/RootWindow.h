#pragma once

#include <wx/wx.h>
#include "LeftPanel.h"
#include "Grid.h"
#include "CellularAutomata.h"

class RootWindow : public wxFrame
{
public:
	RootWindow();

	void setSimulationParameters(const int rule, const int rows);

private:
	CellularAutomata* simulation;
	wxPanel* parent;
	LeftPanel* left_panel;
	Grid* grid;

	int calculateWidth(int row_length);
	int calculateHeight(int rows);
	void redraw();
};

