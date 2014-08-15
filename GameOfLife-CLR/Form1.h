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
	private: System::Windows::Forms::ToolStripMenuItem^  runToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^  startToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  stopToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  stepToolStripMenuItem;
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
			this->runToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stopToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stepToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->runToolStripMenuItem});
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
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->optionsToolStripMenuItem->Text = L"Options";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::optionsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// runToolStripMenuItem
			// 
			this->runToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->startToolStripMenuItem1, 
				this->stopToolStripMenuItem1, this->stepToolStripMenuItem});
			this->runToolStripMenuItem->Name = L"runToolStripMenuItem";
			this->runToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->runToolStripMenuItem->Text = L"Run";
			// 
			// startToolStripMenuItem1
			// 
			this->startToolStripMenuItem1->Name = L"startToolStripMenuItem1";
			this->startToolStripMenuItem1->Size = System::Drawing::Size(121, 22);
			this->startToolStripMenuItem1->Text = L"Start";
			this->startToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::startToolStripMenuItem1_Click);
			// 
			// stopToolStripMenuItem1
			// 
			this->stopToolStripMenuItem1->Name = L"stopToolStripMenuItem1";
			this->stopToolStripMenuItem1->Size = System::Drawing::Size(121, 22);
			this->stopToolStripMenuItem1->Text = L"Stop";
			this->stopToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::stopToolStripMenuItem1_Click);
			// 
			// stepToolStripMenuItem
			// 
			this->stepToolStripMenuItem->Name = L"stepToolStripMenuItem";
			this->stepToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->stepToolStripMenuItem->Text = L"One step";
			this->stepToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::stepToolStripMenuItem_Click);
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
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
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

				Thread::Sleep(30);
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
			double seed = Config::getSeed()/10.0;
			for (int i = 0; i < backBuffer->Length; i++)
			{
				for (int j = 0; j < backBuffer[i]->Length; j++)
				{
					backBuffer[i][j] = Math::Floor(rnd->NextDouble() + seed);
				}
			}

			backBuffer->CopyTo(frontBuffer, 0);

			pictureBox1->Invalidate();
		}

		int CountNeighbours(int x, int y)
		{
			int counter = 0;
			int nb[2][8];
			int k = 0;

			for (int i = x - 1; i <= x + 1; i++) {
				for (int j = y - 1; j <= y + 1; j++) {

					if (i == x && j == y)
						continue;

					if (i < 0) 
						nb[0][k] = frontBuffer->Length - 1;
					else 
						if (i >= frontBuffer->Length) 
							nb[0][k] = 0;
						else
							nb[0][k] = i;

					if (j < 0) 
						nb[1][k] = frontBuffer[0]->Length - 1;
					else 
						if (j >= frontBuffer[0]->Length) 
							nb[1][k] = 0;
						else
							nb[1][k] = j;

					k++;
				}
			}

			for (int i = 0; i < 8; i++)
			{
				if (frontBuffer[nb[0][i]][nb[1][i]] == 1)
					counter++;
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
							default:
								backBuffer[i][j] = 0;
								break;
						}
					}
					else
					{
						switch (neighbours)
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
private: System::Void startToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 resume = true;
			 this->calcthr = gcnew Thread(gcnew ParameterizedThreadStart(&CalcThread));
			 this->calcthr->Start(this);
		 }
private: System::Void stopToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 resume = false;
			 calcthr->Join();
		 }
private: System::Void stepToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CalculateGeneration();
		 }
private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {
			 switch (e->KeyCode)
			 {
			 case Keys::Space:
				 stepToolStripMenuItem_Click(sender, e);
				 break;
			 case Keys::R:
				 startToolStripMenuItem1_Click(sender, e);
				 break;
			 case Keys::S:
				 stopToolStripMenuItem1_Click(sender, e);
				 break;
			 case Keys::Escape:
				 exitToolStripMenuItem_Click(sender, e);
				 break;
			 default:
				 break;
			 }
		 }
private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->menuStrip1->Refresh();
		 }
};
}

