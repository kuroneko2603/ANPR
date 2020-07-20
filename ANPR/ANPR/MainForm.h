#pragma once
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/ml.h>
#include <opencv/cxcore.h>
#include <stdio.h>
#include"PlateFinder.h"
#include"Function.h"

namespace ANPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		IplImage* src;
	private: System::Windows::Forms::Panel^ PnParking;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ btn_Recognize1;
	private: System::Windows::Forms::Button^ Btn_Browse1;

	private: System::Windows::Forms::Label^ pltNumber;
	private: System::Windows::Forms::PictureBox^ pltImg;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ srcImg1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ PNumber;
	private: System::Windows::Forms::Button^ btn_recognize;
	private: System::Windows::Forms::Button^ btn_browse;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ PlateImage;
	private: System::Windows::Forms::PictureBox^ SrcImage;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnFee;

	private: System::Windows::Forms::Button^ btnPrkLot;

	private: System::Windows::Forms::Button^ btnStaff;

	private: System::Windows::Forms::Button^ btnVehicle;

	private: System::Windows::Forms::Button^ btnCus;

	private: System::Windows::Forms::Button^ btnParking;
	private: System::Windows::Forms::Button^ btnReport;
	private: System::Windows::Forms::Panel^ PnCus;


	private: System::Windows::Forms::Button^ btnAddCus;
	private: System::Windows::Forms::GroupBox^ GB1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DOB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PNumbers;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nVehicle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Balance;
	private: System::Windows::Forms::Panel^ PnVehicle;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CusID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PlateNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Term;
	private: System::Windows::Forms::Panel^ PnStaff;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ GbStaff;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Avl1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Avl2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ PnPrkLot;
	private: System::Windows::Forms::Panel^ PnFee;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::DataGridView^ dataGridView5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Description;
	private: System::Windows::Forms::Panel^ PnReport;


	private: System::Windows::Forms::DateTimePicker^ DateStart;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DataGridView^ dataGridView6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdTicket;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Value;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BillDate;
	private: System::Windows::Forms::DataGridView^ dataGridView7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDCus;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CusName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RegDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NVelcus;
	private: System::Windows::Forms::Label^ TileLb;
	
		   
	IplImage* src1;
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			if (src)
			{
				src = NULL;
			}
			if (src1)
			{
				src = NULL;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PnParking = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->btn_browse = (gcnew System::Windows::Forms::Button());
			this->btn_Recognize1 = (gcnew System::Windows::Forms::Button());
			this->Btn_Browse1 = (gcnew System::Windows::Forms::Button());
			this->pltNumber = (gcnew System::Windows::Forms::Label());
			this->pltImg = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->srcImg1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->PNumber = (gcnew System::Windows::Forms::Label());
			this->btn_recognize = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PlateImage = (gcnew System::Windows::Forms::PictureBox());
			this->SrcImage = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnReport = (gcnew System::Windows::Forms::Button());
			this->btnFee = (gcnew System::Windows::Forms::Button());
			this->btnPrkLot = (gcnew System::Windows::Forms::Button());
			this->btnStaff = (gcnew System::Windows::Forms::Button());
			this->btnVehicle = (gcnew System::Windows::Forms::Button());
			this->btnCus = (gcnew System::Windows::Forms::Button());
			this->btnParking = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->PnCus = (gcnew System::Windows::Forms::Panel());
			this->btnAddCus = (gcnew System::Windows::Forms::Button());
			this->GB1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DOB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PNumbers = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nVehicle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Balance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PnVehicle = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->CusID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PlateNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Term = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PnStaff = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->GbStaff = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Avl1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Avl2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->PnPrkLot = (gcnew System::Windows::Forms::Panel());
			this->PnFee = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PnReport = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->DateStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
			this->IdTicket = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BillDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView7 = (gcnew System::Windows::Forms::DataGridView());
			this->IDCus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CusName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RegDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NVelcus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TileLb = (gcnew System::Windows::Forms::Label());
			this->PnParking->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pltImg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->srcImg1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlateImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcImage))->BeginInit();
			this->panel2->SuspendLayout();
			this->PnCus->SuspendLayout();
			this->GB1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->PnVehicle->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->PnStaff->SuspendLayout();
			this->GbStaff->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->PnPrkLot->SuspendLayout();
			this->PnFee->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			this->PnReport->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->BeginInit();
			this->SuspendLayout();
			// 
			// PnParking
			// 
			this->PnParking->BackColor = System::Drawing::SystemColors::Control;
			this->PnParking->Controls->Add(this->label11);
			this->PnParking->Controls->Add(this->btn_browse);
			this->PnParking->Controls->Add(this->btn_Recognize1);
			this->PnParking->Controls->Add(this->Btn_Browse1);
			this->PnParking->Controls->Add(this->pltNumber);
			this->PnParking->Controls->Add(this->pltImg);
			this->PnParking->Controls->Add(this->label7);
			this->PnParking->Controls->Add(this->label6);
			this->PnParking->Controls->Add(this->srcImg1);
			this->PnParking->Controls->Add(this->label4);
			this->PnParking->Controls->Add(this->PNumber);
			this->PnParking->Controls->Add(this->btn_recognize);
			this->PnParking->Controls->Add(this->label2);
			this->PnParking->Controls->Add(this->label1);
			this->PnParking->Controls->Add(this->PlateImage);
			this->PnParking->Controls->Add(this->SrcImage);
			this->PnParking->Location = System::Drawing::Point(178, 30);
			this->PnParking->Name = L"PnParking";
			this->PnParking->Size = System::Drawing::Size(1200, 700);
			this->PnParking->TabIndex = 0;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(604, 39);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(88, 20);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Vehicle out";
			// 
			// btn_browse
			// 
			this->btn_browse->AllowDrop = true;
			this->btn_browse->Location = System::Drawing::Point(8, 655);
			this->btn_browse->Name = L"btn_browse";
			this->btn_browse->Size = System::Drawing::Size(100, 30);
			this->btn_browse->TabIndex = 26;
			this->btn_browse->Text = L"Browse";
			this->btn_browse->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_browse->UseVisualStyleBackColor = true;
			this->btn_browse->Click += gcnew System::EventHandler(this, &MainForm::Btn_browse_Click);
			// 
			// btn_Recognize1
			// 
			this->btn_Recognize1->Location = System::Drawing::Point(728, 655);
			this->btn_Recognize1->Name = L"btn_Recognize1";
			this->btn_Recognize1->Size = System::Drawing::Size(120, 30);
			this->btn_Recognize1->TabIndex = 40;
			this->btn_Recognize1->Text = L"Recognize";
			this->btn_Recognize1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_Recognize1->UseVisualStyleBackColor = true;
			this->btn_Recognize1->Visible = false;
			// 
			// Btn_Browse1
			// 
			this->Btn_Browse1->AllowDrop = true;
			this->Btn_Browse1->Location = System::Drawing::Point(608, 655);
			this->Btn_Browse1->Name = L"Btn_Browse1";
			this->Btn_Browse1->Size = System::Drawing::Size(100, 30);
			this->Btn_Browse1->TabIndex = 39;
			this->Btn_Browse1->Text = L"Browse";
			this->Btn_Browse1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Btn_Browse1->UseVisualStyleBackColor = true;
			this->Btn_Browse1->Click += gcnew System::EventHandler(this, &MainForm::Btn_Browse1_Click);
			// 
			// pltNumber
			// 
			this->pltNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pltNumber->Location = System::Drawing::Point(967, 569);
			this->pltNumber->Name = L"pltNumber";
			this->pltNumber->Size = System::Drawing::Size(240, 50);
			this->pltNumber->TabIndex = 36;
			this->pltNumber->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pltImg
			// 
			this->pltImg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pltImg->Enabled = false;
			this->pltImg->Location = System::Drawing::Point(608, 569);
			this->pltImg->Name = L"pltImg";
			this->pltImg->Size = System::Drawing::Size(240, 50);
			this->pltImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pltImg->TabIndex = 35;
			this->pltImg->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(969, 546);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 20);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Plate Number";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(604, 546);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 20);
			this->label6->TabIndex = 33;
			this->label6->Text = L"PlateImg";
			// 
			// srcImg1
			// 
			this->srcImg1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->srcImg1->Location = System::Drawing::Point(598, 62);
			this->srcImg1->Margin = System::Windows::Forms::Padding(0);
			this->srcImg1->Name = L"srcImg1";
			this->srcImg1->Size = System::Drawing::Size(600, 450);
			this->srcImg1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->srcImg1->TabIndex = 32;
			this->srcImg1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(302, 546);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 20);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Plate Number";
			// 
			// PNumber
			// 
			this->PNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PNumber->Location = System::Drawing::Point(300, 569);
			this->PNumber->Name = L"PNumber";
			this->PNumber->Size = System::Drawing::Size(240, 50);
			this->PNumber->TabIndex = 28;
			this->PNumber->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->PNumber->Click += gcnew System::EventHandler(this, &MainForm::PNumber_Click);
			// 
			// btn_recognize
			// 
			this->btn_recognize->Location = System::Drawing::Point(128, 655);
			this->btn_recognize->Name = L"btn_recognize";
			this->btn_recognize->Size = System::Drawing::Size(120, 30);
			this->btn_recognize->TabIndex = 27;
			this->btn_recognize->Text = L"Recognize";
			this->btn_recognize->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_recognize->UseVisualStyleBackColor = true;
			this->btn_recognize->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 546);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 20);
			this->label2->TabIndex = 25;
			this->label2->Text = L"PlateImg";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 20);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Vehicle in";
			// 
			// PlateImage
			// 
			this->PlateImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlateImage->Enabled = false;
			this->PlateImage->Location = System::Drawing::Point(8, 569);
			this->PlateImage->Name = L"PlateImage";
			this->PlateImage->Size = System::Drawing::Size(240, 50);
			this->PlateImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PlateImage->TabIndex = 23;
			this->PlateImage->TabStop = false;
			// 
			// SrcImage
			// 
			this->SrcImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SrcImage->Location = System::Drawing::Point(1, 62);
			this->SrcImage->Margin = System::Windows::Forms::Padding(0);
			this->SrcImage->Name = L"SrcImage";
			this->SrcImage->Size = System::Drawing::Size(600, 450);
			this->SrcImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->SrcImage->TabIndex = 22;
			this->SrcImage->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel2->Controls->Add(this->btnReport);
			this->panel2->Controls->Add(this->btnFee);
			this->panel2->Controls->Add(this->btnPrkLot);
			this->panel2->Controls->Add(this->btnStaff);
			this->panel2->Controls->Add(this->btnVehicle);
			this->panel2->Controls->Add(this->btnCus);
			this->panel2->Controls->Add(this->btnParking);
			this->panel2->Location = System::Drawing::Point(0, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(177, 741);
			this->panel2->TabIndex = 1;
			// 
			// btnReport
			// 
			this->btnReport->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnReport->FlatAppearance->BorderSize = 0;
			this->btnReport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReport->Location = System::Drawing::Point(0, 547);
			this->btnReport->Name = L"btnReport";
			this->btnReport->Size = System::Drawing::Size(178, 70);
			this->btnReport->TabIndex = 6;
			this->btnReport->Text = L"Report";
			this->btnReport->UseVisualStyleBackColor = false;
			this->btnReport->Click += gcnew System::EventHandler(this, &MainForm::btnReport_Click);
			// 
			// btnFee
			// 
			this->btnFee->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnFee->FlatAppearance->BorderSize = 0;
			this->btnFee->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFee->Location = System::Drawing::Point(2, 471);
			this->btnFee->Name = L"btnFee";
			this->btnFee->Size = System::Drawing::Size(178, 70);
			this->btnFee->TabIndex = 5;
			this->btnFee->Text = L"Fee";
			this->btnFee->UseVisualStyleBackColor = false;
			this->btnFee->Click += gcnew System::EventHandler(this, &MainForm::btnFee_Click);
			// 
			// btnPrkLot
			// 
			this->btnPrkLot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnPrkLot->FlatAppearance->BorderSize = 0;
			this->btnPrkLot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPrkLot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPrkLot->Location = System::Drawing::Point(1, 395);
			this->btnPrkLot->Name = L"btnPrkLot";
			this->btnPrkLot->Size = System::Drawing::Size(178, 70);
			this->btnPrkLot->TabIndex = 4;
			this->btnPrkLot->Text = L"Parking lot";
			this->btnPrkLot->UseVisualStyleBackColor = false;
			this->btnPrkLot->Click += gcnew System::EventHandler(this, &MainForm::btnPrkLot_Click);
			// 
			// btnStaff
			// 
			this->btnStaff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnStaff->FlatAppearance->BorderSize = 0;
			this->btnStaff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStaff->Location = System::Drawing::Point(2, 319);
			this->btnStaff->Name = L"btnStaff";
			this->btnStaff->Size = System::Drawing::Size(178, 70);
			this->btnStaff->TabIndex = 3;
			this->btnStaff->Text = L"Staff";
			this->btnStaff->UseVisualStyleBackColor = false;
			this->btnStaff->Click += gcnew System::EventHandler(this, &MainForm::btnStaff_Click);
			// 
			// btnVehicle
			// 
			this->btnVehicle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnVehicle->FlatAppearance->BorderSize = 0;
			this->btnVehicle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVehicle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVehicle->Location = System::Drawing::Point(1, 243);
			this->btnVehicle->Name = L"btnVehicle";
			this->btnVehicle->Size = System::Drawing::Size(178, 70);
			this->btnVehicle->TabIndex = 2;
			this->btnVehicle->Text = L"Vehicle";
			this->btnVehicle->UseVisualStyleBackColor = false;
			this->btnVehicle->Click += gcnew System::EventHandler(this, &MainForm::btnVehicle_Click);
			// 
			// btnCus
			// 
			this->btnCus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnCus->FlatAppearance->BorderSize = 0;
			this->btnCus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCus->Location = System::Drawing::Point(-1, 167);
			this->btnCus->Name = L"btnCus";
			this->btnCus->Size = System::Drawing::Size(181, 70);
			this->btnCus->TabIndex = 1;
			this->btnCus->Text = L"Customer";
			this->btnCus->UseVisualStyleBackColor = false;
			this->btnCus->Click += gcnew System::EventHandler(this, &MainForm::btnCus_Click);
			// 
			// btnParking
			// 
			this->btnParking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnParking->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnParking->FlatAppearance->BorderSize = 0;
			this->btnParking->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnParking->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnParking->Location = System::Drawing::Point(3, 91);
			this->btnParking->Name = L"btnParking";
			this->btnParking->Size = System::Drawing::Size(173, 70);
			this->btnParking->TabIndex = 0;
			this->btnParking->Text = L"Parking ";
			this->btnParking->UseVisualStyleBackColor = false;
			this->btnParking->Click += gcnew System::EventHandler(this, &MainForm::btnParking_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1333, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L" X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// PnCus
			// 
			this->PnCus->BackColor = System::Drawing::SystemColors::Control;
			this->PnCus->Controls->Add(this->btnAddCus);
			this->PnCus->Controls->Add(this->GB1);
			this->PnCus->Location = System::Drawing::Point(178, 30);
			this->PnCus->Name = L"PnCus";
			this->PnCus->Size = System::Drawing::Size(1200, 700);
			this->PnCus->TabIndex = 43;
			// 
			// btnAddCus
			// 
			this->btnAddCus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnAddCus->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnAddCus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCus->Location = System::Drawing::Point(1107, 27);
			this->btnAddCus->Name = L"btnAddCus";
			this->btnAddCus->Size = System::Drawing::Size(90, 35);
			this->btnAddCus->TabIndex = 1;
			this->btnAddCus->Text = L"Add";
			this->btnAddCus->UseVisualStyleBackColor = false;
			// 
			// GB1
			// 
			this->GB1->Controls->Add(this->dataGridView1);
			this->GB1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GB1->Location = System::Drawing::Point(1, 52);
			this->GB1->Name = L"GB1";
			this->GB1->Size = System::Drawing::Size(1197, 660);
			this->GB1->TabIndex = 0;
			this->GB1->TabStop = false;
			this->GB1->Text = L"All customers";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID, this->Name,
					this->DOB, this->PNumbers, this->nVehicle, this->Balance
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 26);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1191, 631);
			this->dataGridView1->TabIndex = 0;
			// 
			// ID
			// 
			this->ID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 8;
			this->ID->Name = L"ID";
			this->ID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ID->Width = 75;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Name";
			this->Name->MinimumWidth = 8;
			this->Name->Name = L"Name";
			this->Name->Width = 175;
			// 
			// DOB
			// 
			this->DOB->HeaderText = L"Date of Birth";
			this->DOB->MinimumWidth = 8;
			this->DOB->Name = L"DOB";
			this->DOB->Width = 175;
			// 
			// PNumbers
			// 
			this->PNumbers->HeaderText = L"Phone numbers";
			this->PNumbers->MinimumWidth = 8;
			this->PNumbers->Name = L"PNumbers";
			this->PNumbers->Width = 160;
			// 
			// nVehicle
			// 
			this->nVehicle->HeaderText = L"Vehicle";
			this->nVehicle->MinimumWidth = 8;
			this->nVehicle->Name = L"nVehicle";
			this->nVehicle->Width = 75;
			// 
			// Balance
			// 
			this->Balance->HeaderText = L"Balance";
			this->Balance->MinimumWidth = 8;
			this->Balance->Name = L"Balance";
			this->Balance->Width = 70;
			// 
			// PnVehicle
			// 
			this->PnVehicle->BackColor = System::Drawing::SystemColors::Control;
			this->PnVehicle->Controls->Add(this->button2);
			this->PnVehicle->Controls->Add(this->groupBox1);
			this->PnVehicle->Location = System::Drawing::Point(178, 30);
			this->PnVehicle->Name = L"PnVehicle";
			this->PnVehicle->Size = System::Drawing::Size(1200, 700);
			this->PnVehicle->TabIndex = 44;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(1107, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 35);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(1, 52);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1197, 660);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"All vehicles";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->CusID,
					this->PlateNumber, this->Type, this->Term
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(3, 26);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 62;
			this->dataGridView2->RowTemplate->Height = 28;
			this->dataGridView2->Size = System::Drawing::Size(1191, 631);
			this->dataGridView2->TabIndex = 0;
			// 
			// CusID
			// 
			this->CusID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->CusID->HeaderText = L"Owner ID";
			this->CusID->MinimumWidth = 8;
			this->CusID->Name = L"CusID";
			this->CusID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->CusID->Width = 150;
			// 
			// PlateNumber
			// 
			this->PlateNumber->HeaderText = L"Plate Number";
			this->PlateNumber->MinimumWidth = 8;
			this->PlateNumber->Name = L"PlateNumber";
			this->PlateNumber->Width = 220;
			// 
			// Type
			// 
			this->Type->HeaderText = L"Type";
			this->Type->MinimumWidth = 8;
			this->Type->Name = L"Type";
			this->Type->Width = 180;
			// 
			// Term
			// 
			this->Term->HeaderText = L"Term";
			this->Term->MinimumWidth = 8;
			this->Term->Name = L"Term";
			this->Term->Width = 180;
			// 
			// PnStaff
			// 
			this->PnStaff->BackColor = System::Drawing::SystemColors::Control;
			this->PnStaff->Controls->Add(this->button3);
			this->PnStaff->Controls->Add(this->GbStaff);
			this->PnStaff->Location = System::Drawing::Point(178, 30);
			this->PnStaff->Name = L"PnStaff";
			this->PnStaff->Size = System::Drawing::Size(1200, 700);
			this->PnStaff->TabIndex = 45;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(1107, 27);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 35);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Add";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// GbStaff
			// 
			this->GbStaff->Controls->Add(this->dataGridView3);
			this->GbStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GbStaff->Location = System::Drawing::Point(1, 52);
			this->GbStaff->Name = L"GbStaff";
			this->GbStaff->Size = System::Drawing::Size(1197, 660);
			this->GbStaff->TabIndex = 0;
			this->GbStaff->TabStop = false;
			this->GbStaff->Text = L"All staffs";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6
			});
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(3, 26);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 62;
			this->dataGridView3->RowTemplate->Height = 28;
			this->dataGridView3->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView3->Size = System::Drawing::Size(1191, 631);
			this->dataGridView3->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Staff ID";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->Width = 80;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 150;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Date of Birth";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 150;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Phone numbers";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 140;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Identify numbers";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 145;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Type";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 70;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView4);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(1, 52);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1197, 660);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"All parking lots";
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn7,
					this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, this->Avl1, this->dataGridViewTextBoxColumn10, this->Avl2
			});
			this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView4->Location = System::Drawing::Point(3, 26);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 62;
			this->dataGridView4->RowTemplate->Height = 28;
			this->dataGridView4->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView4->Size = System::Drawing::Size(1191, 631);
			this->dataGridView4->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->dataGridViewTextBoxColumn7->HeaderText = L"Parking lot ID";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn7->Width = 120;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"Size";
			this->dataGridViewTextBoxColumn8->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->Width = 50;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"Car slots";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->Width = 120;
			// 
			// Avl1
			// 
			this->Avl1->HeaderText = L"Empty car slots";
			this->Avl1->MinimumWidth = 8;
			this->Avl1->Name = L"Avl1";
			this->Avl1->Width = 130;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"Motorbike slots";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->Width = 160;
			// 
			// Avl2
			// 
			this->Avl2->HeaderText = L"Empty motorbike slot";
			this->Avl2->MinimumWidth = 8;
			this->Avl2->Name = L"Avl2";
			this->Avl2->Width = 190;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(1107, 27);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 35);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Add";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// PnPrkLot
			// 
			this->PnPrkLot->BackColor = System::Drawing::SystemColors::Control;
			this->PnPrkLot->Controls->Add(this->button4);
			this->PnPrkLot->Controls->Add(this->groupBox2);
			this->PnPrkLot->Location = System::Drawing::Point(178, 30);
			this->PnPrkLot->Name = L"PnPrkLot";
			this->PnPrkLot->Size = System::Drawing::Size(1200, 700);
			this->PnPrkLot->TabIndex = 46;
			// 
			// PnFee
			// 
			this->PnFee->BackColor = System::Drawing::SystemColors::Control;
			this->PnFee->Controls->Add(this->button5);
			this->PnFee->Controls->Add(this->groupBox3);
			this->PnFee->Location = System::Drawing::Point(178, 30);
			this->PnFee->Name = L"PnFee";
			this->PnFee->Size = System::Drawing::Size(1200, 700);
			this->PnFee->TabIndex = 47;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(1107, 27);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 35);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Add";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dataGridView5);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(1, 52);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(1197, 660);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"All fee type";
			// 
			// dataGridView5
			// 
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn11,
					this->dataGridViewTextBoxColumn12, this->Description
			});
			this->dataGridView5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView5->Location = System::Drawing::Point(3, 26);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->RowHeadersWidth = 62;
			this->dataGridView5->RowTemplate->Height = 28;
			this->dataGridView5->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView5->Size = System::Drawing::Size(1191, 631);
			this->dataGridView5->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn11
			// 
			this->dataGridViewTextBoxColumn11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->dataGridViewTextBoxColumn11->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn11->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
			this->dataGridViewTextBoxColumn11->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn11->Width = 120;
			// 
			// dataGridViewTextBoxColumn12
			// 
			this->dataGridViewTextBoxColumn12->HeaderText = L"Value";
			this->dataGridViewTextBoxColumn12->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
			this->dataGridViewTextBoxColumn12->Width = 150;
			// 
			// Description
			// 
			this->Description->HeaderText = L"Description";
			this->Description->MinimumWidth = 8;
			this->Description->Name = L"Description";
			this->Description->Width = 460;
			// 
			// PnReport
			// 
			this->PnReport->BackColor = System::Drawing::SystemColors::Control;
			this->PnReport->Controls->Add(this->button6);
			this->PnReport->Controls->Add(this->textBox1);
			this->PnReport->Controls->Add(this->label8);
			this->PnReport->Controls->Add(this->label5);
			this->PnReport->Controls->Add(this->label3);
			this->PnReport->Controls->Add(this->dateTimePicker1);
			this->PnReport->Controls->Add(this->DateStart);
			this->PnReport->Controls->Add(this->tabControl1);
			this->PnReport->Location = System::Drawing::Point(178, 30);
			this->PnReport->Name = L"PnReport";
			this->PnReport->Size = System::Drawing::Size(1200, 700);
			this->PnReport->TabIndex = 48;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button6->Location = System::Drawing::Point(990, 269);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(205, 35);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Save As";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(990, 216);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(207, 26);
			this->textBox1->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(986, 197);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 20);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Result ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(987, 126);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"To";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(987, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"From";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"dd/mm/yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(990, 146);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(207, 26);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// DateStart
			// 
			this->DateStart->CustomFormat = L"dd/mm/yyyy";
			this->DateStart->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->DateStart->Location = System::Drawing::Point(990, 81);
			this->DateStart->Name = L"DateStart";
			this->DateStart->Size = System::Drawing::Size(207, 26);
			this->DateStart->TabIndex = 1;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 32);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(989, 673);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tabPage1->Controls->Add(this->dataGridView6);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(981, 640);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Ticket Report";
			// 
			// dataGridView6
			// 
			this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->IdTicket,
					this->CID, this->Value, this->BillDate
			});
			this->dataGridView6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView6->Location = System::Drawing::Point(3, 3);
			this->dataGridView6->Name = L"dataGridView6";
			this->dataGridView6->RowHeadersWidth = 62;
			this->dataGridView6->RowTemplate->Height = 28;
			this->dataGridView6->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView6->Size = System::Drawing::Size(975, 634);
			this->dataGridView6->TabIndex = 0;
			// 
			// IdTicket
			// 
			this->IdTicket->HeaderText = L"Ticket ID";
			this->IdTicket->MinimumWidth = 8;
			this->IdTicket->Name = L"IdTicket";
			this->IdTicket->Width = 150;
			// 
			// CID
			// 
			this->CID->HeaderText = L"Customer ID";
			this->CID->MinimumWidth = 8;
			this->CID->Name = L"CID";
			this->CID->Width = 150;
			// 
			// Value
			// 
			this->Value->HeaderText = L"Value";
			this->Value->MinimumWidth = 8;
			this->Value->Name = L"Value";
			this->Value->Width = 150;
			// 
			// BillDate
			// 
			this->BillDate->HeaderText = L"Billing Date";
			this->BillDate->MinimumWidth = 8;
			this->BillDate->Name = L"BillDate";
			this->BillDate->Width = 150;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tabPage2->Controls->Add(this->dataGridView7);
			this->tabPage2->Location = System::Drawing::Point(4, 29);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(981, 640);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Customer Report";
			// 
			// dataGridView7
			// 
			this->dataGridView7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView7->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->IDCus,
					this->CusName, this->RegDate, this->NVelcus
			});
			this->dataGridView7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView7->Location = System::Drawing::Point(3, 3);
			this->dataGridView7->Name = L"dataGridView7";
			this->dataGridView7->RowHeadersWidth = 62;
			this->dataGridView7->RowTemplate->Height = 28;
			this->dataGridView7->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView7->Size = System::Drawing::Size(975, 634);
			this->dataGridView7->TabIndex = 0;
			// 
			// IDCus
			// 
			this->IDCus->HeaderText = L"Customer ID";
			this->IDCus->MinimumWidth = 8;
			this->IDCus->Name = L"IDCus";
			this->IDCus->Width = 150;
			// 
			// CusName
			// 
			this->CusName->HeaderText = L"Name";
			this->CusName->MinimumWidth = 8;
			this->CusName->Name = L"CusName";
			this->CusName->Width = 150;
			// 
			// RegDate
			// 
			this->RegDate->HeaderText = L"Resgistration Date";
			this->RegDate->MinimumWidth = 8;
			this->RegDate->Name = L"RegDate";
			this->RegDate->Width = 150;
			// 
			// NVelcus
			// 
			this->NVelcus->HeaderText = L"Vehicle";
			this->NVelcus->MinimumWidth = 8;
			this->NVelcus->Name = L"NVelcus";
			this->NVelcus->Width = 150;
			// 
			// TileLb
			// 
			this->TileLb->AutoSize = true;
			this->TileLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TileLb->Location = System::Drawing::Point(179, 18);
			this->TileLb->Name = L"TileLb";
			this->TileLb->Size = System::Drawing::Size(201, 29);
			this->TileLb->TabIndex = 49;
			this->TileLb->Text = L"Parking Controll";
			// 
			// MainForm
			// 
			this->AccessibleName = L"MainForm";
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1380, 730);
			this->Controls->Add(this->TileLb);
			this->Controls->Add(this->PnReport);
			this->Controls->Add(this->PnFee);
			this->Controls->Add(this->PnPrkLot);
			this->Controls->Add(this->PnStaff);
			this->Controls->Add(this->PnVehicle);
			this->Controls->Add(this->PnCus);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->PnParking);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Location = System::Drawing::Point(300, 100);
			this->Text = L"Parking UI";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->PnParking->ResumeLayout(false);
			this->PnParking->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pltImg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->srcImg1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlateImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcImage))->EndInit();
			this->panel2->ResumeLayout(false);
			this->PnCus->ResumeLayout(false);
			this->GB1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->PnVehicle->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->PnStaff->ResumeLayout(false);
			this->GbStaff->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->PnPrkLot->ResumeLayout(false);
			this->PnFee->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			this->PnReport->ResumeLayout(false);
			this->PnReport->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: char* ConvertStC(System::String^ str)
	{
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		return str2;
	}

	private: System::Void Btn_browse_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dlg = gcnew OpenFileDialog; //^, pronounced "hat" mean that the declared object should be automatically deleted when the system determines that the object is no longer accessible.
		dlg->Filter = "Image (*.bmp; *.jpg; *.jpeg; *.png) |*.bmp; *.jpg; *.jpeg; *.png|All files (*.*)|*.*||";

		if (dlg->ShowDialog() != System::Windows::Forms::DialogResult::Cancel)
		{
			src = cvLoadImage(ConvertStC(dlg->FileName));
			Bitmap^ bmp = gcnew Bitmap(dlg->FileName);
			SrcImage->Image = bmp;
			SrcImage->Refresh();
		}
		PlateFinder pf;
		Function function;
		if (!src)
		{
			MessageBox::Show(L"No image loaded ", "Error", MessageBoxButtons::OK);
			return;
		}

		IplImage* resizeImg = cvCreateImage(cvSize(800, 600), src->depth, src->nChannels);
		cvResize(src, resizeImg);
		std::string strResult;
		IplImage* plateImg, * charImg;
		pf.FindPlate(resizeImg, plateImg, charImg, strResult);
		if (!plateImg)
		{
			MessageBox::Show(L"No plate loaded ", "Error", MessageBoxButtons::OK);
			return;
		}
		IplImage* resizePlate = cvCreateImage(cvSize(240, 50), plateImg->depth, plateImg->nChannels);
		cvResize(plateImg, resizePlate);
		IplImage* resizeCharImg = cvCreateImage(cvSize(240, 50), charImg->depth, charImg->nChannels);
		cvResize(charImg, resizeCharImg);
		PlateImage->Image = gcnew System::Drawing::Bitmap(resizePlate->width, resizePlate->height, resizePlate->widthStep,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) resizePlate->imageData);
		String^ newSystemString = gcnew String(strResult.c_str());
		PNumber->Text = newSystemString;
		cvReleaseImage(&plateImg);
		cvReleaseImage(&resizeImg);
	}
	private: System::Void Btn_recognize_Click(System::Object^ sender, System::EventArgs^ e) {
		PlateFinder pf;
		Function function;
		if (!src)
		{
			MessageBox::Show(L"No image loaded ", "Error", MessageBoxButtons::OK);
			return;
		}

		IplImage* resizeImg = cvCreateImage(cvSize(800, 600), src->depth, src->nChannels);
		cvResize(src, resizeImg);
		std::string strResult;
		IplImage* plateImg, * charImg;
		pf.FindPlate(resizeImg, plateImg, charImg, strResult);
		if (!plateImg)
		{
			MessageBox::Show(L"No plate loaded ", "Error", MessageBoxButtons::OK);
			return;
		}
		IplImage* resizePlate = cvCreateImage(cvSize(240, 50), plateImg->depth, plateImg->nChannels);
		cvResize(plateImg, resizePlate);
		IplImage* resizeCharImg = cvCreateImage(cvSize(240, 50), charImg->depth, charImg->nChannels);
		cvResize(charImg, resizeCharImg);
		PlateImage->Image = gcnew System::Drawing::Bitmap(resizePlate->width, resizePlate->height, resizePlate->widthStep,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) resizePlate->imageData);
		String^ newSystemString = gcnew String(strResult.c_str());
		PNumber->Text = newSystemString;
		cvReleaseImage(&plateImg);
		cvReleaseImage(&resizeImg);
	}
	private: System::Void Label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		PnCus->Visible = false;
		PnFee->Visible = false;
		PnStaff->Visible = false;
		PnReport->Visible = false;
		PnPrkLot->Visible = false;
		PnVehicle->Visible = false;
	}
	private: System::Void Btn_Browse1_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dlg = gcnew OpenFileDialog; //^, pronounced "hat" mean that the declared object should be automatically deleted when the system determines that the object is no longer accessible.
		dlg->Filter = "Image (*.bmp; *.jpg; *.jpeg; *.png) |*.bmp; *.jpg; *.jpeg; *.png|All files (*.*)|*.*||";

		if (dlg->ShowDialog() != System::Windows::Forms::DialogResult::Cancel)
		{
			src1 = cvLoadImage(ConvertStC(dlg->FileName));
			Bitmap^ bmp = gcnew Bitmap(dlg->FileName);
			srcImg1->Image = bmp;
			srcImg1->Refresh();
		}
		// nhan dien bien so
		PlateFinder pf;
		Function function;
		if (!src1)
		{
			MessageBox::Show(L"No image loaded ", "Error", MessageBoxButtons::OK);
			return;
		}

		IplImage* resizeImg = cvCreateImage(cvSize(800, 600), src1->depth, src1->nChannels);
		cvResize(src1, resizeImg);
		std::string strResult;
		IplImage* plateImg, * charImg;
		pf.FindPlate(resizeImg, plateImg, charImg, strResult);
		if (!plateImg)
		{
			MessageBox::Show(L"No plate loaded ", "Error", MessageBoxButtons::OK);
			return;
		}
		IplImage* resizePlate = cvCreateImage(cvSize(240, 50), plateImg->depth, plateImg->nChannels);
		cvResize(plateImg, resizePlate);
		IplImage* resizeCharImg = cvCreateImage(cvSize(240, 50), charImg->depth, charImg->nChannels);
		cvResize(charImg, resizeCharImg);
		pltImg->Image = gcnew System::Drawing::Bitmap(resizePlate->width, resizePlate->height, resizePlate->widthStep,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) resizePlate->imageData);
		String^ newSystemString = gcnew String(strResult.c_str());
		pltNumber->Text = newSystemString;
		cvReleaseImage(&plateImg);
		cvReleaseImage(&resizeImg);
	}
	private: System::Void btn_Recognize1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void PNumber_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnParking_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = true;
		PnCus->Visible = false;
		PnVehicle->Visible = false;
		PnStaff->Visible = false;
		PnPrkLot->Visible = false;
		PnFee->Visible = false;
		PnReport->Visible = false;
		TileLb->Text = L"Parking Controll";
	}
	private: System::Void btnCus_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = false;
		PnCus->Visible = true;
		PnVehicle->Visible = false;
		PnStaff->Visible = false;
		PnPrkLot->Visible = false;
		PnFee->Visible = false;
		PnReport->Visible = false;
		TileLb->Text = L"Customer Management";

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnVehicle_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = false;
		PnCus->Visible = false;
		PnVehicle->Visible = true;
		PnStaff->Visible = false;
		PnPrkLot->Visible = false;
		PnFee->Visible = false;
		PnReport->Visible = false;
		TileLb->Text = L"Vehicle Management";

	}
	private: System::Void btnStaff_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = false;
		PnCus->Visible = false;
		PnVehicle->Visible = false;
		PnStaff->Visible = true;
		PnPrkLot->Visible = false;
		PnFee->Visible = false;
		PnReport->Visible = false;
		TileLb->Text = L"Staff Management";

	}
	private: System::Void btnPrkLot_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = false;
		PnCus->Visible = false;
		PnVehicle->Visible = false;
		PnStaff->Visible = false;
		PnPrkLot->Visible = true;
		PnFee->Visible = false;
		PnReport->Visible = false;
		TileLb->Text = L"Parking lot Management";

	}
	private: System::Void btnFee_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = false;
		PnCus->Visible = false;
		PnVehicle->Visible = false;
		PnStaff->Visible = false;
		PnPrkLot->Visible = false;
		PnFee->Visible = true;
		PnReport->Visible = false;
		TileLb->Text = L"Fee type Management";
	}
	private: System::Void btnReport_Click(System::Object^ sender, System::EventArgs^ e) {
		PnParking->Visible = false;
		PnCus->Visible = false;
		PnVehicle->Visible = false;
		PnStaff->Visible = false;
		PnPrkLot->Visible = false;
		PnFee->Visible = false;
		PnReport->Visible = true;
		TileLb->Text = L"Report";
	}
	};
}
