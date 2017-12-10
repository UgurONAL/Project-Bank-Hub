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
	/// Summary for AdminUserForm
	/// </summary>
	public ref class AdminUserForm : public System::Windows::Forms::Form
	{
	public:
		AdminUserForm(void)
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
		~AdminUserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
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
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column5, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 27);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(625, 150);
			this->dataGridView1->TabIndex = 0;

			MYSQL *mysql;
			MYSQL_RES *result;
			MYSQL_ROW row;
			MYSQL *conn;
			int sorgu;

			std::string sql = "SELECT id, name, citizenship_no, phone, address FROM users WHERE citizenship_no != 00000000000";
			
			mysql = mysql_init(NULL);
			conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);
			
			sorgu = mysql_query(conn, sql.c_str());
			result = mysql_store_result(conn);

			int i = 0;
			while ((row = mysql_fetch_row(result)) != NULL) // Eðer veritabanýndan bilgi gelmiþse
			{
				this->dataGridView1->Rows->Add();
				for (size_t j = 0; j < 5; j++) {
					char *a = row[j];
					std::string _a = a;
					String^ as = gcnew String(_a.c_str());
					this->dataGridView1->Rows[i]->Cells[j]->Value = as;
				}
				i++;
			}

			// 
			// Column1
			// 
			this->Column1->HeaderText = L"User ID";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 80;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ýsim";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"TC";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Telefon";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Adres";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 200;
			// 
			// AdminUserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(667, 261);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"AdminUserForm";
			this->Text = L"AdminUserForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
