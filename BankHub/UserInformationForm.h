#include "mysql\include\mysql.h"
#include "msclr\marshal_cppstd.h"

namespace BankHub {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserInformationForm
	/// </summary>
	public ref class UserInformationForm : public System::Windows::Forms::Form
	{
	public:
		UserInformationForm(void)
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
		~UserInformationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(100, 70);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(126, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(100, 107);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(126, 20);
			this->textBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(116, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Profil Bilgileri";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(54, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Ýsim";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Vatandaþlýk No";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(49, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Telefon";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(100, 140);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(126, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(100, 175);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(126, 59);
			this->textBox4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(54, 178);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Adres";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(119, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Güncelle";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserInformationForm::button1_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(100, 241);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(126, 20);
			this->textBox5->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(66, 244);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Þifre";
			// 
			// UserInformationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(310, 306);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"UserInformationForm";
			this->Text = L"UserInformationForm";
			this->Load += gcnew System::EventHandler(this, &UserInformationForm::UserInformationForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserInformationForm_Load(System::Object^  sender, System::EventArgs^  e) {
		MYSQL *mysql;
		MYSQL_RES *result;
		MYSQL_ROW row;
		MYSQL *conn;
		int sorgu;

		std::string sql = "SELECT id FROM login";

		char* host = "db4free.net";
		char* user = "bjwlf";
		char* dbpassword = "linksys";
		char* db = "bankhub";
		int port = 3307;

		mysql = mysql_init(NULL);
		conn = mysql_real_connect(mysql, host, user, dbpassword, db, port, NULL, 0);
		//conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);
		
		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		char *id = row[0];
		std::string _id = id;

		sql = "SELECT name, citizenship_no, phone, address, passwords FROM users WHERE id =";
		sql += _id;

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		char *name = row[0];
		std::string _name = name;
		char *tc = row[1];
		std::string _tc = tc;
		char *phone = row[2];
		std::string _phone = phone;
		char *adress = row[3];
		std::string _adress = adress;
		char *pass = row[4];
		std::string _pass = pass;

		String^ a = gcnew String(_name.c_str());
		textBox1->Text = a;
		String^ b = gcnew String(_tc.c_str());
		textBox2->Text = b;
		String^ c = gcnew String(_phone.c_str());
		textBox3->Text = c;
		String^ d = gcnew String(_adress.c_str());
		textBox4->Text = d;
		String^ passwords = gcnew String(_pass.c_str());
		textBox5->Text = passwords;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ phone = textBox3->Text;
		String^ address = textBox4->Text;
		String^ pass = textBox5->Text;

		msclr::interop::marshal_context context;
		std::string _phone = context.marshal_as<std::string>(phone);
		msclr::interop::marshal_context context2;
		std::string _address = context2.marshal_as<std::string>(address);
		msclr::interop::marshal_context context3;
		std::string _pass = context3.marshal_as<std::string>(pass);

		MYSQL *mysql;
		MYSQL_RES *result;
		MYSQL_ROW row;
		MYSQL *conn;
		int sorgu;

		std::string sql = "SELECT id FROM login";

		char* host = "db4free.net";
		char* user = "bjwlf";
		char* dbpassword = "linksys";
		char* db = "bankhub";
		int port = 3307;

		mysql = mysql_init(NULL);
		conn = mysql_real_connect(mysql, host, user, dbpassword, db, port, NULL, 0);
		//conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		char *id = row[0];
		std::string _id = id;

		sql = "UPDATE users SET phone = ";
		sql += _phone;
		sql += " ,";
		sql += " passwords = '";
		sql += _pass;
		sql += "', address = '";
		sql += _address;
		sql += "' WHERE id = ";
		sql += _id;

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);

		MessageBox::Show("Profiliniz Güncellenmiþtir.");
		this->Hide();

	}
};
}
