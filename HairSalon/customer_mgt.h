#pragma once
#include "bst.h"
#include "database.h"
#include <iostream>
#include <fstream>
#include <string>

// CustomerManagement class definition
class CustomerManagement {
public:
	// Constructor
	CustomerManagement() : m_customers(), m_filename("customers.txt") {
		std::ifstream infile(m_filename);
		if (!infile.good()) {
			std::ofstream outfile(m_filename);
			outfile.close();
		}
		infile.close();

		loadCustomersFromFile();
	}

	// Public member functions
	void run();

private:
	// Private member functions
	void displayMenu();
	void addCustomer();
	void searchCustomer();
	void deleteCustomer();
	void loadCustomersFromFile();
	void saveCustomersToFile();
	void clearInput();

	// Private data members
	BST m_customers;
	Database database;
	string m_filename;
};

