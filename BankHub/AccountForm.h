
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
	/// Summary for AccountForm
	/// </summary>
	public ref class AccountForm : public System::Windows::Forms::Form
	{
	public:
		AccountForm(void)
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
		~AccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  hesap_no;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Bank_no;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  amount;
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
			this->hesap_no = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Bank_no = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->hesap_no,
					this->Bank_no, this->amount
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(345, 150);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AccountForm::dataGridView1_CellContentClick);

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

			std::string sql2 = "SELECT a.id, a.balance, b.name FROM accounts a JOIN banks b ON a.bank_id = b.id WHERE a.user_id =";
			sql2 += _id;
			sorgu = mysql_query(conn, sql2.c_str());
			result = mysql_store_result(conn);
			//row = mysql_fetch_row(result);

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				this->dataGridView1->Rows->Add();
				for (size_t j = 0; j < 3; j++)
				{
					if (j == 1) {
						char *a = row[j];
						std::string _a = a;
						_a += " TL";
						String^ as = gcnew String(_a.c_str());
						this->dataGridView1->Rows[i]->Cells[j]->Value = as;
					}else {
						char *a = row[j];
						std::string _a = a;
						String^ as = gcnew String(_a.c_str());
						this->dataGridView1->Rows[i]->Cells[j]->Value = as;
					}

				}
				i++;
			}
			
			// 
			// hesap_no
			// 
			this->hesap_no->HeaderText = L"Hesap No";
			this->hesap_no->Name = L"hesap_no";
			this->hesap_no->ReadOnly = true;
			// 
			// Bank_no
			// 
			this->Bank_no->HeaderText = L"Bakiye";
			this->Bank_no->Name = L"Bank_no";
			this->Bank_no->ReadOnly = true;
			// 
			// amount
			// 
			this->amount->HeaderText = L"Banka";
			this->amount->Name = L"amount";
			this->amount->ReadOnly = true;
			// 
			// AccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(433, 280);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"AccountForm";
			this->Text = L"AccountForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	};
}
