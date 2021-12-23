#include "ExplorerForm.h"

System::Void WinExplorer::ExplorerForm::ContentListView_ItemSelectionChanged(System::Object^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^ e)
{
	// Получаем имя каталога или файла
	try
	{
		filePath = pathDic[directoriesTreeView->SelectedNode] + ContentListView->SelectedItems[0]->Text;
	}
	catch (...) {}
}