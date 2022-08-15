#include<wx/wx.h>
#include "VotingArea.h"
int countVote(string s) {

}
void VotingArea::OnConfirm(wxCommandEvent& evt) {
	wxLogStatus("Confirmed");
	string presidentname = presidentList->GetStringSelection().ToStdString();
	string vicepresidentname = vicepresidentList->GetStringSelection().ToStdString();
	string secrataryname = secrataryList->GetStringSelection().ToStdString();
	string joint_secrataryname = joint_secrataryList->GetStringSelection().ToStdString();
	string treasurarname = treasurarList->GetStringSelection().ToStdString();
	string membername = memberList->GetStringSelection().ToStdString();

	Vote(presidentname, "presidentVote");
	Vote(vicepresidentname, "vicePresidnetVote");
	Vote(secrataryname, "secrataryVote");
	Vote(joint_secrataryname, "jointSecrataryVote");
	Vote(treasurarname, "treasurarVote");
	Vote(membername, "memberVote");

	wxMessageDialog ti(NULL, presidentname);
	ti.ShowModal();

}

void VotingArea::OnResult(wxCommandEvent& evt) {
	int presidentCount, vicePresidentCount, secrataryCount, jointSecrataryCount, treasurarCount, memberCount;


}