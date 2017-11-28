#ifndef PAYMENT_CLASS
#define PAYMENT_CLASS

#include <iostream>

using namespace std;

class Payment {
private:
	int id;
	int userID;
	string name;
	double amount;
public:
	Payment() : id(-1), userID(-1), name(""), amount(0) {};
	Payment(const int id, const int userID, const string name, const double amount) : id(id), userID(userID), name(name), amount(amount) {};
	void setName(const string);
	const string & getName();
	void setID(const int);
	const int & getID();
	void setUserID(const int);
	const int & getUserID();
	void setAmount(const double);
	const double & getAmount();
};

#endif // !PAYMENT_CLASS