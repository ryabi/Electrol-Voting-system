#pragma once
#include <wx/wx.h>
#include <string>
#include <iostream>
#include <fstream>
#include "MainFrame.h"
class VotingArea: public wxFrame
{
public:
	VotingArea(const wxString& title,const wxPoint &pos,const wxSize &size, string s, MainFrame &);

private:
	wxChoice *presidentList;
	wxChoice* vicepresidentList;
	wxChoice* secrataryList;
	wxChoice* joint_secrataryList;
	wxChoice* treasurarList;
	wxChoice* memberList;
	string username;

private:
	void OnConfirm(wxCommandEvent&);
	void OnResult(wxCommandEvent&);
public:
	inline void Vote(string , string);
	//void setCandidateList(wxArrayString &, string);
};

inline void VotingArea::Vote(string vote,string filename){
	ofstream write(filename, ios::binary | ios::app);
	write << ',' << vote;
	write.close();
}

//void VotingArea::setCandidateList(wxArrayString &s, string filename) {
//	ifstream reading(filename, ios::binary);
//	string buffer;
//	
//	if (reading.is_open()) {
//		while (!reading.eof()) {
//			getline(reading, buffer, ',');
//			s.Add(buffer);
//		}
//
//	}
//	else
//	{
//		wxMessageDialog error(NULL, "Can't load Candiate List");
//		error.ShowModal();
//	}
//}
//
