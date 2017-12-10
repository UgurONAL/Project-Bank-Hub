#include "mysql\include\mysql.h"
#include "msclr\marshal_cppstd.h"
#include <string>

namespace BankHub {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminUserAddForm
	/// </summary>
	public ref class AdminUserAddForm : public System::Windows::Forms::Form
	{
	public:
		AdminUserAddForm(void)
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
		~AdminUserAddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  Ýsim;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Ýsim = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(95, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(95, 79);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(95, 106);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(95, 133);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 3;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(95, 160);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 186);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Ekle";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminUserAddForm::button1_Click);
			// 
			// Ýsim
			// 
			this->Ýsim->AutoSize = true;
			this->Ýsim->Location = System::Drawing::Point(54, 55);
			this->Ýsim->Name = L"Ýsim";
			this->Ýsim->Size = System::Drawing::Size(25, 13);
			this->Ýsim->TabIndex = 6;
			this->Ýsim->Text = L"Ýsim";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(54, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"TC";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(54, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Þifre";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(46, 136);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Telefon";
			this->label4->Click += gcnew System::EventHandler(this, &AdminUserAddForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(54, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Adres";
			// 
			// AdminUserAddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Ýsim);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"AdminUserAddForm";
			this->Text = L"AdminUserAddForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ ad = textBox1->Text;
		String^ tc = textBox2->Text;
		String^ pass = textBox3->Text;
		String^ tel = textBox4->Text;
		String^ address = textBox5->Text;

		msclr::interop::marshal_context context;
		std::string _ad = context.marshal_as<std::string>(ad);
		msclr::interop::marshal_context context2;
		std::string _tc = context2.marshal_as<std::string>(tc);
		msclr::interop::marshal_context context3;
		std::string _pass = context3.marshal_as<std::string>(pass);
		msclr::interop::marshal_context context4;
		std::string _tel = context4.marshal_as<std::string>(tel);
		msclr::interop::marshal_context context5;
		std::string _address = context5.marshal_as<std::string>(address);

		if (_ad.length() == 0 || _tc.length() == 0 || _pass.length() == 0 || _tel.length() == 0 || _address.length() == 0) {
			MessageBox::Show("Tüm alanlarýn Dolu olmasý gerekmektedir.");
		}else {

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL *conn;
			int sorgu;

			std::string sql = "INSERT INTO users (id,name,citizenship_no,passwords,phone,address) VALUES (NULL,'";
			sql += _ad;
			sql += "','";
			sql += _tc;
			sql += "','";
			sql += _pass;
			sql += "','";
			sql += _tel;
			sql += "','";
			sql += _address;
			sql += "')";

			mysql = mysql_init(NULL);
			conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);

			MessageBox::Show("Kullanýcý Eklenmiþtir.");
			this->Hide();

		}

	}
};
}
