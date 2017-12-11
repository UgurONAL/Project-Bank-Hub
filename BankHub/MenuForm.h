
#include "AccountForm.h"
#include "UserInformationForm.h"
#include "MoneyTransferForm.h"
#include "OpenAccountForm.h"
#include "TransferHistoryForm.h"
#include "PayBillForm.h"

namespace BankHub {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
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
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 117);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Hoþgeldiniz";
			this->label1->Click += gcnew System::EventHandler(this, &MenuForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(88, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Hesaplarým";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(88, 173);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Tranfer Yap";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(88, 202);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Fatura Öde";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(88, 231);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Bilgilerim";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(88, 260);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Hesap Aç";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MenuForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(88, 318);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(104, 23);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Çýkýþ";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(88, 289);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(104, 23);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Transfer Geçmiþi";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MenuForm::button7_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(88, 26);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 70);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 370);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		AccountForm ^ accountForm = gcnew AccountForm();
		accountForm->Show();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		UserInformationForm^ userInfoForm = gcnew UserInformationForm();
		userInfoForm->Show();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		MoneyTransferForm^ moneyTransferForm = gcnew MoneyTransferForm();
		moneyTransferForm->Show();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenAccountForm^ openAccountForm = gcnew OpenAccountForm();
		openAccountForm->Show();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		TransferHistoryForm^ tarnsfer = gcnew TransferHistoryForm();
		tarnsfer->Show();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		PayBillForm^ payBillForm = gcnew PayBillForm();
		payBillForm->Show();
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
