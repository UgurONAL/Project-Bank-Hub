#include <iostream>
#include "person.h"

using namespace std;

void Person::setName(const string newName) {
	name = newName;
}
const string & Person::getName() {
	return name;
}
void Person::setID(const int newID) {
	id = newID;
}
const int & Person::getID() {
	return id;
}
void Person::setPassword(const string newPassword) {
	password = newPassword;
}
const string & Person::getPassword() {
	return password;
}
void Person::setCitizenshipNo(const string newCitizenshipNo) {
	citizenshipNo = newCitizenshipNo;
}
const string & Person::getCitizenshipNo() {
	return citizenshipNo;
}
void Person::setAge(const int newAge) {
	age = newAge;
}
const int & Person::getAge() {
	return age;
}