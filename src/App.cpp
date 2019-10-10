#include "App.h"
#include "RootWindow.h"

IMPLEMENT_APP(App);

bool App::OnInit()
{
	RootWindow* rw = new RootWindow();
	rw->Show(true);

	return true;
}
