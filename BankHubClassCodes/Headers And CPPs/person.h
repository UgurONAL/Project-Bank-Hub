#ifndef PERSON_CLASS
#define PERSON_CLASS

#include <iostream>

using namespace std;

class Person {
private:
	int id;
	int age;
	string name;
	string citizenshipNo;
	string password;
public:
	Person() : id(-1), age(-1), name(""), citizenshipNo(""), password("") {};
	Person(const int id, const int age, const string name, const string citizenshipNo, const string password) : 
		id(id), age(age), name(name), citizenshipNo(citizenshipNo), password(password) {};
	void setName(const string);
	const string & getName();
	void setID(const int);
	const int & getID();
	void setPassword(const string);
	const string & getPassword();
	void setCitizenshipNo(const string);
	const string & getCitizenshipNo();
	void setAge(const int);
	const int & getAge();
};

#endif // !PERSON_CLASS