#include "ExplorerForm.h"

void WinExplorer::ExplorerForm::DriveTreeInit()
{
	// Получаем инфомрацию по дискам системы
	array<DriveInfo^>^ drives = DriveInfo::GetDrives();
	// Создаем новый словарь для хранения путей к каталогам
	pathDic = gcnew Dictionary<TreeNode^, String^>();

	directoriesTreeView->BeginUpdate();

	directoriesTreeView->Nodes->Clear();

	// Для каждого диска
	for (int i = 0; i < drives->Length; i++)
	{
		TreeNode^ drive = gcnew TreeNode(drives[i]->Name);
		pathDic->Add(drive, drives[i]->RootDirectory->FullName);
		drive->Nodes->Add("");
		directoriesTreeView->Nodes->Add(drive);
		GetLocaleDirectories(drive);
	}

	// Смена иконок дисков: C и D. А также флеш-карт
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
	// Получаем объект с инфомрацией о каталоге соответствующему указанному при вызове узлу
	DirectoryInfo^ directory = gcnew DirectoryInfo(parentNode->FullPath);

	array<DirectoryInfo^>^ directories;

	parentNode->Nodes->Clear();

	// Если каталога не существует, то выход
	if (!directory->Exists)
		return;

	try
	{
		// Получаем информацию о подкаталогах
		directories = directory->GetDirectories();
	}
	catch (...)
	{
		return;
	}

	for each (DirectoryInfo ^ dirinfo in directories)
	{
		// Добавляем новый узел	
		TreeNode^ node = gcnew TreeNode(dirinfo->Name, 1, 2);
		node->Nodes->Add("");
		node->Name = node->Text;
		String^ dirName = dirinfo->FullName;
		// Если полный путь не содержит последним символом слэш ("\"), то добавляем этот символ
		if (dirName[dirName->Length - 1] != '\\')
			dirName += "\\";
		// Добавляем новый путь в словарь, по указателю узлового элемента
		pathDic->Add(node, dirName);
		parentNode->Nodes->Add(node);
	}
}