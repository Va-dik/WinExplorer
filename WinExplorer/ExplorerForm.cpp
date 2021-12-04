#include "ExplorerForm.h"
#include "PropertyForm.h"

#include <Windows.h>

using namespace System::IO;
using namespace System::Collections::Generic;
using namespace WinExplorer; // �������� �������

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
		// ������� ������ ��������� � �����
		ContentListView->Items->Clear();
		// �������� ����� ��������� ��������� �������� ������, ��� ������ ������������ ������ ��������� � ������
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
/// ���������� ������� �������� �����
/// </sender>
System::Void WinExplorer::ExplorerForm::ExplorerForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	// ������� ������ ��� ������ � ������ ������
	this->ContentListView->LargeImageList = gcnew ImageList();
	// ������� ����� ������� ��� �������� ����� � ���������
	pathDic = gcnew Dictionary<TreeNode^, String^>();
	// �������� ���������� �� ������ �������
	array<DriveInfo^, 1>^ drives = DriveInfo::GetDrives();

	// ��� ������� �����
	for (int i = 0; i < drives->Length; i++)
	{
		// ��������� �������� ���� � ������ ���������
		TreeNode^ node = gcnew TreeNode(drives[i]->Name);
		pathDic->Add(node, drives[i]->RootDirectory->FullName);
		node->Nodes->Add("");
		directoriesTreeView->Nodes->Add(node);
	}

	ImageList^ iconList = gcnew ImageList();

	// ������������� ������ ������
	iconList->ImageSize = System::Drawing::Size(20, 20);

	// ��������� ������ ������ ���������� � ������
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\folder.png"));
	iconList->Images->Add(Bitmap::FromFile(Application::StartupPath + "\\Icons\\disk.png"));

	// ����� ������ ������: C � D. � ����� ����-����
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

	// ��������� ������ ��� ������ � ���������
	this->ContentListView->LargeImageList->ImageSize = System::Drawing::Size(40, 40);
	ContentListView->LargeImageList->Images->Add("folder", Bitmap::FromFile(Application::StartupPath + "\\Icons\\folder.png"));
	ContentListView->LargeImageList->Images->Add("file", Bitmap::FromFile(Application::StartupPath + "\\Icons\\file.png"));
	ContentListView->LargeImageList->Images->Add("textFile", Bitmap::FromFile(Application::StartupPath + "\\Icons\\text_File.png"));
}

///<sender>
/// ���������� ������� �������������� ��������� ���� (���� ������ �� ������ +)
///</sender>
System::Void WinExplorer::ExplorerForm::directoriesTreeView_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e)
{	// ���� ������ 1 �������� ���� � � ���� ������ ���, �� ������ ��������� ��������� ��� �� ���� ���������
	// � ���������� ����� ���������� ����� ������, ��������������� ������������
	if (e->Node->Nodes->Count == 1 && e->Node->Nodes[0]->Text == "")
	{
		e->Node->Nodes->Clear();
		AddDirs(e->Node);
	}
}

///<sender>
/// ���������� ������� ��������� �������� ������. ��������� ������������ ������ ��������� � ������
///</sender>
System::Void WinExplorer::ExplorerForm::directoriesTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
	pathTextBox->Text = e->Node->FullPath;
	try
	{
		DirectoryInfo^ di = gcnew DirectoryInfo(pathDic[e->Node]);
		// ������������� �������� �������� ����
		e->Node->Expand();
		// ������� ������ ������
		ContentListView->Items->Clear();
		// �������� ������ ���������
		array<DirectoryInfo^, 1>^ dirs = di->GetDirectories();

		for (int i = 0; i < dirs->Length; i++)
		{
			// ��������� � ������ ��������� � ������ ������� � ������� �������� � ������� ������ �����
			ContentListView->Items->Add(dirs[i]->Name, "folder");
		}
		// �������� ������ ������ � ��������
		array<FileInfo^, 1>^ files = di->GetFiles("*.*");

		// � ��������� �� � ������ � ������� �����
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
		MessageBox::Show("�������� ���� � ��������", "�������� ����");
	}
}

///<sender>
/// ���������� ������� �������� ������� ������ ����� �� ������� �� ������ ��������� � ������
///</sender>
System::Void WinExplorer::ExplorerForm::ContentListView_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		// �������� ��� �������� ��� ����� ����� �������, � ������� ��������� ���� ���������� ���� � ���������� ��������
		String^ fileName = pathDic[directoriesTreeView->SelectedNode] + ContentListView->SelectedItems[0]->Text;
		pathTextBox->Text = fileName;

		try
		{
			//���� ������� �������
			if ((gcnew DirectoryInfo(fileName))->Exists)
			{
				// �������� �������������� ��� ���� � ������ ���������
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
		// ���� ��� ��� ����, �� ��������� ��� ����� ��������� �� ���������
		System::Diagnostics::Process::Start(fileName);
	}
	catch (...) {}
}

///<sender>
/// �����, ����������� ���� ��������� � ���������� � �������� �������� ���������
///</sender>
void WinExplorer::ExplorerForm::AddDirs(TreeNode^ parentNode)
{
	DirectoryInfo^ di = gcnew DirectoryInfo(pathDic[parentNode]);
	// ���� �������� �� ����������, �� �����
	if (!di->Exists)
		return;
	// �������� ���������� � ������������
	array<DirectoryInfo^, 1>^ SubDirs = di->GetDirectories();
	// ��� ������� �����������
	for (int i = 0; i < SubDirs->Length; i++)
	{
		// ��������� ����� ����
		TreeNode^ node = gcnew TreeNode(SubDirs[i]->Name);
		node->Nodes->Add("");
		node->Name = node->Text;
		String^ dirName = SubDirs[i]->FullName;
		// ���� ������ ���� �� �������� ��������� �������� ���� ("/"), �� ��������� ���� ������
		if (dirName[dirName->Length - 1] != '\\')
			dirName += "\\";
		// ��������� ����� ���� � �������, �� ��������� �������� ��������
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
			// �������� ����� �� ����� 
			paths->AddRange(Directory::GetFiles(path));
		}
		else
		{
			// �������� ���� � 
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

System::Void WinExplorer::ExplorerForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ContentListView_DoubleClick(sender, e);
}

System::Void WinExplorer::ExplorerForm::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	PropertyForm^ propertyBox = gcnew PropertyForm();
	propertyBox->Show();
}

System::Void WinExplorer::ExplorerForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	CopyFiles();
}
