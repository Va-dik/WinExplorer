#include "ExplorerForm.h"
#include "PropertyForm.h"

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



System::Void WinExplorer::ExplorerForm::buttonEnter_Click(System::Object^ sender, System::EventArgs^ e)
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

System::Void WinExplorer::ExplorerForm::ContentListView_ItemSelectionChanged(System::Object^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^ e)
{
	for (int i = 0; i < ContentListView->SelectedItems->Count; i++)
	{
		pathTextBox->Text += ContentListView->SelectedItems[i]->Text;
	}
}

/// <sender>
/// Обработчик события загрузки формы
/// </sender>
System::Void WinExplorer::ExplorerForm::ExplorerForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Создаем список для иконок в списке файлов
	this->ContentListView->LargeImageList = gcnew ImageList();
	// Создаем новый словарь для хранения путей к каталогам
	pathDic = gcnew Dictionary<TreeNode^, String^>();
	// Получаем инфомрацию по дискам системы
	array<DriveInfo^, 1>^ drives = DriveInfo::GetDrives();

	// Для каждого диска
	for (int i = 0; i < drives->Length; i++)
	{
		// Добавляем корневые узлы в дерево каталогов
		TreeNode^ node = gcnew TreeNode(drives[i]->Name);
		pathDic->Add(node, drives[i]->RootDirectory->FullName);
		node->Nodes->Add("");
		directoriesTreeView->Nodes->Add(node);
	}

	ImageList^ iconList = gcnew ImageList();

	// Устанавливаем размер иконок
	iconList->ImageSize = System::Drawing::Size(20, 20);

	// Заполняем список иконок директорий и дисков
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\folder.png"));
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\disk.png"));

	// Смена иконок дисков: C и D. А также флеш-карт
	for (int i = 0; i < drives->Length; i++)
	{
		directoriesTreeView->Nodes[i]->ImageIndex = 1;
		directoriesTreeView->Nodes[i]->SelectedImageIndex = 1;

		if (drives[i]->DriveType == DriveType::Removable)
		{
			directoriesTreeView->Nodes[i]->ImageIndex = 0;
		}
	}

	directoriesTreeView->ImageList = iconList;

	// Загружаем иконки для файлов и каталогов
	this->ContentListView->LargeImageList->ImageSize = System::Drawing::Size(40, 40);
	ContentListView->LargeImageList->Images->Add("folder", Bitmap::FromFile(Application::StartupPath + "\\Icons\\folder.png"));
	ContentListView->LargeImageList->Images->Add("file", Bitmap::FromFile(Application::StartupPath + "\\Icons\\file.png"));
	ContentListView->LargeImageList->Images->Add("textFile", Bitmap::FromFile(Application::StartupPath + "\\Icons\\text_File.png"));
}

///<sender>
/// Обработчик события разворачивания элементов узла (клик мышкой на значек +)
///</sender>
System::Void WinExplorer::ExplorerForm::directoriesTreeView_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e)
{	// Если только 1 дочерний узел и у него пустое имя, то значит структура каталогов еще не была загружена
	// и вызывается метод добавления узлов дерева, соответствующих подкаталогам
	if (e->Node->Nodes->Count == 1 && e->Node->Nodes[0]->Text == "")
	{
		e->Node->Nodes->Clear();
		AddDirs(e->Node);
	}
}

