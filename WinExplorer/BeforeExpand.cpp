#include "ExplorerForm.h"

///<sender>
/// ќбработчик событи€ разворачивани€ элементов узла (клик мышкой на значок +)
///</sender>
System::Void WinExplorer::ExplorerForm::directoriesTreeView_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e)
{	// ≈сли только 1 дочерний узел и у него пустое им€, то значит структура каталогов еще не была загружена
	// и вызываетс€ метод добавлени€ узлов дерева, соответствующих подкаталогам
	if (e->Node->Nodes->Count == 1 && e->Node->Nodes[0]->Text == "")
	{
		e->Node->Nodes->Clear();
		GetLocaleDirectories(e->Node);
	}
}