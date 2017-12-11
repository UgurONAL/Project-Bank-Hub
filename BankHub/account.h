#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <iostream>
#include "bank.h"

using namespace std;

class Account {
private:
	int accountID;
	double balance;
	Bank bank;
public:
	Account() : accountID(-1), balance(0) {};
	Account(const int newAccountID, const double balance, const Bank & bankID = Bank()) : accountID(newAccountID), balance(balance), bank(bankID) {};
	void setAccountID(const int);
	const int & getAccountID();
	void setBank(const Bank &);
	const Bank & getBank();
	void setBalance(const int);
	const double & getBalance();
};

#endif // !ACCOUNT_CLASS