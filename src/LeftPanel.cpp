#include "LeftPanel.h"
#include "App.h"
#include "RootWindow.h"

LeftPanel::LeftPanel(wxPanel* parent)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
	, parent(parent)
	, rule_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%d"), DEFAULT_RULE), wxPoint(10, 10), wxSize(-1, -1)))
	, rows_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%d"), DEFAULT_ROWS), wxPoint(10, 40), wxSize(-1, -1)))
	, start_button(new wxButton(this, ID_SIMULATE, wxT("Simulate"), wxPoint(10, 70)))
{
	Connect(ID_SIMULATE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnSimulate));
}

void LeftPanel::OnSimulate(wxCommandEvent& event)
{
	RootWindow* rw = (RootWindow *) parent->GetParent();

	int rule = wxAtoi(rule_input->GetValue());
	int rows = wxAtoi(rows_input->GetValue());

	rw->setSimulationParameters(rule, rows);
}