///<sender>
/// Обработчик события выделения элемента дерева. Выполняет перестроение списка каталогов и файлов
///</sender>
System::Void WinExplorer::ExplorerForm::directoriesTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
	pathTextBox->Text = e->Node->FullPath;
	try
	{
		DirectoryInfo^ di = gcnew DirectoryInfo(pathDic[e->Node]);
		// Разворачиваем дочерние элементы узла
		e->Node->Expand();
		// Очищаем список файлов
		ContentListView->Items->Clear();
		// Получаем список каталогов
		array<DirectoryInfo^, 1>^ dirs = di->GetDirectories();

		for (int i = 0; i < dirs->Length; i++)
		{
			// Добавляем в список каталогов и файлов элемент с иконкой каталога и кратким именем папки
			ContentListView->Items->Add(dirs[i]->Name, "folder");
		}
		// Получаем список файлов в каталоге
		array<FileInfo^, 1>^ files = di->GetFiles("*.*");

		// И добавляем их в список с иконкой файла
		for (int i = 0; i < files->Length; i++)
		{
			if (files[i]->Extension != ".txt")
			{
				ContentListView->Items->Add(files[i]->Name, "file");
			}

			if (files[i]->Extension == ".txt")
			{
				ContentListView->Items->Add(files[i]->Name, "textFile");
			}
		}
	}
	catch (...)
	{
		MessageBox::Show("Вставьте диск в дисковод", "Вставьте диск");
	}
}

///<sender>
/// Обработчик события двойного нажатия кнопки мышки на элемент из списка каталогов и файлов
///</sender>
System::Void WinExplorer::ExplorerForm::ContentListView_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		// Получаем имя каталога или файла через словарь, в котором указываем путь выбранного узла и выбранного элемента
		String^ fileName = pathDic[directoriesTreeView->SelectedNode] + ContentListView->SelectedItems[0]->Text;
		pathTextBox->Text = fileName;

		try
		{
			//Если выделен каталог
			if ((gcnew DirectoryInfo(fileName))->Exists)
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
		System::Diagnostics::Process::Start(fileName);
	}
	catch (...) {}
}

///<sender>
/// Метод, добавляющий узлы каталогов к указанному в качестве входного параметра
///</sender>
void WinExplorer::ExplorerForm::AddDirs(TreeNode^ parentNode)
{
	DirectoryInfo^ di = gcnew DirectoryInfo(pathDic[parentNode]);
	// Если каталога не существует, то выход
	if (!di->Exists)
		return;
	// Получаем информацию о подкаталогах
	array<DirectoryInfo^, 1>^ SubDirs = di->GetDirectories();
	// Для каждого подкаталога
	for (int i = 0; i < SubDirs->Length; i++)
	{
		// Добавляем новый узел
		TreeNode^ node = gcnew TreeNode(SubDirs[i]->Name);
		node->Nodes->Add("");
		node->Name = node->Text;
		String^ dirName = SubDirs[i]->FullName;
		// Если полный путь не содержит последним символом слэш ("/"), то добавляем этот символ
		if (dirName[dirName->Length - 1] != '\\')
			dirName += "\\";
		// Добавляем новый путь в словарь, по указателю узлового элемента
		pathDic->Add(node, dirName);
		parentNode->Nodes->Add(node);
	}
}

void WinExplorer::ExplorerForm::CopyFiles()
{
	File::Move(pathTextBox->Text, "D:\\Games\\file.txt");
}

System::Void WinExplorer::ExplorerForm::ContentListView_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	e->Effect = DragDropEffects::Move;
}

System::Void WinExplorer::ExplorerForm::ContentListView_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	List<String^>^ paths = (List<String^>^)(e->Data->GetData(DataFormats::FileDrop));
	for each (String ^ path in paths) {

		if (Directory::Exists(path))
		{
			// Добавить файлы из папки 
			paths->AddRange(Directory::GetFiles(path));
		}
		else
		{
			// Добавить путь к 
			paths->Add(path);
		}
	}
}

System::Void WinExplorer::ExplorerForm::ContentListView_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	return System::Void();
}

System::Void WinExplorer::ExplorerForm::ContentListView_ItemDrag(System::Object^ sender, System::Windows::Forms::ItemDragEventArgs^ e)
{

}

System::Void WinExplorer::ExplorerForm::ContentListView_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	
}

System::Void WinExplorer::ExplorerForm::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ContentListView_DoubleClick(sender, e);
}

System::Void WinExplorer::ExplorerForm::свойстваToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	PropertyForm^ propertyBox = gcnew PropertyForm();
	propertyBox->Show();
}

System::Void WinExplorer::ExplorerForm::копироватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	CopyFiles();
}
