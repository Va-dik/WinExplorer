#include "ExplorerForm.h"
#include "PropertyForm.h"

System::Void WinExplorer::ExplorerForm::PropertyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	PropertyForm^ propertyBox = gcnew PropertyForm();

	try
	{
		if (File::Exists(filePath))
		{
			FileInfo^ fileInfo = gcnew FileInfo(filePath);

			for (int i = 0; i < fileInfo->Length; i++)
			{
				propertyBox->dataFileNameLabel->Text = fileInfo->Name;
				propertyBox->dataFileLocationLabel->Text = fileInfo->FullName;
				propertyBox->dataFileSizeLabel->Text = fileInfo->Length.ToString() + " байт (" + fileInfo->Length / 1024 + " кб)";
				propertyBox->dataFileCreationLabel->Text = fileInfo->CreationTime.ToString();
				propertyBox->dataFileOpenedLabel->Text = File::GetLastAccessTime(fileInfo->ToString()).ToString();
				propertyBox->dataFileChangedLabel->Text = File::GetLastWriteTime(fileInfo->ToString()).ToString();
				propertyBox->Text = "Свойства: " + fileInfo->Name;
			}
		}

		else if (Directory::Exists(filePath))
		{
			DirectoryInfo^ directoryInfo = gcnew DirectoryInfo(filePath);

			array<DirectoryInfo^>^ dirs = directoryInfo->GetDirectories();

			for (int i = 0; i < dirs->Length; i++)
			{
				propertyBox->dataFileNameLabel->Text = dirs[i]->Name;
				propertyBox->dataFileLocationLabel->Text = dirs[i]->FullName;
				propertyBox->dataFileCreationLabel->Text = dirs[i]->CreationTime.ToString();
				propertyBox->dataFileOpenedLabel->Text = Directory::GetLastAccessTime(dirs[i]->ToString()).ToString();
				propertyBox->dataFileChangedLabel->Text = Directory::GetLastWriteTime(dirs[i]->ToString()).ToString();
				propertyBox->dataFileSizeLabel->Text = DirSize(dirs[i]).ToString() + " байт (" + DirSize(dirs[i]) / 1024 + " кб)";
				propertyBox->Text = "Свойства: " + dirs[i];

			}
		}
		propertyBox->Show();
	}
	catch (...)
	{
		MessageBox::Show("Не удалось получить свойства файла (папки).", "Ошибка");
	}
	
}