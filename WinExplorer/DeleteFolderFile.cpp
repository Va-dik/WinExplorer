#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::DeleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ContentListView->SelectedItems->Count != 0)
	{
		NameList = ContentListView->SelectedItems[0]->Text;
		Delete = true;
	}
	else
	{
		Delete = false;
	}

	if (Delete == true)
	{
		if (Directory::Exists(Path::Combine(directoriesTreeView->SelectedNode->FullPath, NameList)))
		{
			if (MessageBox::Show("Вы действительно хотите удалить папку?", "Удаление", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				try
				{
					Directory::Delete(Path::Combine(directoriesTreeView->SelectedNode->FullPath, NameList), true);
					ContentListView->Items->RemoveAt(ContentListView->SelectedIndices[0]);
					GetLocaleDirectories(delnode);
				}
				catch (...)
				{
					MessageBox::Show("Невозможно удалить данную папку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		else if (File::Exists(Path::Combine(directoriesTreeView->SelectedNode->FullPath, NameList)))
		{
			if (MessageBox::Show("Вы действительно хотите удалить файл?", "Удаление", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				try
				{
					File::Delete(Path::Combine(directoriesTreeView->SelectedNode->FullPath, NameList));
					ContentListView->Items->RemoveAt(ContentListView->SelectedIndices[0]);
					GetLocaleDirectories(delnode);
				}
				catch (...)
				{
					MessageBox::Show("Невозможно удалить данный файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}
	else
	{
		if (Directory::Exists(directoriesTreeView->SelectedNode->FullPath))
		{
			if (MessageBox::Show("Вы действительно хотите удалить папку?", "Удаление", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				try
				{
					Directory::Delete(directoriesTreeView->SelectedNode->FullPath, true);
					directoriesTreeView->Nodes->Remove(directoriesTreeView->SelectedNode);
				}
				catch (...)
				{
					MessageBox::Show("Невозможно удалить данную папку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}
}