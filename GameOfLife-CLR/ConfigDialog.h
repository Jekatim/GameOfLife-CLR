#pragma once

#include "Config.h"

namespace GameOfLifeCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for ConfigDialog
	/// </summary>
	public ref class ConfigDialog : public System::Windows::Forms::Form
	{
	public:
		ConfigDialog(void)
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
		~ConfigDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  widthBox;
	private: System::Windows::Forms::TextBox^  heightBox;
	protected: 


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  seedBox;
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
			this->widthBox = (gcnew System::Windows::Forms::TextBox());
			this->heightBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->seedBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// widthBox
			// 
			this->widthBox->Location = System::Drawing::Point(53, 12);
			this->widthBox->Name = L"widthBox";
			this->widthBox->Size = System::Drawing::Size(51, 20);
			this->widthBox->TabIndex = 0;
			this->widthBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// heightBox
			// 
			this->heightBox->Location = System::Drawing::Point(154, 12);
			this->heightBox->Name = L"heightBox";
			this->heightBox->Size = System::Drawing::Size(51, 20);
			this->heightBox->TabIndex = 1;
			this->heightBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Width";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(110, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Height";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(64, 89);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ConfigDialog::button1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(107, 38);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(102, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Value = 5;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &ConfigDialog::trackBar1_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Seed";
			// 
			// seedBox
			// 
			this->seedBox->Location = System::Drawing::Point(50, 50);
			this->seedBox->Name = L"seedBox";
			this->seedBox->ReadOnly = true;
			this->seedBox->Size = System::Drawing::Size(51, 20);
			this->seedBox->TabIndex = 7;
			this->seedBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ConfigDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(223, 127);
			this->Controls->Add(this->seedBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->heightBox);
			this->Controls->Add(this->widthBox);
			this->Name = L"ConfigDialog";
			this->Text = L"ConfigDialog";
			this->Shown += gcnew System::EventHandler(this, &ConfigDialog::ConfigDialog_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 try
				 {
					 Config::setWidth(Convert::ToInt32(this->widthBox->Text));
					 Config::setHeight(Convert::ToInt32(this->heightBox->Text));
					 Config::setSeed(Convert::ToInt32(this->seedBox->Text));

					 this->Close();
				 }
				 catch (Exception^ ex)
				 {
				 	Debug::WriteLine("Wrong config saving");
				 }				 
			 }

private: System::Void ConfigDialog_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			 try
			 {
				 this->widthBox->Text = Convert::ToString(Config::getWidth());
				 this->heightBox->Text = Convert::ToString(Config::getHeight());
				 this->seedBox->Text = Convert::ToString(Config::getSeed());
				 this->trackBar1->Value = Config::getSeed();
			 }
			 catch (Exception^ ex)
			 {
				 Debug::WriteLine("Wrong config reading");
			 }
		 }
private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->seedBox->Text = Convert::ToString(this->trackBar1->Value);
		 }
};
}
