#include "MainFrame.h"
#include "VotingArea.h"

#include<cstring>
//Function to change StaticText font


MainFrame::MainFrame(const wxString& title,const wxPoint &pos,const wxSize &size) : wxFrame(NULL, wxID_ANY, title,pos,size) {

	CreateStatusBar(2);

	//Creating the outter window
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	//Creating the inner window
	wxPanel* HeaderPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(750, 50));
	wxPanel* registerPanel = new wxPanel(this,wxID_ANY,wxPoint(0,60),wxSize(750,350));
	wxPanel* loginPanel = new wxPanel(this);

	//Element for Header Panel
	
	wxImage i1("votingicon.BMP"),i2; 
	i2 = i1.Scale(100,100, wxIMAGE_QUALITY_NORMAL);//scaling image
	wxStaticBitmap* img = new wxStaticBitmap(HeaderPanel, wxID_ANY,i2, wxPoint(90, 5));//Adding image In header Panel
	
	
	wxStaticText* Header = new wxStaticText(HeaderPanel, wxID_STATIC,"Welcome to Digital Voting System",wxPoint(200,20),wxDefaultSize);
	FontChanger(Header, 18, wxFONTFAMILY_SCRIPT,wxFONTWEIGHT_NORMAL,true);

	wxStaticText* text = new wxStaticText(HeaderPanel, wxID_ANY, "\"Vote for Your Right!!\"", wxPoint(450,50), wxDefaultSize);
	FontChanger(text, 12);
	

	//Element for the register panel is added
	
	wxStaticText* signUpText = new wxStaticText(registerPanel, wxID_ANY, "Register to Digital Voting System", wxPoint(50, 5));
	FontChanger(signUpText, 12,wxFONTFAMILY_DEFAULT, wxFONTWEIGHT_BOLD);

	wxStaticText* firstname = new wxStaticText(registerPanel, wxID_ANY, "First Name :", wxPoint(15, 50), wxSize(85, -1));
	FontChanger(firstname, 12);
	firstnamectrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140, 45), wxSize(200, -1));
	wxStaticText* lastname = new wxStaticText(registerPanel, wxID_ANY, "Last Name :", wxPoint(400, 50), wxSize(75, -1));
	FontChanger(lastname, 12);
	lastnamectrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(500, 45), wxSize(200, -1));

	string  provinceName[] = { "Provience 1" ,"Provience 2","Bagmati","Gandaki","Lumbini","Karnali","Sudur Paschim" };
	wxArrayString ProvinceName;
	for (int i = 0; i < 7; i++) {
		ProvinceName.Add(provinceName[i]);
	}

	wxStaticText* Province = new wxStaticText(registerPanel, wxID_ANY, "Province:", wxPoint(15, 75), wxDefaultSize);
	FontChanger(Province, 12);
 provincelist= new wxChoice(registerPanel, wxID_ANY,wxPoint(140,75),wxSize(200,-1),ProvinceName);

	wxStaticText* ctz = new wxStaticText(registerPanel, wxID_ANY, "Citizenship Number :", wxPoint(15, 120), wxSize(120, -1));
	FontChanger(ctz, 12);
	ctzctrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(160, 115), wxSize(200, -1));

	wxStaticText* username = new wxStaticText(registerPanel, wxID_ANY, "UserName :", wxPoint(15, 150), wxSize(80, -1));
	FontChanger(username, 12);
	usernamectrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140,145), wxSize(200, -1));

	wxStaticText* password = new wxStaticText(registerPanel, wxID_ANY, "PassWord :", wxPoint(15, 180), wxSize(80, -1));
	FontChanger(password, 12);
	passwordctrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140, 175), wxSize(200, -1), wxTE_PASSWORD);
	
	wxStaticText* confirmpassword = new wxStaticText(registerPanel, wxID_ANY, "Confirm PassWord:", wxPoint(15, 220));
	FontChanger(confirmpassword, 12);
	confirmpasswordctrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(170, 215),wxSize(200,-1),wxTE_PASSWORD);

	wxButton* signup = new wxButton(registerPanel, wxID_ANY, "Sign Up", wxPoint(80, 250), wxSize(140, -1));
	signup->Bind(wxEVT_BUTTON, &MainFrame::OnSignUp,this);

	//Element of login is added;
	wxStaticText* loginText = new wxStaticText(loginPanel, wxID_ANY, wxT("Login to Digital Voting System"), wxPoint(50, 5));
	wxFont font2 = loginText->GetFont();
	font2.SetPointSize(12);
	font2.SetWeight(wxFONTWEIGHT_BOLD);
	loginText->SetFont(font2);
	wxStaticText* username2 = new wxStaticText(loginPanel, wxID_ANY, "UserName :", wxPoint(15,40), wxSize(100, -1));
	FontChanger(username2, 12);
	loginusername = new wxTextCtrl(loginPanel, wxID_ANY, "", wxPoint(140, 35), wxSize(200, -1));
	wxStaticText* password2 = new wxStaticText(loginPanel, wxID_ANY, "Password :", wxPoint(15, 70), wxSize(80, -1));
	FontChanger(password2, 12);
	loginpassword = new wxTextCtrl(loginPanel, wxID_ANY, "", wxPoint(140, 65), wxSize(200, -1),wxTE_PASSWORD);
	wxButton* login = new wxButton(loginPanel, wxID_ANY, "Login", wxPoint(80, 150), wxSize(140, -1));
	login->Bind(wxEVT_BUTTON, &MainFrame::OnLogIn, this);

	//Panels were added to the sizer
	sizer->Add(HeaderPanel, 1, wxEXPAND |wxTOP |wxRIGHT |wxLEFT, 10);
	sizer->Add(registerPanel, 3, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 10);
	sizer->Add(loginPanel, 2, wxEXPAND | wxALL, 10);
	this->SetSizerAndFit(sizer);

}
