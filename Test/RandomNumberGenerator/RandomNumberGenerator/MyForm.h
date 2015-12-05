#pragma once
#include <stdlib.h>
#include <string>
#include <msclr\marshal_cppstd.h>


using std::string;

namespace RandomNumberGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  MoneyBox;
	protected:



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  AddButton;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  NameBox;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MoneyBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// MoneyBox
			// 
			this->MoneyBox->Location = System::Drawing::Point(157, 38);
			this->MoneyBox->Name = L"MoneyBox";
			this->MoneyBox->Size = System::Drawing::Size(120, 22);
			this->MoneyBox->TabIndex = 0;
			this->MoneyBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(154, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Money";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Participants";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(305, 34);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(58, 26);
			this->AddButton->TabIndex = 5;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyForm::AddButton_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(264, 113);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 30);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Calculate";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// NameBox
			// 
			this->NameBox->Location = System::Drawing::Point(42, 37);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(100, 22);
			this->NameBox->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 469);
			this->Controls->Add(this->NameBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MoneyBox);
			this->Name = L"MyForm";
			this->Text = L"AccountBook";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
	}
	private: System::Void AddButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^ name = NameBox->Text;
		String ^ money = MoneyBox->Text;
		double dmoney = std::stod(MarshalString(money));
		int cnt = 2;
		double aver = dmoney / cnt;
		MessageBox::Show(name + " pays: " + aver);
	}
	private: string MarshalString(String ^ s) {
		using namespace Runtime::InteropServices;
		return msclr::interop::marshal_as<std::string>(s);
	}
	};
}
