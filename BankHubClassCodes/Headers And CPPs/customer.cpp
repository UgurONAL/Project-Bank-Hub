#include <iostream>
#include "customer.h"

using namespace std;

Customer::Customer(const int id, const int age, const string name, const string citizenshipNo, const string password, const Account & bankAccount, const Payment & payment) {
	bankAccounts.push_back(bankAccount);
	payments.push_back(payment);
}
void Customer::addBankAccount(const Account newBankAccount) {
	bankAccounts.push_back(newBankAccount);
}
const vector<Account> & Customer::getBankAccounts() {
	return bankAccounts;
}
void Customer::addPayment(const Payment newPayment) {
	payments.push_back(newPayment);
}
const vector<Payment> & Customer::getPayments() {
	return payments;
}