#pragma once

#include <wx/wx.h>

const int ID_SIMULATE = 100;

class LeftPanel : public wxPanel
{
public:
	LeftPanel(wxPanel* parent);

private:
	wxPanel* parent;
	wxTextCtrl* rule_input;
	wxTextCtrl* rows_input;
	wxButton* start_button;

	void OnSimulate(wxCommandEvent& event);
};

