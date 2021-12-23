#pragma once

namespace WinExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PropertyForm
	/// </summary>
	public ref class PropertyForm : public System::Windows::Forms::Form
	{
	public:
		PropertyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PropertyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ fileNameLabel;
	protected:

	private: System::Windows::Forms::Label^ fileLocationLabel;
	internal: System::Windows::Forms::Label^ fileSizeLabel;
	private:


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	internal: System::Windows::Forms::Label^ dataFileNameLabel;
	private:

	private:

	private:


	private:
	internal: System::Windows::Forms::Label^ dataFileLocationLabel;
	internal: System::Windows::Forms::Label^ dataFileSizeLabel;
	internal: System::Windows::Forms::Label^ dataFileCreationLabel;
	internal: System::Windows::Forms::Label^ dataFileChangedLabel;
	internal: System::Windows::Forms::Label^ dataFileOpenedLabel;


	public:

	public:

	public:

	public:

	private:








	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->fileNameLabel = (gcnew System::Windows::Forms::Label());
			this->fileLocationLabel = (gcnew System::Windows::Forms::Label());
			this->fileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dataFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileLocationLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileCreationLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileChangedLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileOpenedLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// fileNameLabel
			// 
			this->fileNameLabel->AutoSize = true;
			this->fileNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileNameLabel->Location = System::Drawing::Point(17, 52);
			this->fileNameLabel->MinimumSize = System::Drawing::Size(73, 15);
			this->fileNameLabel->Name = L"fileNameLabel";
			this->fileNameLabel->Size = System::Drawing::Size(77, 15);
			this->fileNameLabel->TabIndex = 0;
			this->fileNameLabel->Text = L"Имя файла:";
			// 
			// fileLocationLabel
			// 
			this->fileLocationLabel->AutoSize = true;
			this->fileLocationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileLocationLabel->Location = System::Drawing::Point(17, 87);
			this->fileLocationLabel->MinimumSize = System::Drawing::Size(96, 15);
			this->fileLocationLabel->Name = L"fileLocationLabel";
			this->fileLocationLabel->Size = System::Drawing::Size(96, 15);
			this->fileLocationLabel->TabIndex = 1;
			this->fileLocationLabel->Text = L"Расположение:";
			// 
			// fileSizeLabel
			// 
			this->fileSizeLabel->AutoSize = true;
			this->fileSizeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileSizeLabel->Location = System::Drawing::Point(17, 120);
			this->fileSizeLabel->MinimumSize = System::Drawing::Size(54, 15);
			this->fileSizeLabel->Name = L"fileSizeLabel";
			this->fileSizeLabel->Size = System::Drawing::Size(54, 15);
			this->fileSizeLabel->TabIndex = 4;
			this->fileSizeLabel->Text = L"Размер:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 147);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(337, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"_______________________________________________________";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(17, 175);
			this->label7->MinimumSize = System::Drawing::Size(52, 15);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 15);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Создан:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(17, 216);
			this->label8->MinimumSize = System::Drawing::Size(62, 15);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(62, 15);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Изменён:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(17, 259);
			this->label9->MinimumSize = System::Drawing::Size(30, 15);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 15);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Открыт:";
			// 
			// dataFileNameLabel
			// 
			this->dataFileNameLabel->AutoSize = true;
			this->dataFileNameLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dataFileNameLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataFileNameLabel->Location = System::Drawing::Point(134, 52);
			this->dataFileNameLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileNameLabel->Name = L"dataFileNameLabel";
			this->dataFileNameLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileNameLabel->TabIndex = 9;
			// 
			// dataFileLocationLabel
			// 
			this->dataFileLocationLabel->AutoSize = true;
			this->dataFileLocationLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dataFileLocationLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataFileLocationLabel->Location = System::Drawing::Point(134, 87);
			this->dataFileLocationLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileLocationLabel->Name = L"dataFileLocationLabel";
			this->dataFileLocationLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileLocationLabel->TabIndex = 9;
			// 
			// dataFileSizeLabel
			// 
			this->dataFileSizeLabel->AutoSize = true;
			this->dataFileSizeLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dataFileSizeLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataFileSizeLabel->Location = System::Drawing::Point(134, 122);
			this->dataFileSizeLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileSizeLabel->Name = L"dataFileSizeLabel";
			this->dataFileSizeLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileSizeLabel->TabIndex = 9;
			// 
			// dataFileCreationLabel
			// 
			this->dataFileCreationLabel->AutoSize = true;
			this->dataFileCreationLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dataFileCreationLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataFileCreationLabel->Location = System::Drawing::Point(134, 175);
			this->dataFileCreationLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileCreationLabel->Name = L"dataFileCreationLabel";
			this->dataFileCreationLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileCreationLabel->TabIndex = 9;
			// 
			// dataFileChangedLabel
			// 
			this->dataFileChangedLabel->AutoSize = true;
			this->dataFileChangedLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dataFileChangedLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataFileChangedLabel->Location = System::Drawing::Point(134, 216);
			this->dataFileChangedLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileChangedLabel->Name = L"dataFileChangedLabel";
			this->dataFileChangedLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileChangedLabel->TabIndex = 9;
			// 
			// dataFileOpenedLabel
			// 
			this->dataFileOpenedLabel->AutoSize = true;
			this->dataFileOpenedLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dataFileOpenedLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataFileOpenedLabel->Location = System::Drawing::Point(134, 261);
			this->dataFileOpenedLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileOpenedLabel->Name = L"dataFileOpenedLabel";
			this->dataFileOpenedLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileOpenedLabel->TabIndex = 9;
			// 
			// PropertyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(364, 313);
			this->Controls->Add(this->dataFileOpenedLabel);
			this->Controls->Add(this->dataFileChangedLabel);
			this->Controls->Add(this->dataFileSizeLabel);
			this->Controls->Add(this->dataFileCreationLabel);
			this->Controls->Add(this->dataFileLocationLabel);
			this->Controls->Add(this->dataFileNameLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->fileSizeLabel);
			this->Controls->Add(this->fileLocationLabel);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->fileNameLabel);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->Name = L"PropertyForm";
			this->ShowIcon = false;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
