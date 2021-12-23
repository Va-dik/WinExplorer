#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::changeViewButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ContentListView->View == View::Details)
		ContentListView->View = View::LargeIcon;

	else
		ContentListView->View = View::Details;
}