#include "sale_management.h"

void SalesManagement::addSale(const Sale& sale) {
	sales.push(sale);
	saveToFile();
}

void SalesManagement::viewAllSales() {
	if (sales.empty()) {
		cout << "No sales found." << endl;
	}
	else {
		cout << "|----------------------|----------------------|----------------------|\n";
		cout << "| Sales ID             | Customer Name        | Sales Amount ($)     |\n";
		cout << "|----------------------|----------------------|----------------------|\n";
		queue<Sale> copy = sales;
		int i = 1;
		while (!copy.empty()) {
			Sale sale = copy.front();
			copy.pop();
			cout << "| " << left << setw(20) << i << " | ";
			cout << left << setw(20) << sale.customerName << " | ";
			cout << left << setw(20) << sale.totalAmount << " |\n";
			cout << "|----------------------|----------------------|----------------------|\n";
			i++;
		}
	}
}

void SalesManagement::searchSale(const string& customerName) {
	if (sales.empty()) {
		cout << "\nNo sales found." << endl;
	}
	else {
		cout << "|----------------------|----------------------|----------------------|\n";
		cout << "| Sales ID             | Customer Name        | Sales Amount ($)     |\n";
		cout << "|----------------------|----------------------|----------------------|\n";

		queue<Sale> copy = sales;

		bool found = false;
		int i = 1;
		while (!copy.empty()) {
			Sale sale = copy.front();
			if (sale.customerName == customerName) {
				found = true;
				cout << "| " << left << setw(20) << i << " | ";
				cout << left << setw(20) << sale.customerName << " | ";
				cout << left << setw(20) << sale.totalAmount << " |\n";
				cout << "|----------------------|----------------------|----------------------|\n";
			}
			copy.pop();
			i++;
		}
		if (!found) {
			cout << "\nSale not found for customer: " << customerName << endl;
		}
	}
}

void SalesManagement::menu() {
	cout << "\n1. Add sale" << endl;
	cout << "2. View all sales" << endl;
	cout << "3. Search sale by customer name" << endl;
	cout << "4. Exit" << endl;
	cout << "> ";
}

void SalesManagement::saveToFile() {
	queue<Sale> copy = sales;
	database.storeSalesToFile(copy, filename);
	readFromFile();
}

void SalesManagement::readFromFile() {
	database.readSalesFromFile(sales, filename);
}

void SalesManagement::run() {
	cout << "======================" << endl;
	cout << "Sales Management Menu" << endl;
	cout << "======================" << endl;

	int choice = 0;

	while (true) {
		menu();
		cin >> choice;

		switch (choice) {
		case 1: {
			string name;
			double amount;
			cout << "Enter customer name: ";
			cin >> name;
			cout << "Enter total amount: ";
			cin >> amount;
			Sale sale(name, amount);
			addSale(sale);
			cout << "Sale added successfully." << endl;
			break;
		}
		case 2: {
			viewAllSales();
			break;
		}
		case 3: {
			string name;
			cout << "Enter customer name: ";
			cin >> name;
			searchSale(name);
			break;
		}
		case 4: {
			return;
		}
		default: {
			cout << "Invalid choice." << endl;
			break;
		}
		}

	}
}