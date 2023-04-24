#include "customer.h"
#include <iostream>
#include <fstream>

using namespace std;

Customer::Customer() {}

Customer::Customer(string n, string p, string e) {
	name = n;
	phone = p;
	email = e;
}

void Customer::setName(string n) {
	name = n;
}

void Customer::setPhone(string p) {
	phone = p;
}

void Customer::setEmail(string e) {
	email = e;
}

string Customer::getName() {
	return name;
}

string Customer::getPhone() {
	return phone;
}

string Customer::getEmail() {
	return email;
}

void Customer::displayCustomerInfo() {
	cout << "Name: " << name << endl;
	cout << "Phone: " << phone << endl;
	cout << "Email: " << email << endl;
}