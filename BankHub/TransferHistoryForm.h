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
	/// Summary for TransferHistoryForm
	/// </summary>
	public ref class TransferHistoryForm : public System::Windows::Forms::Form
	{
	public:
		TransferHistoryForm(void)
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
		~TransferHistoryForm()
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




	protected:

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(519, 150);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TransferHistoryForm::dataGridView1_CellContentClick);
			
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

			std::string sql2 = "SELECT from_account_no, destination_account_no, amount, created_at, bill FROM transactions WHERE user_id = ";
			sql2 += _id;
			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				this->dataGridView1->Rows->Add();
				for (size_t j = 0; j < 4; j++)
				{

					if (j == 2) {
						char *a = row[j];
						std::string _a = a;
						_a += " TL";
						String^ as = gcnew String(_a.c_str());
						this->dataGridView1->Rows[i]->Cells[j]->Value = as;
					}else {
						char *a = row[j];
						std::string _a = a;

						if (_a == "0") {
							char *x = row[4];
							std::string _x = x;
							String^ as = gcnew String(_x.c_str());
							this->dataGridView1->Rows[i]->Cells[j]->Value = as;

						}else {
							String^ as = gcnew String(_a.c_str());
							this->dataGridView1->Rows[i]->Cells[j]->Value = as;
						}
					}					
				}
				i++;
			}
			
			
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"GönderenHesap";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Alýcý Hesap";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Miktar";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Ýþlem Tarihi";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 175;
			// 
			// TransferHistoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 261);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"TransferHistoryForm";
			this->Text = L"TransferHistoryForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	};
}
