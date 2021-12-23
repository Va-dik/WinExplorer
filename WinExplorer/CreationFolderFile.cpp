#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::CreateFolderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Счётчик
	int i = 1;
	//Запоминаем полный путь для создания папки в стринговую переменную
	String^ directoryFolder = directoriesTreeView->SelectedNode->FullPath;
	String^ dirFoldName = "Новая папка";

	DirectoryInfo^ dir = gcnew DirectoryInfo(directoriesTreeView->SelectedNode->FullPath);
	array<DirectoryInfo^>^ dirs = dir->GetDirectories();

	System::Text::StringBuilder^ strBuilder = gcnew System::Text::StringBuilder(dirFoldName);

	for each (DirectoryInfo ^ folderName in dirs)
	{
		if (dirFoldName == folderName->Name)
		{
			strBuilder->Append(i.ToString());
			dirFoldName = strBuilder->ToString();
			i++;
		}
	}

	//Если каталог не существует, то создаём новый каталог
	if (!Directory::Exists(directoryFolder + "\\" + dirFoldName))
	{
		Directory::CreateDirectory(directoryFolder + "\\" + dirFoldName);
		ContentListView->Items->Add(dirFoldName);
		i = ContentListView->Items->Count - 1;
		ContentListView->Items[i]->Selected = true;
		ContentListView->Items[i]->ImageIndex = 0;
		ContentListView->SelectedItems[0]->BeginEdit();
	}
}

System::Void WinExplorer::ExplorerForm::CreateTextFIleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Счётчик
	int i = 1;
	//Запоминания полного пути для создания папки в стринговую переменную
	String^ DirectoryFile = directoriesTreeView->SelectedNode->FullPath;
	String^ DirFileName = "Новый текстовый документ";

	DirectoryInfo^ file = gcnew DirectoryInfo(directoriesTreeView->SelectedNode->FullPath);
	array<FileInfo^>^ files = file->GetFiles();

	System::Text::StringBuilder^ strBuilder = gcnew System::Text::StringBuilder(DirFileName);

	for each (FileInfo ^ FileName in files)
	{
		if (DirFileName + ".txt" == FileName->Name)
		{
			strBuilder->Append(i.ToString());
			DirFileName = strBuilder->ToString();
			i++;
		}
	}

	//Если каталог не существует, то создаём новый каталог
	if (!File::Exists(DirectoryFile + "\\" + DirFileName + ".txt"))
	{
		File::Create(DirectoryFile + "\\" + DirFileName + ".txt");
		ContentListView->Items->Add(DirFileName + ".txt");
		GetLocaleDirectories(delnode);
		i = ContentListView->Items->Count - 1;
		ContentListView->Items[i]->Selected = true;
		ContentListView->Items[i]->ImageIndex = 4;
		ContentListView->SelectedItems[0]->BeginEdit();
	}
}