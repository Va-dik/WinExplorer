#include "ExplorerForm.h"

void WinExplorer::ExplorerForm::DriveTreeInit()
{
	// �������� ���������� �� ������ �������
	array<DriveInfo^>^ drives = DriveInfo::GetDrives();
	// ������� ����� ������� ��� �������� ����� � ���������
	pathDic = gcnew Dictionary<TreeNode^, String^>();

	directoriesTreeView->BeginUpdate();

	directoriesTreeView->Nodes->Clear();

	// ��� ������� �����
	for (int i = 0; i < drives->Length; i++)
	{
		TreeNode^ drive = gcnew TreeNode(drives[i]->Name);
		pathDic->Add(drive, drives[i]->RootDirectory->FullName);
		drive->Nodes->Add("");
		directoriesTreeView->Nodes->Add(drive);
		GetLocaleDirectories(drive);
	}

	// ����� ������ ������: C � D. � ����� ����-����
	for (int i = 0; i < drives->Length; i++)
	{
		directoriesTreeView->Nodes[i]->ImageIndex = 0;
		directoriesTreeView->Nodes[i]->SelectedImageIndex = 0;

		if (drives[i]->DriveType == DriveType::Removable)
		{
			directoriesTreeView->Nodes[i]->ImageIndex = 3;
			directoriesTreeView->Nodes[i]->SelectedImageIndex = 3;
		}
	}

	directoriesTreeView->EndUpdate();
}

void WinExplorer::ExplorerForm::GetLocaleDirectories(TreeNode^ parentNode)
{
	// �������� ������ � ����������� � �������� ���������������� ���������� ��� ������ ����
	DirectoryInfo^ directory = gcnew DirectoryInfo(parentNode->FullPath);

	array<DirectoryInfo^>^ directories;

	parentNode->Nodes->Clear();

	// ���� �������� �� ����������, �� �����
	if (!directory->Exists)
		return;

	try
	{
		// �������� ���������� � ������������
		directories = directory->GetDirectories();
	}
	catch (...)
	{
		return;
	}

	for each (DirectoryInfo ^ dirinfo in directories)
	{
		// ��������� ����� ����	
		TreeNode^ node = gcnew TreeNode(dirinfo->Name, 1, 2);
		node->Nodes->Add("");
		node->Name = node->Text;
		String^ dirName = dirinfo->FullName;
		// ���� ������ ���� �� �������� ��������� �������� ���� ("\"), �� ��������� ���� ������
		if (dirName[dirName->Length - 1] != '\\')
			dirName += "\\";
		// ��������� ����� ���� � �������, �� ��������� �������� ��������
		pathDic->Add(node, dirName);
		parentNode->Nodes->Add(node);
	}
}