#pragma once

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
			
			// Data grid verileri burada doldur...
			for (size_t i = 0; i < 4; i++)
			{
				this->dataGridView1->Rows->Add();
				for (size_t j = 0; j < 3; j++)
				{
					this->dataGridView1->Rows[i]->Cells[j]->Value = "Ali";
				}
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
			this->Bank_no->HeaderText = L"Banka";
			this->Bank_no->Name = L"Bank_no";
			this->Bank_no->ReadOnly = true;
			// 
			// amount
			// 
			this->amount->HeaderText = L"Bakiye";
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
