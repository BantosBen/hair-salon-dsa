#include "loyalty_program_mgt.h"

LoyaltyProgram::LoyaltyProgram() {
	database = new Database;
	database->loadLoyaltyPointFromFile(customers, filename);
}

void LoyaltyProgram::enrollCustomer(string name) {
	// Check if customer already exists
	if (customers.find(name) != customers.end()) {
		cout << "\nCustomer " << name << " is already enrolled in the loyalty program." << endl;
		return;
	}

	// Add customer to loyalty program
	customers.insert(make_pair(name, 0));
	cout << "\nCustomer " << name << " has been enrolled in the loyalty program." << endl;

	database->saveLoyaltyPointsToFile(customers, filename);
}

void LoyaltyProgram::addPoints(string name, int points) {
	// Check if customer exists
	if (customers.find(name) == customers.end()) {
		cout << "\nCustomer " << name << " is not enrolled in the loyalty program." << endl;
		return;
	}

	// Add points to customer's account
	customers[name] += points;
	cout << "\n" << points << " points have been added to " << name << "'s account. Total points: " << customers[name] << endl;

	database->saveLoyaltyPointsToFile(customers, filename);
}

void LoyaltyProgram::redeemPoints(string name, int points) {
	// Check if customer exists
	if (customers.find(name) == customers.end()) {
		cout << "\nCustomer " << name << " is not enrolled in the loyalty program." << endl;
		return;
	}

	// Check if customer has enough points
	if (customers[name] < points) {
		cout << "\n" << name << " does not have enough points to redeem." << endl;
		return;
	}

	// Redeem points from customer's account
	customers[name] -= points;
	cout << "\n" << points << " points have been redeemed from " << name << "'s account. Total points: " << customers[name] << endl;

	database->saveLoyaltyPointsToFile(customers, filename);
}

void LoyaltyProgram::viewPoints(string name) {
	// Check if customer exists
	if (customers.find(name) == customers.end()) {
		cout << "\nCustomer " << name << " is not enrolled in the loyalty program." << endl;
		return;
	}

	// View customer's points
	cout << "\n" << name << " has " << customers[name] << " loyalty points." << endl;
}

void LoyaltyProgram::run() {
	while (true) {
		cout << "\n=====================" << endl;
		cout << "	Loyalty Program" << endl;
		cout << "=====================" << endl;
		cout << "1. Add a new customer to the program" << endl;
		cout << "2. Update an existing customer's points" << endl;
		cout << "3. View a customer's current point balance" << endl;
		cout << "4. Redeem customer points." << endl;
		cout << "5. Exit\n> " << endl;

		int choice;
		string name;

		cin >> choice;

		if (choice == 1) {
			// add a new customer to the program
			cout << "Enter customer name: ";
			cin >> name;
			enrollCustomer(name);
		}
		else if (choice == 2) {
			// update an existing customer's points
			cout << "Enter customer name: ";
			cin >> name;
			cout << "Enter points to add: ";
			int points;
			cin >> points;
			addPoints(name, points);
		}
		else if (choice == 3) {
			// view a customer's current point balance
			cout << "Enter customer name: ";
			cin >> name;
			viewPoints(name);
		}
		else if (choice == 4) {
			// remove a customer from the program
			cout << "Enter customer name: ";
			cin >> name;
			cout << "Enter points to add: ";
			int points;
			cin >> points;
			redeemPoints(name, points);
		}
		else if (choice == 5) {
			// exit
			return;
		}
		else {
			// invalid input
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}
