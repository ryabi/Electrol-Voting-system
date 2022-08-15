
#include<wx/wx.h>
#include "Myapp.h"
#include"MainFrame.h"
#include "VotingArea.h"

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit() {
	wxWindow* hello;
	hello = new wxWindow(NULL, wxID_ANY);
	MainFrame* frame = new MainFrame("Electrol Voting System", wxDefaultPosition, wxSize(800, 800));
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}
