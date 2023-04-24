#include "customer_mgt.h"

// Function to display the menu
void CustomerManagement::displayMenu() {
	cout << endl << endl;
	cout << "1. Add customer" << endl;
	cout << "2. Search customer" << endl;
	cout << "3. Delete customer" << endl;
	cout << "4. Quit" << endl;
	cout << ">";
}

// Function to add a new customer
void CustomerManagement::addCustomer() {
	string name, phone, email;

	cout << "Enter customer name: ";
	clearInput();
	getline(cin, name);
	cout << "Enter customer phone: ";
	getline(cin, phone);
	cout << "Enter customer email: ";
	getline(cin, email);

	Customer customer(name, phone, email);
	m_customers.insert(customer);
	cout << "Customer added"  << endl;
	saveCustomersToFile();
}

// Function to search for a customer
void CustomerManagement::searchCustomer() {
	string name;

	cout << "Enter customer name: ";
	clearInput();
	getline(cin, name);

	Node* node = m_customers.search(Customer(name, "", ""));
	if (node == nullptr) {
		cout << "Customer not found" << endl;
	}
	else {
		cout << "Customer found: "<< endl;
		node->customer.displayCustomerInfo();
	}
}

// Function to delete a customer
void CustomerManagement::deleteCustomer() {
	string name;

	cout << "Enter customer name: ";
	clearInput();
	getline(cin, name);

	if (m_customers.remove(Customer(name, "", ""))) {
		cout << "Customer deleted" << endl;
		saveCustomersToFile();
	}
	else {
		cout << "Customer not found" << endl;
	}

	
}

void CustomerManagement::loadCustomersFromFile() {
	database.readCustomersFromFile(m_customers, m_filename);
	saveCustomersToFile();
}
void CustomerManagement::saveCustomersToFile() {
	database.storeCustomersToFile(m_customers, m_filename);
}

void CustomerManagement::run() {
	cout << "==============================" << endl;
	cout << "   CUSTOMER MANAGEMENT MENU" << endl;
	cout << "==============================" << endl;

	int choice=0;

	while (choice!=4)
	{
		displayMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			addCustomer();
			break;
		case 2:
			searchCustomer();
			break;
		case 3:
			deleteCustomer();
			break;
		case 4:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}

void CustomerManagement::clearInput(){
	// Clear input stream buffer
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}