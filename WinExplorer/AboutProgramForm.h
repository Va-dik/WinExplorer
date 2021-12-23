#pragma once

namespace WinExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AboutProgramForm
	/// </summary>
	public ref class AboutProgramForm : public System::Windows::Forms::Form
	{
	public:
		AboutProgramForm(void)
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
		~AboutProgramForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ copyrightPictureBox;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutProgramForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->copyrightPictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->copyrightPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(49, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(465, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название программы: MSU-FM-AVD-2021";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(35, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(498, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Программу разработал: Ахремчик Вадим Дмитриевич";
			// 
			// copyrightPictureBox
			// 
			this->copyrightPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copyrightPictureBox.Image")));
			this->copyrightPictureBox->Location = System::Drawing::Point(135, 150);
			this->copyrightPictureBox->Name = L"copyrightPictureBox";
			this->copyrightPictureBox->Size = System::Drawing::Size(276, 123);
			this->copyrightPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->copyrightPictureBox->TabIndex = 2;
			this->copyrightPictureBox->TabStop = false;
			// 
			// AboutProgramForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 285);
			this->Controls->Add(this->copyrightPictureBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AboutProgramForm";
			this->Text = L"AboutProgramForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->copyrightPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
