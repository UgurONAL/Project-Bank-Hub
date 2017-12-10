
#include "MenuForm.h";
#include "mysql\include\mysql.h"
#include "msclr\marshal_cppstd.h"
#include "AdminMenuForm.h"

#include <string>
#include <string.h>


namespace BankHub {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserLogin
	/// </summary>
	public ref class UserLogin : public System::Windows::Forms::Form
	{
	public:
		UserLogin(void)
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
		~UserLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  TextBox1;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
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
			this->TextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TextBox1
			// 
			this->TextBox1->Location = System::Drawing::Point(88, 56);
			this->TextBox1->Name = L"TextBox1";
			this->TextBox1->Size = System::Drawing::Size(100, 20);
			this->TextBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(88, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 146);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"LogIn";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserLogin::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"TC";
			this->label1->Click += gcnew System::EventHandler(this, &UserLogin::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password";
			// 
			// UserLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->TextBox1);
			this->Name = L"UserLogin";
			this->Text = L"UserLogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ tc = TextBox1->Text;
		String^ pass = textBox2->Text;

		msclr::interop::marshal_context context;
		std::string tcStr = context.marshal_as<std::string>(tc);
		msclr::interop::marshal_context context2;
		std::string passStr = context2.marshal_as<std::string>(pass);

		if (tcStr == "00000000000" && passStr == "admin") {
			AdminMenuForm^ adminmenu = gcnew AdminMenuForm();
			adminmenu->Show();
			this->Hide();
		}else {

			MenuForm ^ menuForm = gcnew MenuForm();

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL_ROW row;
			MYSQL *conn;
			int sorgu;

			std::string sql = "SELECT passwords, id FROM users WHERE citizenship_no = ";
			sql += tcStr;

			mysql = mysql_init(NULL);
			conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);
			//conn = mysql_real_connect(mysql, "mysql.itu.edu.tr", "kurtbu", "q8VPBFHRg6", "kurtbu", 0, NULL, 0);
			//conn = mysql_real_connect(mysql, "srv.digitaltrade.com.tr:8080/dtmyadmin", "bunyaminkurt", "bunyamin*123", "bunyaminkurt", 0, NULL, 0);

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);
			row = mysql_fetch_row(result);

			if (row == NULL) {
				MessageBox::Show("Girilen TC ile kayýtlý bir kullanýcý bulunmamaktadýr.", "LogIn", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				char *passSql = row[0];
				std::string abc = passSql;

				char *id = row[1];
				std::string _id = id;
				std::string sql2 = "UPDATE login SET id = ";
				sql2 += _id;
				sorgu = mysql_query(conn, sql2.c_str());

				if (abc == passStr) {
					menuForm->Show();
					this->Hide();
				}
				else {
					MessageBox::Show("Hatalý Giriþ. Tekrar Deneyiniz.", "LogIn", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}
};
}
