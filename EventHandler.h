#pragma once
/*

class VoterData {
private:
	string firstname;
	string lastname;
	string ctznumber;
	string username;
	string password;

public:
	friend void MainFrame::OnSignUp(wxCommandEvent& evt);
	friend void MainFrame::OnLogIn(wxCommandEvent& evt);
};
//Event handler

void MainFrame::OnSignUp(wxCommandEvent& evt) {
	wxLogStatus("Sign Up Clicked");
	VoterData *Buffer;
	Buffer = new VoterData;
	Buffer->firstname =firstnamectrl->GetValue().ToStdString();
	Buffer->lastname= lastnamectrl->GetValue().ToStdString();
	Buffer->ctznumber = ctzCtrl->GetValue().ToStdString();
	Buffer->username = usernamectrl->GetValue().ToStdString();
	Buffer->password = passwordctrl->GetValue().ToStdString();

	//Writing Data on File
	fstream WritingVoterData("Data",ios::binary|ios::app);
	WritingVoterData.write(reinterpret_cast<char *>(Buffer), sizeof(Buffer));
	delete Buffer;
	WritingVoterData.close();
}

void MainFrame::OnLogIn(wxCommandEvent& e) {
	wxLogStatus("Log In CLicked");
	VoterData* Buffer;
	Buffer = new VoterData;
	ifstream ReadingData("Data");
	ReadingData.read(reinterpret_cast<char*>(Buffer),sizeof(Buffer));
	ReadingData.close();
	string username_check = loginusername->GetValue
	().ToStdString();
	string password_check = loginpassword->GetValue().ToStdString();
	if (Buffer->username == username_check && Buffer->password == password_check) {
		wxMessageBox("You are logged in sucessfully");
	}
}

*/