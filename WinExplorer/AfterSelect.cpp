#include "ExplorerForm.h"

///<sender>
/// Обработчик события выделения элемента дерева. Выполняет перестроение списка каталогов и файлов
///</sender>

System::Void WinExplorer::ExplorerForm::directoriesTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
	delnode = e->Node;

	DirectoryInfo^ selectDirectory = gcnew DirectoryInfo(pathDic[e->Node]);

	e->Node->Expand();

	array<DirectoryInfo^>^ directories = selectDirectory->GetDirectories();
	array<FileInfo^>^ files = selectDirectory->GetFiles();

	ContentListView->Items->Clear();

	for (int i = 0; i < directories->Length; i++)
	{
		ListViewItem^ listViewItem = gcnew ListViewItem(directories[i]->Name);

		listViewItem->SubItems->Add("");
		listViewItem->SubItems->Add(directories[i]->LastWriteTime.ToString());
		listViewItem->ImageIndex = 0;

		ContentListView->Items->Add(listViewItem);
	}

	for (int i = 0; i < files->Length; i++)
	{
		ListViewItem^ listViewItem = gcnew ListViewItem(files[i]->Name);

		if (files[i]->Length < 1024)
		{
			listViewItem->SubItems->Add(files[i]->Length + " Байт");
		}

		if (files[i]->Length >= 1024 && files[i]->Length < 1048576)
		{
			listViewItem->SubItems->Add(files[i]->Length / 1024 + " Кб");
		}

		if (files[i]->Length >= 1048576 && files[i]->Length < 1073741824)
		{
			listViewItem->SubItems->Add(Math::Round(files[i]->Length / 1048576) + " Мб");
		}

		listViewItem->SubItems->Add(files[i]->LastWriteTime.ToString());

		String^ fileNameExtension = Path::GetExtension(files[i]->Name)->ToLower();

		if (fileNameExtension == ".exe")
		{
			listViewItem->ImageIndex = 5;
		}

		else if (fileNameExtension == ".txt")
		{
			listViewItem->ImageIndex = 4;
		}

		else if (fileNameExtension == ".doc" || fileNameExtension == ".docx")
		{
			listViewItem->ImageIndex = 7;
		}

		else if (fileNameExtension == ".png" || fileNameExtension == ".jpg")
		{
			listViewItem->ImageIndex = 6;
		}

		else
		{
			listViewItem->ImageIndex = 3;
		}

		ContentListView->Items->Add(listViewItem);
	}

	DirectoryInfo^ selectDirectorys = gcnew DirectoryInfo(Application::StartupPath + "\\Icons");
	array<FileInfo^>^ icons = selectDirectorys->GetFiles();

	for (int i = 0; i < icons->Length; i++)
	{
		ContentListView->SmallImageList->Images->Add(Image::FromFile(icons[i]->FullName));
		ContentListView->LargeImageList->Images->Add(Image::FromFile(icons[i]->FullName));
	}

	backPathList->Add(directoriesTreeView->SelectedNode);

	ContentListView->AutoResizeColumns(ColumnHeaderAutoResizeStyle::HeaderSize);
}