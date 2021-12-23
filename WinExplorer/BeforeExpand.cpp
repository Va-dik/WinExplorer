#include "ExplorerForm.h"

///<sender>
/// ���������� ������� �������������� ��������� ���� (���� ������ �� ������ +)
///</sender>
System::Void WinExplorer::ExplorerForm::directoriesTreeView_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e)
{	// ���� ������ 1 �������� ���� � � ���� ������ ���, �� ������ ��������� ��������� ��� �� ���� ���������
	// � ���������� ����� ���������� ����� ������, ��������������� ������������
	if (e->Node->Nodes->Count == 1 && e->Node->Nodes[0]->Text == "")
	{
		e->Node->Nodes->Clear();
		GetLocaleDirectories(e->Node);
	}
}