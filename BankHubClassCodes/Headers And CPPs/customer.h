#ifndef CUSTOMER_CLASS
#define CUSTOMER_CLASS

#include <iostream>
#include <vector>
#include "person.h"
#include "bank.h"
#include "account.h"
#include "payment.h"

using namespace std;

class Customer : public Person{
private:
	vector<Account> bankAccounts;
	vector<Payment> payments;
public:
	Customer() : Person() {};
	Customer(const int id, const int age, const string name, const string citizenshipNo, const string password) : Person(id, age, name, citizenshipNo, password) {};
	Customer(const int id, const int age, const string name, const string citizenshipNo, const string password, const Account & bankAccount, const Payment & payment) :
		Person(id, age, name, citizenshipNo, password) {};
	void addBankAccount(const Account);
	const vector<Account> & getBankAccounts();
	void addPayment(const Payment);
	const vector<Payment> & getPayments();
};

#endif // !CUSTOMER_CLASS