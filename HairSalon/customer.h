#pragma once
#include <string>
#include <vector>

using namespace std;

class Customer {
private:
	string name;
	string phone;
	string email;

public:
	Customer();
	Customer(string n, string p, string e);
	void setName(string n);
	void setPhone(string p);
	void setEmail(string e);
	string getName();
	string getPhone();
	string getEmail();
	void displayCustomerInfo();

	bool operator<(const Customer& other) const {
		return name < other.name;
	}
};