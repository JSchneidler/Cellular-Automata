#include "LeftPanel.h"
#include "App.h"

LeftPanel::LeftPanel(wxPanel* parent)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	this->parent = parent;
	
	rule_input = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%d"), DEFAULT_RULE), wxPoint(10, 10), wxSize(-1, -1));
	rows_input = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%d"), DEFAULT_ROWS), wxPoint(10, 40), wxSize(-1, -1));
	start_button = new wxButton(this, ID_START, wxT("Start"), wxPoint(10, 70));
}
