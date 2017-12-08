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
	/// Summary for OpenAccountForm
	/// </summary>
	public ref class OpenAccountForm : public System::Windows::Forms::Form
	{
	public:
		OpenAccountForm(void)
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
		~OpenAccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(96, 52);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL_ROW row;
			MYSQL *conn;
			int sorgu;

			

			mysql = mysql_init(NULL);
			conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

			std::string sql2 = "SELECT name FROM banks";
			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);
			
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				char *a = row[0];
				std::string _a = a;
				String^ as = gcnew String(_a.c_str());
				this->comboBox1->Items->Add(as);
			}


			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Banka:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(111, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Hesap Aç";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &OpenAccountForm::button1_Click);
			// 
			// OpenAccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"OpenAccountForm";
			this->Text = L"OpenAccountForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ bank = comboBox1->Text;

		msclr::interop::marshal_context context;
		std::string _bank = context.marshal_as<std::string>(bank);

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

		sql = "SELECT id FROM banks WHERE name = '";
		sql += _bank;
		sql += "'";

		sorgu = mysql_query(conn, sql.c_str());
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		if (row == NULL) {
			MessageBox::Show("Ýþleminiz gerçekleþtirilemiyor...", "OpenAccount");
		}else {
			char *bankid = row[0];
			std::string _bankid = bankid;

			std::string sql2 = "INSERT INTO accounts (id, user_id, balance, bank_id, currency) VALUES(NULL,";
			sql2 += _id;
			sql2 += ",0,";
			sql2 += _bankid;
			sql2 += ",'TRY')";

			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);

			MessageBox::Show("Hesabýnýz açýlmýþtýr.", "OpenAccount");
			this->Hide();
		}	
		
	}
	};
}
