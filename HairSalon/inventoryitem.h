#pragma once

#include <string>

using namespace std;

class InventoryItem {
public:
	string productName;
	string description;
	int stockLevel;
	double price;

	// Define comparison operator for sorting
	bool operator<(const InventoryItem& other) const {
		return productName < other.productName;
	}
};

