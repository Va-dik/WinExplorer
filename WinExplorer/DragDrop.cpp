#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::ContentListView_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	e->Effect = DragDropEffects::Copy;
}

System::Void WinExplorer::ExplorerForm::ContentListView_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	array<String^>^ paths = (array<String^>^)(e->Data->GetData(DataFormats::FileDrop, false));

	for (int i = 0; i < paths->Length; i++)
	{
		if (Directory::Exists(paths[i]))
		{
			MoveDirectory(paths[i], directoriesTreeView->SelectedNode->FullPath + "\\" + Path::GetFileName(paths[i]), false);
		}

		if (File::Exists(paths[i]))
		{
			File::Move(paths[i], directoriesTreeView->SelectedNode->FullPath + "\\" + Path::GetFileName(paths[i]));
		}

		GetLocaleDirectories(directoriesTreeView->SelectedNode);
	}

	buttonUpdate_Click(sender, e);
}

System::Void WinExplorer::ExplorerForm::ContentListView_ItemDrag(System::Object^ sender, System::Windows::Forms::ItemDragEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left && Control::ModifierKeys == Keys::Shift || e->Button == System::Windows::Forms::MouseButtons::Right)
	{
		array<String^>^ filesToDrag = { filePath };

		DoDragDrop(gcnew DataObject(DataFormats::FileDrop, filesToDrag), DragDropEffects::Move);
	}

	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		array<String^>^ filesToDrag = { filePath };

		DoDragDrop(gcnew DataObject(DataFormats::FileDrop, filesToDrag), DragDropEffects::Copy);
	}

	buttonUpdate_Click(sender, e);
}