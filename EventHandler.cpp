#include"MainFrame.h"
#include"VotingArea.h"
//Function for event handling of LogIn and registration frame

void MainFrame::OnSignUp(wxCommandEvent& evt) {
	wxLogStatus("Sign Up Clicked");
	string *Buffer;
	Buffer = new string[5];
	Buffer[0] = firstnamectrl->GetValue().ToStdString();
	Buffer[1] = lastnamectrl->GetValue().ToStdString();
	Buffer[2] = ctzctrl->GetValue().ToStdString();
	Buffer[3] = usernamectrl->GetValue().ToStdString();
	Buffer[4] = passwordctrl->GetValue().ToStdString();
	
	if (!Buffer[4].compare(confirmpasswordctrl->GetValue().ToStdString())) {
		VoterData voterID(Buffer);
		wxMessageDialog* confirm = new wxMessageDialog(NULL, "Are you sure provided data are right ?", "Signing Up", wxYES_DEFAULT | wxYES_NO | wxICON_QUESTION);
		confirm->ShowModal();
		//Writing Data on File
		firstnamectrl->Clear();
		lastnamectrl->Clear();
		
		ctzctrl->Clear();
		usernamectrl->Clear();
		passwordctrl->Clear();
		confirmpasswordctrl->Clear();
		voterID.write_data();
		delete[]Buffer;
	}
	else //if(Buffer[4].compare(confirmpasswordctrl->GetValue().ToStdString())!=0) 
	{
		wxMessageDialog* retry = new wxMessageDialog(NULL, "Recheck password and Confirm password");
		retry->ShowModal();
		passwordctrl->Clear();
		confirmpasswordctrl->Clear();
	}
}

void MainFrame::OnLogIn(wxCommandEvent& e) {
	bool flag =1;
	string Buffer[2];
	Buffer[0] = loginusername->GetValue().ToStdString();
	Buffer[1] = loginpassword->GetValue().ToStdString();
	//wxMessageDialog show1(NULL, Buffer[1]);
	//show1.ShowModal();

	ifstream ReadingVoterData("Data.dat",ios::binary |ios::in);
	if (!ReadingVoterData) {
		wxMessageDialog error(NULL,"File can't be Opened");
		error.ShowModal();
	}
	ReadingVoterData.seekg(0, ios::beg);
	//ReadingVoterData.seekg(0, ios::end);
	
	while (!ReadingVoterData.eof()) {
		
		int counter = 0;
		string word;
		string* s1;
		s1 = new string[3];
		for (counter; counter < 3; counter++) {
			getline(ReadingVoterData,word,',');
			s1[counter] = word;


			//wxMessageDialog show(NULL, s1[counter]);
			//show.ShowModal();
		}
		
		if (!Buffer[0].compare(s1[1]) && !Buffer[1].compare(s1[2])) {
			flag = 0;
			wxMessageDialog login(NULL,"Log In Sucesssfull");
			login.ShowModal();
			loginusername->Clear();
			loginpassword->Clear();
			VotingArea* voting = new VotingArea("Electrol Voting System", wxDefaultPosition, wxSize(800, 800),Buffer[0],*this);
			voting->Show();
			break;	
		}
		delete []s1;
	}
	if (flag) {
		wxMessageDialog wrong(NULL, "Username or Password is Wrong. \n Please,Check it again!!!! ");
		wrong.ShowModal();
	}	
}