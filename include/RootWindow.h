#pragma once

#include <wx/wx.h>
#include "LeftPanel.h"
#include "Grid.h"
#include "CellularAutomata.h"

class RootWindow : public wxFrame
{
public:
	RootWindow();

private:
	wxPanel* parent;
	LeftPanel* left_panel;
	Grid* grid;
	CellularAutomata* simulation;
};

