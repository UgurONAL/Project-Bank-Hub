
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
	/// Summary for PayBillForm
	/// </summary>
	public ref class PayBillForm : public System::Windows::Forms::Form
	{
	public:
		PayBillForm(void)
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
		~PayBillForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(94, 48);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL_ROW row;
			MYSQL *conn;
			int sorgu;

			std::string sql = "SELECT id FROM login";

			mysql = mysql_init(NULL);
			conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);
			row = mysql_fetch_row(result);

			char *id = row[0];
			std::string _id = id;

			sql = "SELECT id, type, amount FROM loans WHERE user_id =";
			sql += _id;

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);
			//row = mysql_fetch_row(result);

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{

				char *c = row[0];
				std::string _c = c;
				char *a = row[1];
				std::string _a = a;
				char *b = row[2];
				std::string _b = b;
				_c += " - ";
				_c += _a;
				_c += " - ";	
				_c += _b;
				_c += " TL";
				

				String^ as = gcnew String(_c.c_str());
				this->comboBox1->Items->Add(as);
				
				i++;
			}


			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Fatura:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(94, 97);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 2;

			sql = "SELECT a.id, a.balance, b.name FROM accounts a JOIN banks b ON a.bank_id = b.id WHERE a.user_id =";
			sql += _id;

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);
			//row = mysql_fetch_row(result);

			i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				char *a = row[0];
				std::string _a = a;
				char *b = row[1];
				std::string _b = b;
				char *c = row[2];
				std::string _c = c;
				_a += " - ";
				_a += _b;
				_a += " TL - ";
				_a += _c;

				String^ as = gcnew String(_a.c_str());
				this->comboBox2->Items->Add(as);
				
				i++;
			}

			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(47, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Hesap:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(108, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Fatura Öde";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PayBillForm::button1_Click);
			// 
			// PayBillForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"PayBillForm";
			this->Text = L"PayBillForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ c = comboBox1->SelectedItem->ToString();
		String^ c2 = comboBox2->SelectedItem->ToString();
		int a = comboBox1->SelectedIndex;

		msclr::interop::marshal_context context;
		std::string _c = context.marshal_as<std::string>(c);
		msclr::interop::marshal_context context2;
		std::string _c2 = context2.marshal_as<std::string>(c2);
		char _cc = _c2[0];
		int accountid = (int)_cc;

		char _billid = _c[0];
		int billid = (int)_billid;

		MYSQL *mysql;
		MYSQL_RES *result;
		MYSQL_ROW row;
		MYSQL *conn;
		int sorgu;

		std::string sql = "SELECT id FROM login";

		mysql = mysql_init(NULL);
		conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		char *id = row[0];
		std::string _id = id;

		sql = "SELECT amount FROM loans WHERE id=";
		sql += billid;

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		std::string billamount = row[0];

		sql = "SELECT balance FROM accounts WHERE id=";
		sql += accountid;

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		std::string balance = row[0];

		if (std::atoi(billamount.c_str()) > std::atoi(balance.c_str()) ) {
			MessageBox::Show("Hesabýnýzda yeterli para bulunmamaktadýr.");
		}else {

			std::string sql2 = "UPDATE accounts SET balance = balance - ";
			sql2 += billamount;
			sql2 += " WHERE id=";
			sql2 += accountid;

			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);
			//row = mysql_fetch_row(result);

			sql2 = "DELETE FROM loans WHERE id=";
			sql2 += billid;

			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);

			MessageBox::Show("Faturanýz ödenmiþtir.");
			this->Hide();
		}


	}
};
}
