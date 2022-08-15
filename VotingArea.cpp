#include "VotingArea.h"
#include"Myapp.h"
#include <wx/wx.h>
//Function to hold candident name by reading from respecive files
wxArrayString candidateList(string s) {
	wxArrayString data;
	ifstream reading(s);
	string buffer;

	if (reading.is_open()) {
		while (!reading.eof()) {
			getline(reading, buffer, ',');
			data.Add(buffer);
		}
	}
	else
	{
		wxMessageDialog error(NULL, "Can't load Candiate List");
		error.ShowModal();
	}
	return data;
}


VotingArea::VotingArea(const wxString& title,const wxPoint &pos,const wxSize &size, string s, MainFrame &close):wxFrame(NULL, wxID_ANY, title,pos,size) {
	username = s;
	
	wxMessageDialog hawa(NULL,username);
	hawa.ShowModal();

	CreateStatusBar(3);
	//delete previous log in frame;
	close.Close();
	//Making menu Bar
	wxMenu* filemenu = new wxMenu;
	filemenu->Append(wxID_ABOUT);
	filemenu->Append(wxID_CUT);
	wxMenu* helpmenu = new wxMenu;
	helpmenu->Append(wxID_HELP);

	wxMenuBar* menubar = new wxMenuBar;
	menubar->Append(filemenu, "&File");
	menubar->Append(helpmenu, "&Help");
	SetMenuBar(menubar);


	
	
	//this->setCandidateList(presidentCandidate, "presidentCandidateList");

	
	//Main body 
	
	wxPanel* HeaderPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(800, 110));
	wxImage i1("votingicon.bmp"), i2;
	i2 = i1.Scale(100, 100, wxIMAGE_QUALITY_NORMAL);//scaling image
	wxStaticBitmap* img = new wxStaticBitmap(HeaderPanel, wxID_ANY, i2, wxPoint(90, 5));//Adding image In header Panel
	wxStaticText* Header = new wxStaticText(HeaderPanel, wxID_STATIC, "Welcome to Digital Voting System", wxPoint(200, 20), wxDefaultSize);
	FontChanger(Header, 18, wxFONTFAMILY_SCRIPT, wxFONTWEIGHT_NORMAL, true);

	wxStaticText* text = new wxStaticText(HeaderPanel, wxID_ANY, "\"Vote for Your Right!!\"", wxPoint(450, 50), wxDefaultSize);
	FontChanger(text, 12);
	//voting section

	
	
	//wxBoxSizer* innersizer = new wxBoxSizer(wxHORIZONTAL);
	wxPanel* VotingPanel = new wxPanel(this, wxID_ANY,wxPoint(0,115),wxSize(450,680));


	wxStaticText* hint1 = new wxStaticText(VotingPanel, wxID_ANY, "Choose one candident for each post:", wxPoint(0, 5), wxDefaultSize);
	FontChanger(hint1, 16);
	//Voting for Persident
	wxStaticText* presidentText = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Persident", wxPoint(25, 75));
	 presidentList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(25, 100), wxSize(150, -1), candidateList("presidentCandidateList.txt"));
	//voting for  Vice persident
	wxStaticText* vicepresidentText = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Vice Persident", wxPoint(220, 75));
	 vicepresidentList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(220, 100), wxSize(150, -1),candidateList("vicePresidentCandidateList.txt"));
	//voting for secratary
	wxStaticText* secretaryText = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Secratary", wxPoint(25, 200));
	 secrataryList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(25, 220), wxSize(150, -1),candidateList("secrataryCandidateList.txt"));
//voting for vice secratary
	wxStaticText* joint_secrataryText = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Joint-Secratary", wxPoint(220, 200));
	 joint_secrataryList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(220, 220),wxSize(150,-1),candidateList("jointSecrataryCandidateList.txt"));
//voting for tresurer
	wxStaticText* tresurar = new wxStaticText(VotingPanel , wxID_ANY,"Vote for Treasurar", wxPoint(25, 300));
	 treasurarList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(25, 320),wxSize(150,-1),candidateList("treasurarCandidateList.txt"));
//voting member
	wxStaticText* member = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Member", wxPoint(220, 300));
	 memberList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(220, 320), wxSize(150, -1),candidateList("memberCandidateList.txt"));

//Information
	wxStaticText *hint2 = new wxStaticText(VotingPanel, wxID_ANY, "To cast your Vote for Choosen candident Press Confirm ", wxPoint(0, 400));
	FontChanger(hint2, 13, wxFONTFAMILY_SCRIPT);
	wxButton* confirm = new wxButton(VotingPanel, wxID_ANY, "Confirm", wxPoint(250, 430),wxSize(100,-1));
	confirm->Bind(wxEVT_BUTTON, &VotingArea::OnConfirm, this);
	wxButton* result = new wxButton(VotingPanel, wxID_ANY, "Click to see reasult", wxPoint(250, 450), wxSize(250, -1));
	result->Bind(wxEVT_BUTTON, &VotingArea::OnResult, this);

	//Notice and Information Panel
	wxPanel* NoticePanel = new wxPanel(this, wxID_ANY, wxPoint(458,115),wxSize(330,680));
	wxStaticText* notice = new wxStaticText(NoticePanel, wxID_ANY, "Hello,"+ username, wxPoint(0, 15));
	FontChanger(notice, 14, wxFONTFAMILY_MODERN, wxFONTWEIGHT_SEMIBOLD, true);
	wxStaticText* instruction = new wxStaticText(NoticePanel, wxID_ANY, "Plese read this Rules and Instruction befor voting:", wxPoint(0, 45),wxDefaultSize,wxID_UNDERLINE);

/*
	innersizer->Add(VotingPanel, 1, wxEXPAND|wxTOP | wxRIGHT | wxLEFT, 10);
	innersizer->Add(NoticePanel, 1, wxEXPAND|wxALL,10);
	*/
	//BodyPanel->SetSizerAndFit(innersizer);
}