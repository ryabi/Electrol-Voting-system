#include <wx/wx.h>
#include "MainFrame.h"
MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 800)) {

}

bool MyApp::OnInit() {
	MainFrame* LogInFrame = new MainFrame("Electrol Voting System");
	LogInFrame->Show();
	return true;
}
