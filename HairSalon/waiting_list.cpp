#include "waiting_list.h"


void WaitingList::addCustomer() {
	Waiting newCustomer;
	cout << "Enter customer name: ";
	cin >> newCustomer.customerName;
	cout << "Enter requested service: ";
	cin >> newCustomer.service;
	waitingStack.push(newCustomer);
	cout << "\nCustomer added to waiting list.\n";
	saveToFile();
}

void WaitingList::viewNextCustomer() {
	if (waitingStack.empty()) {
		cout << "\nWaiting list is empty.\n";
	}
	else {
		Waiting nextCustomer = waitingStack.top();
		cout << "\nNext customer in line:\n";
		cout << "Name: " << nextCustomer.customerName << endl;
		cout << "Service: " << nextCustomer.service << endl;
		waitingStack.pop();

		saveToFile();
	}
}

void WaitingList::run() {
	int choice;

	cout << "======================" << endl;
	cout << "  Waiting List Menu" << endl;
	cout << "======================" << endl;

	while (true) {
		cout << "\n1. Add customer\n";
		cout << "2. View next customer\n";
		cout << "3. Exit\n";
		cout << "> ";
		cin >> choice;

		switch (choice) {
		case 1:
			addCustomer();
			break;
		case 2:
			viewNextCustomer();
			break;
		case 3:
			return;
		default:
			cout << "\nInvalid choice. Please try again.\n";
			break;
		}
	}
}

void WaitingList::saveToFile() {
	database.storeWaitingToFile(waitingStack, filename);
	readFromFile();
}

void WaitingList::readFromFile() {
	database.readWaitingFromFile(waitingStack, filename);
}

