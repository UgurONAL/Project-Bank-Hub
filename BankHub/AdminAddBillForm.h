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
	/// Summary for AdminAddBillForm
	/// </summary>
	public ref class AdminAddBillForm : public System::Windows::Forms::Form
	{
	public:
		AdminAddBillForm(void)
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
		~AdminAddBillForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(85, 45);
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

			std::string sql = "SELECT id,name FROM users WHERE citizenship_no != 00000000000 ORDER BY id";

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				char *a = row[0];
				std::string _a = a;
				char *b = row[1];
				std::string _b = b;
				_a += " - ";
				_a += _b;
				String^ as = gcnew String(_a.c_str());
				this->comboBox1->Items->Add(as);
				i++;
			}

			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(85, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(85, 99);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ekle";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminAddBillForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Kullanýcý";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Açýklama";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(43, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Miktar";
			// 
			// AdminAddBillForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"AdminAddBillForm";
			this->Text = L"AdminAddBillForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ id = comboBox1->Text;
		String^ desc = textBox1->Text;
		String^ miktar = textBox2->Text;

		msclr::interop::marshal_context context;
		std::string _userid = context.marshal_as<std::string>(id);
		msclr::interop::marshal_context context2;
		std::string _desc = context2.marshal_as<std::string>(desc);
		msclr::interop::marshal_context context3;
		std::string _miktar = context3.marshal_as<std::string>(miktar);

		if (_desc.length() == 0 || _miktar.length() == 0) {
			MessageBox::Show("Tüm alanlarýn Dolu olmasý gerekmektedir.");
		}
		else {
			char _cc = _userid[0];
			int uID = (int)_cc;

			//float _m = std::stof(_miktar);

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL *conn;
			int sorgu;

			mysql = mysql_init(NULL);
			conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

			std::string sql = "INSERT INTO loans (id,user_id,type,amount,currency) VALUES (NULL,";
			sql += uID;
			sql += ",'";
			sql += _desc;
			sql += "',";
			sql += _miktar;
			sql += ",'TRY')";

			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);

			String^ aa = gcnew String(sql.c_str());
			MessageBox::Show(aa);
			MessageBox::Show("Fatura eklenmiþtir.");
			this->Hide();

		}
	}
};
}
