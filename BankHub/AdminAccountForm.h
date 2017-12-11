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
	/// Summary for AdminAccountForm
	/// </summary>
	public ref class AdminAccountForm : public System::Windows::Forms::Form
	{
	public:
		AdminAccountForm(void)
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
		~AdminAccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(447, 206);
			this->dataGridView1->TabIndex = 0;

			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(178, 235);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL_ROW row;
			MYSQL *conn;
			int sorgu;

			std::string sql = "SELECT a.id,u.name,a.balance,b.name FROM accounts a JOIN users u ON a.user_id = u.id JOIN banks b On a.bank_id = b.id ORDER BY a.id";

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

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				this->dataGridView1->Rows->Add();
				for (size_t j = 0; j < 4; j++) {
					char *a = row[j];
					std::string _a = a;
					String^ as = gcnew String(_a.c_str());

					if (j == 0) {
						this->comboBox1->Items->Add(as);
					}
					
					this->dataGridView1->Rows[i]->Cells[j]->Value = as;
				}
				i++;
			}

			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Hesap No";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Hesap Sahibi";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Bakiye";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Banka";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			



			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 262);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Hesabý Sil";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminAccountForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(117, 238);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Hesap No";
			// 
			// AdminAccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 315);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"AdminAccountForm";
			this->Text = L"AdminAccountForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ accNo = comboBox1->Text;

		msclr::interop::marshal_context context;
		std::string _accNo = context.marshal_as<std::string>(accNo);

		MYSQL *mysql;
		MYSQL_RES *result;
		MYSQL *conn;
		int sorgu;

		char* host = "db4free.net";
		char* user = "bjwlf";
		char* dbpassword = "linksys";
		char* db = "bankhub";
		int port = 3307;

		mysql = mysql_init(NULL);
		conn = mysql_real_connect(mysql, host, user, dbpassword, db, port, NULL, 0);
		//conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);

		std::string sql2 = "DELETE FROM accounts WHERE id =";
		sql2 += _accNo;

		sorgu = mysql_query(conn, sql2.c_str());
		result = mysql_store_result(conn);

		std::string msg = _accNo;
		msg += " numaralý hesap silinmiþtir.";
		String^ _msg = gcnew String(msg.c_str());
		MessageBox::Show(_msg);
		this->Hide();
	}
};
}
