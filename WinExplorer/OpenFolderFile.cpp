#include "ExplorerForm.h"

///<sender>
/// Обработчик события двойного нажатия кнопки мышки на элемент из списка каталогов и файлов
///</sender>
System::Void WinExplorer::ExplorerForm::ContentListView_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		pathTextBox->Text = filePath;

		try
		{
			//Если выделен каталог
			if ((gcnew DirectoryInfo(filePath))->Exists)
			{
				// Выделяем сответствующий ему узел в дереве каталогов
				String^ selName = ContentListView->SelectedItems[0]->Text;
				array<String^, 1>^ strs = gcnew array<String^, 1>(directoriesTreeView->SelectedNode->Nodes->Count);
				for (int i = 0; i < directoriesTreeView->SelectedNode->Nodes->Count; i++)
				{
					strs[i] = directoriesTreeView->SelectedNode->Nodes[i]->Name;
				}
				directoriesTreeView->SelectedNode = directoriesTreeView->SelectedNode->Nodes[selName];
				return;
			}
		}
		catch (...) {}
		// Если это был файл, то запускаем его через программу по умолчанию
		System::Diagnostics::Process::Start(filePath);
	}
	catch (...) {}
}

System::Void WinExplorer::ExplorerForm::OpenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ContentListView_DoubleClick(sender, e);
}