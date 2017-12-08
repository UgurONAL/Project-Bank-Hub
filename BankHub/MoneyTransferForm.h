
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
	/// Summary for MoneyTransferForm
	/// </summary>
	public ref class MoneyTransferForm : public System::Windows::Forms::Form
	{
	public:
		MoneyTransferForm(void)
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
		~MoneyTransferForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(203, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Para Transferi Yap!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(108, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Hesap No (From)";
			this->label2->Click += gcnew System::EventHandler(this, &MoneyTransferForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(201, 123);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(118, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Hesap No (To)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(201, 161);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(215, 201);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Transfer Et";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MoneyTransferForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(159, 164);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Miktar";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(201, 83);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MoneyTransferForm::comboBox1_SelectedIndexChanged);
			

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

			std::string sql2 = "SELECT id FROM accounts WHERE user_id =";
			sql2 += _id;
			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				char *a = row[0];
				std::string _a = a;
				String^ as = gcnew String(_a.c_str());
				this->comboBox1->Items->Add(as);
				i++;
			}
			
			// 
			// MoneyTransferForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 292);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MoneyTransferForm";
			this->Text = L"MoneyTransferForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ fromNo = comboBox1->Text;
		String^ toNo = textBox2->Text;
		String^ miktar = textBox3->Text;

		msclr::interop::marshal_context context;
		std::string _fromNo = context.marshal_as<std::string>(fromNo);
		msclr::interop::marshal_context context2;
		std::string _toNo = context2.marshal_as<std::string>(toNo);
		msclr::interop::marshal_context context3;
		std::string _miktar = context3.marshal_as<std::string>(miktar);

		MYSQL *mysql;
		MYSQL_RES *result;
		MYSQL_ROW row;
		MYSQL *conn;
		int sorgu;

		mysql = mysql_init(NULL);
		conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

		std::string sql2 = "SELECT balance FROM accounts WHERE id=";
		sql2 += _fromNo;

		sorgu = mysql_query(conn, sql2.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		char *balance = row[0];
		std::string _balance = balance;

		int m = atoi(_miktar.c_str());
		int b = atoi(_balance.c_str());

		std::string sql3 = "SELECT id FROM accounts WHERE id=";
		sql3 += _toNo;

		sorgu = mysql_query(conn, sql3.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		if (row == NULL) {
			MessageBox::Show("Gönderilecek hesap numarasý bulunmamaktadýr.", "MoneyTransfer", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			if (m > b) {
				MessageBox::Show("Bu hesapta yeterli para bulunmamaktadýr.", "MoneyTransfer", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				std::string sql4 = "UPDATE accounts SET balance=balance-";
				sql4 += _miktar;
				sql4 += " WHERE id=";
				sql4 += _fromNo;

				sorgu = mysql_query(conn, sql4.c_str());
				result = mysql_store_result(conn);

				sql4 = "UPDATE accounts SET balance=balance+";
				sql4 += _miktar;
				sql4 += " WHERE id=";
				sql4 += _toNo;

				sorgu = mysql_query(conn, sql4.c_str());
				result = mysql_store_result(conn);


				std::string sql5 = "SELECT id FROM login";

				sorgu = mysql_query(conn, sql5.c_str());
				result = mysql_store_result(conn);
				row = mysql_fetch_row(result);

				char *id = row[0];
				std::string _id = id;

				sql4 = "INSERT INTO transactions (id,user_id, from_account_no, destination_account_no, amount, created_at) VALUES (NULL,";
				sql4 += _id;
				sql4 += ",";
				sql4 += _fromNo;
				sql4 += ",";
				sql4 += _toNo;
				sql4 += ",";
				sql4 += _miktar;
				sql4 += ",";
				sql4 += "NOW())";

				sorgu = mysql_query(conn, sql4.c_str());
				result = mysql_store_result(conn);

				MessageBox::Show("Para Transferi Gerçekleþtirildi.");
				this->Hide();
			}
		}	

	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
