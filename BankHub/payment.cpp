#include <iostream>
#include "payment.h"

using namespace std;

void Payment::setName(const string newName) {
	name = newName;
}
const string & Payment::getName() {
	return name;
}
void Payment::setID(const int newID) {
	id = newID;
}
const int & Payment::getID() {
	return id;
}
void Payment::setUserID(const int newUserID) {
	userID = newUserID;
}
const int & Payment::getUserID() {
	return userID;
}
void Payment::setAmount(const double newAmount) {
	amount = newAmount;
}
const double & Payment::getAmount() {
	return amount;
}