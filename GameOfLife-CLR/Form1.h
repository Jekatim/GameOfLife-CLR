#pragma once

#include "ConfigDialog.h"

namespace GameOfLifeCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			PrepareFields();
			FillRandomBuffer();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::ToolStripMenuItem^  startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  stopToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->stopToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->startToolStripMenuItem, this->stopToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->optionsToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->optionsToolStripMenuItem->Text = L"Options";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::optionsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->startToolStripMenuItem->Text = L"Start";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::startToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(760, 523);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// stopToolStripMenuItem
			// 
			this->stopToolStripMenuItem->Name = L"stopToolStripMenuItem";
			this->stopToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->stopToolStripMenuItem->Text = L"Stop";
			this->stopToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::stopToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//////////////////////////////////////////////////////////////////////////

		static array<array<unsigned char>^>^ frontBuffer;
		static array<array<unsigned char>^>^ backBuffer;

		Thread^ calcthr;
		static bool resume = false;

		static void CalcThread(System::Object^ data)
		{
			Form1^ pForm1 = (Form1^)data;

			while (resume)
			{
				pForm1->CalculateGeneration();

				pForm1->pictureBox1->Invalidate();
			}
		}

		void PrepareFields()
		{
			frontBuffer = gcnew array<array<unsigned char>^>(Config::getWidth());
			backBuffer = gcnew array<array<unsigned char>^>(Config::getWidth());

			for (int i = 0; i < Config::getWidth(); i++)
			{
				frontBuffer[i] = gcnew array<unsigned char>(Config::getHeight());
				backBuffer[i] = gcnew array<unsigned char>(Config::getHeight());
			}
		}

		void FillRandomBuffer()
		{
			Random^ rnd = gcnew Random();
			for (int i = 0; i < backBuffer->Length; i++)
			{
				for (int j = 0; j < backBuffer[i]->Length; j++)
				{
					backBuffer[i][j] = Math::Floor(rnd->NextDouble()+0.5);
				}
			}

			backBuffer->CopyTo(frontBuffer, 0);

			pictureBox1->Invalidate();
		}

		int CountNeighbours(int x, int y)
		{
			int counter = 0;

			for (int i = Math::Max(x-1, 0); i <= Math::Min(x+1, frontBuffer->Length - 1); i++)
			{
				for (int j = Math::Max(y-1, 0); j <= Math::Min(y+1, frontBuffer[0]->Length - 1); j++)
				{
					if (frontBuffer[i][j] == 1)
					{
						counter++;
					}
				}
			}
			return counter;
		}

		void CalculateGeneration()
		{
			int neighbours = 0;

			for (int i = 0; i < backBuffer->Length; i++)
			{
				for (int j = 0; j < backBuffer[0]->Length; j++)
				{
					neighbours = CountNeighbours(i, j);

					if (frontBuffer[i][j] == 0)
					{
						switch (neighbours)
						{
							case 3:
								backBuffer[i][j] = 1;
								break;
						}
					}
					else
					{
						switch (neighbours - 1)
						{
							case 2:
							case 3:
								backBuffer[i][j] = 1;
								break;
							default:
								backBuffer[i][j] = 0;
								break;
						}
					}
				}
			}

			backBuffer->CopyTo(frontBuffer, 0);

			pictureBox1->Invalidate();
		}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 resume = false;
				 Application::Exit();
			 }
private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ConfigDialog^ cfgdlg = gcnew ConfigDialog();
			 cfgdlg->ShowDialog();

			 PrepareFields();
			 FillRandomBuffer();
			 pictureBox1->Invalidate();
		 }
private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 pictureBox1->Invalidate();
		 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		 {
			 int picw = this->pictureBox1->Width;
			 int pich = this->pictureBox1->Height;

			 Bitmap^ bmp = gcnew Bitmap(picw, pich);
			 Graphics^ g = Graphics::FromImage(bmp);

			 g->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			 g->CompositingQuality = Drawing2D::CompositingQuality::HighQuality;
			 g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;

			 int wndw = Config::getWidth();
			 int wndh = Config::getHeight();

			 float stepw = picw / wndw;
			 float steph = pich / wndh;

			 for (int i = 0; i < wndw; i++)
			 {
				 for (int j = 0; j < wndh; j++)
				 {
					 g->DrawRectangle(Pens::Aqua, i*stepw + 1, j*steph + 1, stepw - 1, steph - 1);
					 if (frontBuffer[i][j] == 0)
					 {
						 g->FillRectangle(Brushes::White, i*stepw + 1, j*steph + 1, stepw - 1, steph - 1);
					 } 
					 else
					 {
						 g->FillRectangle(Brushes::Black, i*stepw + 1, j*steph + 1, stepw - 1, steph - 1);
					 }
				 }
			 }

			 this->pictureBox1->Image = bmp;
		 }
private: System::Void startToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 resume = true;
			 this->calcthr = gcnew Thread(gcnew ParameterizedThreadStart(&CalcThread));
			 this->calcthr->Start(this);
		 }

private: System::Void stopToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 resume = false;
			 calcthr->Join();
		 }
};
}

