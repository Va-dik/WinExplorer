#pragma once

namespace WinExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class ExplorerForm : public System::Windows::Forms::Form
	{
	public:
		ExplorerForm(void)
		{
			InitializeComponent();

			Type^ type = ContentListView->GetType();
			System::Reflection::PropertyInfo^ propertyInfo = type->GetProperty("DoubleBuffered", System::Reflection::BindingFlags::NonPublic | System::Reflection::BindingFlags::Instance);
			propertyInfo->SetValue(ContentListView, true, nullptr);
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~ExplorerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;


	private: System::Windows::Forms::Button^ BackButton;


	private: System::Windows::Forms::ContextMenuStrip^ extraContextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ CopyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ PasteToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ DeleteToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ PropertyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ RenameToolStripMenuItem;


	private: System::Windows::Forms::TextBox^ pathTextBox;
	private: System::Windows::Forms::ListView^ ContentListView;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Button^ buttonUpdate;
	private: System::Windows::Forms::TreeView^ directoriesTreeView;
	private: System::Windows::Forms::SplitContainer^ splitContainer;







	private: System::Windows::Forms::ToolStripMenuItem^ CreateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ CreateFolderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ CreateTextFIleToolStripMenuItem;
	private: System::Windows::Forms::Button^ changeViewButton;
	private: System::Windows::Forms::Panel^ panel1;


	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ExplorerForm::typeid));
			this->extraContextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->OpenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CreateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CreateFolderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CreateTextFIleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CopyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DeleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RenameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PropertyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->pathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ContentListView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->directoriesTreeView = (gcnew System::Windows::Forms::TreeView());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->changeViewButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->extraContextMenuStrip->SuspendLayout();
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// extraContextMenuStrip
			// 
			this->extraContextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->OpenToolStripMenuItem,
					this->CreateToolStripMenuItem, this->CopyToolStripMenuItem, this->PasteToolStripMenuItem, this->DeleteToolStripMenuItem, this->RenameToolStripMenuItem,
					this->PropertyToolStripMenuItem
			});
			this->extraContextMenuStrip->Name = L"contextMenuStrip1";
			this->extraContextMenuStrip->Size = System::Drawing::Size(162, 158);
			// 
			// OpenToolStripMenuItem
			// 
			this->OpenToolStripMenuItem->Name = L"OpenToolStripMenuItem";
			this->OpenToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->OpenToolStripMenuItem->Text = L"Îòêğûòü";
			this->OpenToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::OpenToolStripMenuItem_Click);
			// 
			// CreateToolStripMenuItem
			// 
			this->CreateToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->CreateFolderToolStripMenuItem,
					this->CreateTextFIleToolStripMenuItem
			});
			this->CreateToolStripMenuItem->Name = L"CreateToolStripMenuItem";
			this->CreateToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->CreateToolStripMenuItem->Text = L"Ñîçäàòü";
			// 
			// CreateFolderToolStripMenuItem
			// 
			this->CreateFolderToolStripMenuItem->Name = L"CreateFolderToolStripMenuItem";
			this->CreateFolderToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->CreateFolderToolStripMenuItem->Text = L"Ïàïêó";
			this->CreateFolderToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::CreateFolderToolStripMenuItem_Click);
			// 
			// CreateTextFIleToolStripMenuItem
			// 
			this->CreateTextFIleToolStripMenuItem->Name = L"CreateTextFIleToolStripMenuItem";
			this->CreateTextFIleToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->CreateTextFIleToolStripMenuItem->Text = L"Òåêñòîâûé ôàéë";
			this->CreateTextFIleToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::CreateTextFIleToolStripMenuItem_Click);
			// 
			// CopyToolStripMenuItem
			// 
			this->CopyToolStripMenuItem->Name = L"CopyToolStripMenuItem";
			this->CopyToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->CopyToolStripMenuItem->Text = L"Êîïèğîâàòü";
			this->CopyToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::CopyToolStripMenuItem_Click);
			// 
			// PasteToolStripMenuItem
			// 
			this->PasteToolStripMenuItem->Name = L"PasteToolStripMenuItem";
			this->PasteToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->PasteToolStripMenuItem->Text = L"Âñòàâèòü";
			this->PasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::PasteToolStripMenuItem_Click);
			// 
			// DeleteToolStripMenuItem
			// 
			this->DeleteToolStripMenuItem->Name = L"DeleteToolStripMenuItem";
			this->DeleteToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->DeleteToolStripMenuItem->Text = L"Óäàëèòü";
			this->DeleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::DeleteToolStripMenuItem_Click);
			// 
			// RenameToolStripMenuItem
			// 
			this->RenameToolStripMenuItem->Name = L"RenameToolStripMenuItem";
			this->RenameToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->RenameToolStripMenuItem->Text = L"Ïåğåèìåíîâàòü";
			this->RenameToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::RenameToolStripMenuItem_Click);
			// 
			// PropertyToolStripMenuItem
			// 
			this->PropertyToolStripMenuItem->Name = L"PropertyToolStripMenuItem";
			this->PropertyToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->PropertyToolStripMenuItem->Text = L"Ñâîéñòâà";
			this->PropertyToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::PropertyToolStripMenuItem_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ôàéëToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(1125, 24);
			this->menuStrip->TabIndex = 4;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîäToolStripMenuItem,
					this->îÏğîãğàììåToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->âûõîäToolStripMenuItem->Text = L"Çàêğûòü";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::CloseToolStripMenuItem_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::AboutProgramToolStripMenuItem_Click);
			// 
			// BackButton
			// 
			this->BackButton->BackColor = System::Drawing::SystemColors::Control;
			this->BackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.BackgroundImage")));
			this->BackButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->BackButton->FlatAppearance->BorderSize = 0;
			this->BackButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BackButton->Location = System::Drawing::Point(3, 3);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(46, 25);
			this->BackButton->TabIndex = 0;
			this->BackButton->UseVisualStyleBackColor = false;
			this->BackButton->Click += gcnew System::EventHandler(this, &ExplorerForm::BackButton_Click);
			// 
			// pathTextBox
			// 
			this->pathTextBox->Location = System::Drawing::Point(226, 3);
			this->pathTextBox->Multiline = true;
			this->pathTextBox->Name = L"pathTextBox";
			this->pathTextBox->Size = System::Drawing::Size(449, 28);
			this->pathTextBox->TabIndex = 0;
			// 
			// ContentListView
			// 
			this->ContentListView->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->ContentListView->AllowDrop = true;
			this->ContentListView->BackColor = System::Drawing::SystemColors::Info;
			this->ContentListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1,
					this->columnHeader2, this->columnHeader3
			});
			this->ContentListView->ContextMenuStrip = this->extraContextMenuStrip;
			this->ContentListView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ContentListView->HideSelection = false;
			this->ContentListView->HoverSelection = true;
			this->ContentListView->LabelEdit = true;
			this->ContentListView->Location = System::Drawing::Point(0, 0);
			this->ContentListView->Name = L"ContentListView";
			this->ContentListView->Size = System::Drawing::Size(899, 653);
			this->ContentListView->TabIndex = 0;
			this->ContentListView->UseCompatibleStateImageBehavior = false;
			this->ContentListView->View = System::Windows::Forms::View::Details;
			this->ContentListView->AfterLabelEdit += gcnew System::Windows::Forms::LabelEditEventHandler(this, &ExplorerForm::ContentListView_AfterLabelEdit);
			this->ContentListView->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &ExplorerForm::ContentListView_ItemDrag);
			this->ContentListView->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &ExplorerForm::ContentListView_ItemSelectionChanged);
			this->ContentListView->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &ExplorerForm::ContentListView_DragDrop);
			this->ContentListView->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &ExplorerForm::ContentListView_DragEnter);
			this->ContentListView->DoubleClick += gcnew System::EventHandler(this, &ExplorerForm::ContentListView_DoubleClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Èìÿ";
			this->columnHeader1->Width = 180;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Ğàçìåğ";
			this->columnHeader2->Width = 180;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Èçìåí¸í";
			this->columnHeader3->Width = 180;
			// 
			// buttonUpdate
			// 
			this->buttonUpdate->BackColor = System::Drawing::SystemColors::Control;
			this->buttonUpdate->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonUpdate.BackgroundImage")));
			this->buttonUpdate->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonUpdate->FlatAppearance->BorderSize = 0;
			this->buttonUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonUpdate->Location = System::Drawing::Point(681, 3);
			this->buttonUpdate->Name = L"buttonUpdate";
			this->buttonUpdate->Size = System::Drawing::Size(34, 28);
			this->buttonUpdate->TabIndex = 2;
			this->buttonUpdate->UseVisualStyleBackColor = false;
			this->buttonUpdate->Click += gcnew System::EventHandler(this, &ExplorerForm::buttonUpdate_Click);
			// 
			// directoriesTreeView
			// 
			this->directoriesTreeView->ContextMenuStrip = this->extraContextMenuStrip;
			this->directoriesTreeView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->directoriesTreeView->HotTracking = true;
			this->directoriesTreeView->Location = System::Drawing::Point(0, 0);
			this->directoriesTreeView->Name = L"directoriesTreeView";
			this->directoriesTreeView->Size = System::Drawing::Size(222, 653);
			this->directoriesTreeView->TabIndex = 3;
			this->directoriesTreeView->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &ExplorerForm::directoriesTreeView_BeforeExpand);
			this->directoriesTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &ExplorerForm::directoriesTreeView_AfterSelect);
			// 
			// splitContainer
			// 
			this->splitContainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer->Location = System::Drawing::Point(0, 61);
			this->splitContainer->Name = L"splitContainer";
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->directoriesTreeView);
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->ContentListView);
			this->splitContainer->Size = System::Drawing::Size(1125, 653);
			this->splitContainer->SplitterDistance = 222;
			this->splitContainer->TabIndex = 0;
			// 
			// changeViewButton
			// 
			this->changeViewButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"changeViewButton.BackgroundImage")));
			this->changeViewButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->changeViewButton->FlatAppearance->BorderSize = 0;
			this->changeViewButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->changeViewButton->Location = System::Drawing::Point(168, 4);
			this->changeViewButton->Name = L"changeViewButton";
			this->changeViewButton->Size = System::Drawing::Size(54, 27);
			this->changeViewButton->TabIndex = 6;
			this->changeViewButton->UseVisualStyleBackColor = true;
			this->changeViewButton->Click += gcnew System::EventHandler(this, &ExplorerForm::changeViewButton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonUpdate);
			this->panel1->Controls->Add(this->pathTextBox);
			this->panel1->Controls->Add(this->BackButton);
			this->panel1->Controls->Add(this->changeViewButton);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1125, 36);
			this->panel1->TabIndex = 8;
			// 
			// ExplorerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1125, 714);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->splitContainer);
			this->Controls->Add(this->menuStrip);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"ExplorerForm";
			this->Text = L"MSU-FM-AVD-2021";
			this->Load += gcnew System::EventHandler(this, &ExplorerForm::ExplorerForm_Load);
			this->extraContextMenuStrip->ResumeLayout(false);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ filePath;
		Dictionary<TreeNode^, String^>^ pathDic;
		bool Delete;
		TreeNode^ delnode;
		String^ NameList;
		String^ sourcePath;
		String^ fileName;
		List<TreeNode^>^ backPathList = gcnew List<TreeNode^>;
		

	private: System::Void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContentListView_ItemSelectionChanged(System::Object^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^ e);
	private: System::Void ExplorerForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void directoriesTreeView_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e);
	private: System::Void directoriesTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
	private: System::Void ContentListView_DoubleClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContentListView_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void ContentListView_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void OpenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PropertyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CopyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PasteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DeleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContentListView_ItemDrag(System::Object^ sender, System::Windows::Forms::ItemDragEventArgs^ e);
	private: System::Void RenameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContentListView_AfterLabelEdit(System::Object^ sender, System::Windows::Forms::LabelEditEventArgs^ e);
	private: System::Void CreateFolderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CreateTextFIleToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void changeViewButton_Click(System::Object^ sender, System::EventArgs^ e);

	void DriveTreeInit();
	void GetLocaleDirectories(TreeNode^ parentNode);
	void CopyDirectory(DirectoryInfo^ diSourceDir, DirectoryInfo^ diDestDir);
	void MoveDirectory(String^ strSourceDir, String^ strDestDir, bool bDelSource);
	unsigned long long DirSize(DirectoryInfo^ d);
	private: System::Void AboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CloseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
