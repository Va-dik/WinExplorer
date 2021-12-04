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
	/// ������ ��� MyForm
	/// </summary>
	public ref class ExplorerForm : public System::Windows::Forms::Form
	{
	public:
		ExplorerForm(void)
		{
			InitializeComponent();

			this->ContentListView->AllowDrop = true;

			this->ContentListView->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &ExplorerForm::ContentListView_DragEnter);
			this->ContentListView->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &ExplorerForm::ContentListView_DragDrop);
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ExplorerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListView^ ContentListView;
	private: System::Windows::Forms::Button^ buttonEnter;












	private: System::Windows::Forms::TreeView^ directoriesTreeView;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ searchByMask;

	private: System::Windows::Forms::ToolStrip^ toolStrip1;

	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TextBox^ pathTextBox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ContextMenuStrip^ extraContextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;



















	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ExplorerForm::typeid));
			this->ContentListView = (gcnew System::Windows::Forms::ListView());
			this->extraContextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonEnter = (gcnew System::Windows::Forms::Button());
			this->directoriesTreeView = (gcnew System::Windows::Forms::TreeView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchByMask = (gcnew System::Windows::Forms::TextBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->pathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->extraContextMenuStrip->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ContentListView
			// 
			this->ContentListView->ContextMenuStrip = this->extraContextMenuStrip;
			this->ContentListView->HideSelection = false;
			this->ContentListView->Location = System::Drawing::Point(261, 124);
			this->ContentListView->Name = L"ContentListView";
			this->ContentListView->Size = System::Drawing::Size(779, 578);
			this->ContentListView->TabIndex = 0;
			this->ContentListView->UseCompatibleStateImageBehavior = false;
			this->ContentListView->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &ExplorerForm::ContentListView_ItemDrag);
			this->ContentListView->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &ExplorerForm::ContentListView_ItemSelectionChanged);
			this->ContentListView->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &ExplorerForm::ContentListView_DragDrop);
			this->ContentListView->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &ExplorerForm::ContentListView_DragEnter);
			this->ContentListView->DoubleClick += gcnew System::EventHandler(this, &ExplorerForm::ContentListView_DoubleClick);
			this->ContentListView->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ExplorerForm::ContentListView_MouseDown);
			this->ContentListView->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ExplorerForm::ContentListView_MouseMove);
			// 
			// extraContextMenuStrip
			// 
			this->extraContextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->�������ToolStripMenuItem,
					this->����������ToolStripMenuItem, this->��������ToolStripMenuItem, this->�������ToolStripMenuItem, this->��������ToolStripMenuItem
			});
			this->extraContextMenuStrip->Name = L"contextMenuStrip1";
			this->extraContextMenuStrip->Size = System::Drawing::Size(181, 136);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::�������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::����������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ExplorerForm::��������ToolStripMenuItem_Click);
			// 
			// buttonEnter
			// 
			this->buttonEnter->BackColor = System::Drawing::SystemColors::Control;
			this->buttonEnter->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonEnter.BackgroundImage")));
			this->buttonEnter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonEnter->FlatAppearance->BorderSize = 0;
			this->buttonEnter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEnter->Location = System::Drawing::Point(713, 88);
			this->buttonEnter->Name = L"buttonEnter";
			this->buttonEnter->Size = System::Drawing::Size(34, 28);
			this->buttonEnter->TabIndex = 2;
			this->buttonEnter->UseVisualStyleBackColor = false;
			this->buttonEnter->Click += gcnew System::EventHandler(this, &ExplorerForm::buttonEnter_Click);
			// 
			// directoriesTreeView
			// 
			this->directoriesTreeView->Location = System::Drawing::Point(22, 124);
			this->directoriesTreeView->Name = L"directoriesTreeView";
			this->directoriesTreeView->Size = System::Drawing::Size(240, 578);
			this->directoriesTreeView->TabIndex = 3;
			this->directoriesTreeView->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &ExplorerForm::directoriesTreeView_BeforeExpand);
			this->directoriesTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &ExplorerForm::directoriesTreeView_AfterSelect);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1125, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�����ToolStripMenuItem,
					this->����������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->�����ToolStripMenuItem->Text = L"�������";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			// 
			// searchByMask
			// 
			this->searchByMask->Location = System::Drawing::Point(771, 88);
			this->searchByMask->Multiline = true;
			this->searchByMask->Name = L"searchByMask";
			this->searchByMask->Size = System::Drawing::Size(268, 28);
			this->searchByMask->TabIndex = 5;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1125, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// pathTextBox
			// 
			this->pathTextBox->Location = System::Drawing::Point(260, 88);
			this->pathTextBox->Multiline = true;
			this->pathTextBox->Name = L"pathTextBox";
			this->pathTextBox->Size = System::Drawing::Size(449, 28);
			this->pathTextBox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(22, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(53, 28);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// ExplorerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1125, 714);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pathTextBox);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->searchByMask);
			this->Controls->Add(this->directoriesTreeView);
			this->Controls->Add(this->buttonEnter);
			this->Controls->Add(this->ContentListView);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"ExplorerForm";
			this->Text = L"WinExplorer";
			this->Load += gcnew System::EventHandler(this, &ExplorerForm::ExplorerForm_Load);
			this->extraContextMenuStrip->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ currentPath;
		String^ fileName;
		Dictionary<TreeNode^, String^>^ pathDic;

	private: System::Void buttonEnter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContentListView_ItemSelectionChanged(System::Object^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^ e);
	private: System::Void ExplorerForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void directoriesTreeView_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e);
	private: System::Void directoriesTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
	private: System::Void ContentListView_DoubleClick(System::Object^ sender, System::EventArgs^ e);

		   void AddDirs(TreeNode^ parentNode);
		   void CopyFiles();
	private: System::Void ContentListView_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void ContentListView_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void ContentListView_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void ContentListView_ItemDrag(System::Object^ sender, System::Windows::Forms::ItemDragEventArgs^ e);
	private: System::Void ContentListView_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
