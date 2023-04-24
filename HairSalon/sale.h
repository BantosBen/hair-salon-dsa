#pragma once

#include <string>

using namespace std;

class Sale {
public:
	string customerName;
	double totalAmount;

	Sale(string name, double amount) {
		customerName = name;
		totalAmount = amount;
	}
};
