#include <iostream>
#include "account.h"

using namespace std;

const int & Account::getAccountID() {
	return accountID;
}
const Bank & Account::getBank() {
	return bank;
}
void Account::setAccountID(const int newAccountID) {
	accountID = newAccountID;
}
void Account::setBank(const Bank & newBankID) {
	bank = newBankID;
}
void Account::setBalance(const int newBalance) {
	balance = newBalance;
}
const double & Account::getBalance() {
	return balance;
}