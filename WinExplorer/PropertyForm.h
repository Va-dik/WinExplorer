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
	private: System::Windows::Forms::Label^ fileTypeLabel;
	private: System::Windows::Forms::Label^ fileLocationLabel;
	protected:


	protected:

	protected:

	protected:

	protected:

	protected:

	protected:

	protected:


	private: System::Windows::Forms::Label^ fileSizeLabel;
	private: System::Windows::Forms::TextBox^ fileNameTextBox;









	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ fileIconLabel;

	private: System::Windows::Forms::Label^ dataFileTypeLabel;
	private: System::Windows::Forms::Label^ dataFileLocationLabel;
	private: System::Windows::Forms::Label^ dataFileSizeLabel;
	private: System::Windows::Forms::Label^ dataFileCreationLabel;
	private: System::Windows::Forms::Label^ dataFileChangedLabel;
	private: System::Windows::Forms::Label^ dataFileOpened;

































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
			this->fileTypeLabel = (gcnew System::Windows::Forms::Label());
			this->fileLocationLabel = (gcnew System::Windows::Forms::Label());
			this->fileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->fileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->fileIconLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileTypeLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileLocationLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileCreationLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileChangedLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileOpened = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// fileTypeLabel
			// 
			this->fileTypeLabel->AutoSize = true;
			this->fileTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileTypeLabel->Location = System::Drawing::Point(12, 91);
			this->fileTypeLabel->MinimumSize = System::Drawing::Size(73, 15);
			this->fileTypeLabel->Name = L"fileTypeLabel";
			this->fileTypeLabel->Size = System::Drawing::Size(73, 15);
			this->fileTypeLabel->TabIndex = 0;
			this->fileTypeLabel->Text = L"Тип файла:";
			// 
			// fileLocationLabel
			// 
			this->fileLocationLabel->AutoSize = true;
			this->fileLocationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileLocationLabel->Location = System::Drawing::Point(12, 120);
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
			this->fileSizeLabel->Location = System::Drawing::Point(12, 149);
			this->fileSizeLabel->MinimumSize = System::Drawing::Size(54, 15);
			this->fileSizeLabel->Name = L"fileSizeLabel";
			this->fileSizeLabel->Size = System::Drawing::Size(54, 15);
			this->fileSizeLabel->TabIndex = 4;
			this->fileSizeLabel->Text = L"Размер:";
			// 
			// fileNameTextBox
			// 
			this->fileNameTextBox->Location = System::Drawing::Point(152, 47);
			this->fileNameTextBox->Name = L"fileNameTextBox";
			this->fileNameTextBox->Size = System::Drawing::Size(164, 20);
			this->fileNameTextBox->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 178);
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
			this->label7->Location = System::Drawing::Point(12, 208);
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
			this->label8->Location = System::Drawing::Point(12, 237);
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
			this->label9->Location = System::Drawing::Point(12, 266);
			this->label9->MinimumSize = System::Drawing::Size(30, 15);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 15);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Открыт:";
			// 
			// fileIconLabel
			// 
			this->fileIconLabel->AutoSize = true;
			this->fileIconLabel->Location = System::Drawing::Point(28, 47);
			this->fileIconLabel->Name = L"fileIconLabel";
			this->fileIconLabel->Size = System::Drawing::Size(35, 13);
			this->fileIconLabel->TabIndex = 8;
			this->fileIconLabel->Text = L"label4";
			// 
			// dataFileTypeLabel
			// 
			this->dataFileTypeLabel->AutoSize = true;
			this->dataFileTypeLabel->Location = System::Drawing::Point(129, 91);
			this->dataFileTypeLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileTypeLabel->Name = L"dataFileTypeLabel";
			this->dataFileTypeLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileTypeLabel->TabIndex = 9;
			// 
			// dataFileLocationLabel
			// 
			this->dataFileLocationLabel->AutoSize = true;
			this->dataFileLocationLabel->Location = System::Drawing::Point(129, 120);
			this->dataFileLocationLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileLocationLabel->Name = L"dataFileLocationLabel";
			this->dataFileLocationLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileLocationLabel->TabIndex = 9;
			// 
			// dataFileSizeLabel
			// 
			this->dataFileSizeLabel->AutoSize = true;
			this->dataFileSizeLabel->Location = System::Drawing::Point(129, 151);
			this->dataFileSizeLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileSizeLabel->Name = L"dataFileSizeLabel";
			this->dataFileSizeLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileSizeLabel->TabIndex = 9;
			// 
			// dataFileCreationLabel
			// 
			this->dataFileCreationLabel->AutoSize = true;
			this->dataFileCreationLabel->Location = System::Drawing::Point(129, 208);
			this->dataFileCreationLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileCreationLabel->Name = L"dataFileCreationLabel";
			this->dataFileCreationLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileCreationLabel->TabIndex = 9;
			// 
			// dataFileChangedLabel
			// 
			this->dataFileChangedLabel->AutoSize = true;
			this->dataFileChangedLabel->Location = System::Drawing::Point(129, 237);
			this->dataFileChangedLabel->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileChangedLabel->Name = L"dataFileChangedLabel";
			this->dataFileChangedLabel->Size = System::Drawing::Size(220, 15);
			this->dataFileChangedLabel->TabIndex = 9;
			// 
			// dataFileOpened
			// 
			this->dataFileOpened->AutoSize = true;
			this->dataFileOpened->Location = System::Drawing::Point(129, 268);
			this->dataFileOpened->MinimumSize = System::Drawing::Size(220, 15);
			this->dataFileOpened->Name = L"dataFileOpened";
			this->dataFileOpened->Size = System::Drawing::Size(220, 15);
			this->dataFileOpened->TabIndex = 9;
			// 
			// PropertyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(366, 383);
			this->Controls->Add(this->dataFileOpened);
			this->Controls->Add(this->dataFileChangedLabel);
			this->Controls->Add(this->dataFileSizeLabel);
			this->Controls->Add(this->dataFileCreationLabel);
			this->Controls->Add(this->dataFileLocationLabel);
			this->Controls->Add(this->dataFileTypeLabel);
			this->Controls->Add(this->fileIconLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->fileNameTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->fileSizeLabel);
			this->Controls->Add(this->fileLocationLabel);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->fileTypeLabel);
			this->MaximizeBox = false;
			this->Name = L"PropertyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
