#pragma once
#include <wx/wx.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

inline void FontChanger(wxStaticText* Name, int a, wxFontFamily b = wxFONTFAMILY_DEFAULT, wxFontWeight c = wxFONTWEIGHT_NORMAL,bool d= false) {
	wxFont font = Name->GetFont();
	font.SetPointSize(a);
	font.Bold();
	font.SetFamily(b);
	font.SetWeight(c);
	font.SetUnderlined(d);
	Name->SetFont(font);
}
class MainFrame:public wxFrame{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& Size);
	
private:
	//Pointer variables of Control Elemet of UI
	wxTextCtrl* firstnamectrl;
	wxTextCtrl* lastnamectrl;
	wxChoice* provincelist;
	wxTextCtrl* ctzctrl;
	wxTextCtrl* usernamectrl;
	wxTextCtrl* passwordctrl;
	wxTextCtrl* loginusername;
	wxTextCtrl* loginpassword;
	wxTextCtrl* confirmpasswordctrl;
	//String to hold Log in userData
	
private:
	//Event handler 
	void OnLogIn(wxCommandEvent & );
	void OnSignUp(wxCommandEvent &);


};


class VoterData {
private:

	string username;
	string password;
public:
	VoterData(string* s) :username(s[3]), password(s[4]) {}
	string GetUserName() {
		return username;
	}
	string GetPassWord() {
		return password;
	}
	void write_data() {
		ofstream Writing("Data.dat", ios::binary | ios::app);
		Writing << ',' << username << ',' << password << ',' << endl;
		Writing.close();
	}


};




