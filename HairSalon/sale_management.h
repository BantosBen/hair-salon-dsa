#pragma once

#include "sale.h"
#include "database.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class SalesManagement {
private:
	queue<Sale> sales;
	string filename="sales.txt";
	Database database;
	void addSale(const Sale& sale);
	void viewAllSales();
	void searchSale(const string& customerName);
	void menu();
	void saveToFile();
	void readFromFile();

public:
	void run();
	SalesManagement() {
		std::ifstream infile(filename);
		if (!infile.good()) {
			std::ofstream outfile(filename);
			outfile.close();
		}
		infile.close();

		readFromFile();
	}

};
