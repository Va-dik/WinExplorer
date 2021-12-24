#include "ExplorerForm.h"
#include "AboutProgramForm.h"
#include <Windows.h>

using namespace System::IO;
using namespace System::Collections::Generic;
using namespace WinExplorer; // Название проекта

[STAThreadAttribute]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ExplorerForm);
	return 0;
}


unsigned long long WinExplorer::ExplorerForm::DirSize(DirectoryInfo^ directory)
{
	unsigned long long Size = 0;
	// Добавление размерова файлов
	array<FileInfo^>^ filesSizes = directory->GetFiles();
	for (int i = 0; i < filesSizes->Length; i++)
	{
		Size += filesSizes[i]->Length;
	}
	// Добавление размеров подкаталогов
	array<DirectoryInfo^>^ directoriesSizes = directory->GetDirectories();
	for (int i = 0; i < directoriesSizes->Length; i++)
	{
		Size += DirSize(directoriesSizes[i]);
	}

	return(Size);
}

System::Void WinExplorer::ExplorerForm::AboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AboutProgramForm^ aboutProgram = gcnew AboutProgramForm();
	aboutProgram->Show();
}

System::Void WinExplorer::ExplorerForm::CloseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void WinExplorer::ExplorerForm::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		// Очищаем список каталогов и фалов
		ContentListView->Items->Clear();
		// Вызываем метод обработки выделения элемента дерева, для нового формирования списка каталогов и файлов
		directoriesTreeView_AfterSelect(sender, gcnew TreeViewEventArgs(directoriesTreeView->SelectedNode, TreeViewAction::ByMouse));
	}
	catch (...) {}
}

/// <sender>
/// Обработчик события загрузки формы
/// </sender>
System::Void WinExplorer::ExplorerForm::ExplorerForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Создаем список для иконок элементов
	this->ContentListView->SmallImageList = gcnew ImageList();
	this->ContentListView->LargeImageList = gcnew ImageList();

	ImageList^ iconList = gcnew ImageList();

	// Устанавливаем размер иконок
	iconList->ImageSize = System::Drawing::Size(20, 20);

	// Заполняем список иконок директорий и дисков

	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\disk.png"));
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\0_closed_Folder.png"));
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\1_opened_Folder.png"));
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\usb_Icon.png"));
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\cd_icon.png"));
	//Инициализируем 
	DriveTreeInit();

	directoriesTreeView->ImageList = iconList;

	// Загружаем иконки для файлов и каталогов

	this->ContentListView->SmallImageList->ImageSize = Drawing::Size(20, 20);
	this->ContentListView->LargeImageList->ImageSize = Drawing::Size(40, 40);
}