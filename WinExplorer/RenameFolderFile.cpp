#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::RenameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ContentListView->SelectedItems->Count != 0)
	{
		ContentListView->SelectedItems[0]->BeginEdit();
	}
	else
	{
		MessageBox::Show("�� ������(-�) ���� ��� �����", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void WinExplorer::ExplorerForm::ContentListView_AfterLabelEdit(System::Object^ sender, System::Windows::Forms::LabelEditEventArgs^ e)
{
	if (e->Label != nullptr)
	{
		if (e->Label->Length > 0)
		{
			array <Char>^ temp = { '/','*','?','|', '\\', '<', '>','"' };
			if (e->Label->IndexOfAny(temp) == -1)
			{
				try
				{
					Directory::Move(directoriesTreeView->SelectedNode->FullPath + "\\" + ContentListView->SelectedItems[0]->Text, directoriesTreeView->SelectedNode->FullPath + "\\" + e->Label->ToString());
					GetLocaleDirectories(delnode);
				}
				catch (...)
				{
					MessageBox::Show("��������� ������������ ����� �����", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else
			{
				e->CancelEdit = true;
				MessageBox::Show("��� �����(�����) �� ������ ��������� ��������� ������: \/:*?<>|", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			e->CancelEdit = true;
			MessageBox::Show("��� �����(�����) �� ����� ���� ������.", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	buttonUpdate_Click(sender, e);
}