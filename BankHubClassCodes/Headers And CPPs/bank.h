#ifndef BANK_CLASS
#define BANK_CLASS

#include <iostream>

using namespace std;

class Bank {
private:
	int id;
	string name;
public:
	Bank() : id(-1), name("") {};
	Bank(const int id, const string name) : id(id), name(name) {};
	void setName(const string);
	const string & getName();
	void setID(const int);
	const int & getID();
};

#endif // !BANK_CLASS