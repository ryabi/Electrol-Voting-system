
#include <wx/wx.h>
#include <iostream>
#include <fstream>
#include"MainFrame.h"

class Candidate
{
protected:
	string name;
public:
	Candidate(string n):name(n){}
};
class persident: public Candidate {
private:
	int vote;
public:
	persident(string n):Candidate(n){}
	int voteCount() {
		string onVote;
		ifstream votefile("presidentVote", ios::binary);
		while (!votefile.eof()) {
			getline(votefile, onVote, ',');
			if (name == onVote) {
				vote++;
			}
		}
		return vote;
	}
};
/*
void Counting(string s,string s2) {
	int number;
	ifstream open(s, ios::binary);
	string buffer;
		while (! open.eof()) {
			getline(open, buffer, ',');
			persident p1(buffer);
			p1.votecouhnt

	}

}*/

