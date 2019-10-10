#pragma once

#include <wx/wx.h>

const int CELL_SIZE = 10;
const int DEFAULT_RULE = 66847740;
const int DEFAULT_ROWS = 5;
const int ROW_LENGTH = (DEFAULT_ROWS * 2) + 1;

class App : public wxApp
{
public:
	virtual bool OnInit();
};

