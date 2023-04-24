#pragma once

#include "inventoryitem.h"
#include "database.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class InventoryManager {
public:
	void run();
	InventoryManager() {

		std::ifstream infile(filename);
		if (!infile.good()) {
			std::ofstream outfile(filename);
			outfile.close();
		}
		infile.close();

		readInventory();
	}

	~InventoryManager() {
		saveInventory();
	}

private:
	vector<InventoryItem> inventory;
	string filename = "invetory.txt";
	Database database;

	void addInventoryItem();
	void modifyInventoryItem();
	void deleteInventoryItem();
	void viewInventory();
	void menu();
	void saveInventory();
	void readInventory();

};
