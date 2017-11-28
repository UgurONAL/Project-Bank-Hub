#include <iostream>
#include "bank.h"

using namespace std;

void Bank::setName(const string newName) {
	name = newName;
}
const string & Bank::getName() {
	return name;
}
void Bank::setID(const int newID) {
	id = newID;
}
const int & Bank::getID() {
	return id;
}