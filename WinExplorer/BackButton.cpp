#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	TreeNode^ dir;
	array<TreeNode^>^ backPath = gcnew array<TreeNode^>(backPathList->Count);
	backPath = backPathList->ToArray();

	for (int i = 0; i < backPath->Length - 1; i++)
	{
		dir = backPath[i];

	}

	directoriesTreeView->SelectedNode = dir;
}