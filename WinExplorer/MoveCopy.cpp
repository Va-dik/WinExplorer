#include "ExplorerForm.h"

void WinExplorer::ExplorerForm::CopyDirectory(DirectoryInfo^ diSourceDir, DirectoryInfo^ diDestDir)
{
	if (!diDestDir->Exists) diDestDir->Create();
	array<FileInfo^>^ fiSrcFiles = diSourceDir->GetFiles();
	for each (FileInfo ^ fiSrcFile in fiSrcFiles)
	{
		fiSrcFile->CopyTo(Path::Combine(diDestDir->FullName, fiSrcFile->Name));
	}
	array<DirectoryInfo^>^ diSrcDirectories = diSourceDir->GetDirectories();
	for each (DirectoryInfo ^ diSrcDirectory in diSrcDirectories)
	{
		CopyDirectory(diSrcDirectory, gcnew DirectoryInfo(Path::Combine(diDestDir->FullName, diSrcDirectory->Name)));
	}
}

void WinExplorer::ExplorerForm::MoveDirectory(String^ strSourceDir, String^ strDestDir, bool bDelSource)
{
	if (Directory::Exists(strSourceDir))
	{
		if (Directory::GetDirectoryRoot(strSourceDir) == Directory::GetDirectoryRoot(strDestDir))
		{
			Directory::Move(strSourceDir, strDestDir);
		}
		else
		{
			try
			{
				CopyDirectory(gcnew DirectoryInfo(strSourceDir), gcnew DirectoryInfo(strDestDir));
				if (bDelSource) Directory::Delete(strSourceDir, true);
			}
			catch (...)
			{

			}
		}
	}
}

System::Void WinExplorer::ExplorerForm::CopyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	sourcePath = filePath;
}


System::Void WinExplorer::ExplorerForm::PasteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (File::Exists(sourcePath))
	{
		File::Copy(sourcePath, directoriesTreeView->SelectedNode->FullPath + "\\" + Path::GetFileName(sourcePath));
	}

	else if (Directory::Exists(sourcePath))
	{
		MoveDirectory(sourcePath, directoriesTreeView->SelectedNode->FullPath + "\\" + Path::GetFileName(sourcePath), false);
	}

	buttonUpdate_Click(sender, e);
}