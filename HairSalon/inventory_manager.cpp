#include "inventory_manager.h"



// Add an inventory item
void InventoryManager::addInventoryItem() {
	InventoryItem newItem;
	cout << "Enter the product name: ";
	getline(cin, newItem.productName);
	cout << "Enter the description: ";
	getline(cin, newItem.description);
	cout << "Enter the stock level: ";
	cin >> newItem.stockLevel;
	cout << "Enter the price: ";
	cin >> newItem.price;

	// Add the item to the vector and sort it
	inventory.push_back(newItem);
	sort(inventory.begin(), inventory.end());
	cout << "Item added successfully!\n";
	saveInventory();
}

// Modify an inventory item
void InventoryManager::InventoryManager::modifyInventoryItem() {
	string searchName;
	cout << "Enter the product name to modify: ";
	getline(cin, searchName);

	// Find the item by name
	auto it = find_if(inventory.begin(), inventory.end(), [&searchName](const InventoryItem& item) { return item.productName == searchName; });
	if (it == inventory.end()) {
		cout << "Item not found.\n";
		return;
	}

	// Modify the item
	InventoryItem& item = *it;
	cout << "Enter the new description (leave blank to keep current): ";
	string newDescription;
	getline(cin, newDescription);
	if (!newDescription.empty()) {
		item.description = newDescription;
	}
	cout << "Enter the new stock level (leave blank to keep current): ";
	string newStockLevel;
	getline(cin, newStockLevel);
	if (!newStockLevel.empty()) {
		item.stockLevel = stoi(newStockLevel);
	}
	cout << "Enter the new price (leave blank to keep current): ";
	string newPrice;
	getline(cin, newPrice);
	if (!newPrice.empty()) {
		item.price = stod(newPrice);
	}

	// Sort the vector
	sort(inventory.begin(), inventory.end());
	cout << "Item modified successfully!\n";
	saveInventory();
}

// Delete an inventory item
void InventoryManager::deleteInventoryItem() {
	string searchName;
	cout << "Enter the product name to delete: ";
	getline(cin, searchName);

	// Find the item by name
	auto it = find_if(inventory.begin(), inventory.end(), [&searchName](const InventoryItem& item) { return item.productName == searchName; });
	if (it == inventory.end()) {
		cout << "Item not found.\n";
		return;
	}

	// Erase the item from the vector and sort it
	inventory.erase(it);
	sort(inventory.begin(), inventory.end());
	cout << "Item deleted successfully!\n";
	saveInventory();
}

// View all inventory items
void InventoryManager::viewInventory() {
	if (!inventory.empty()) {
		cout << "|----------------------|----------------------|----------------------|\n";
		cout << "| Item Name            | Stock Level          | Unit Price($)        |\n";
		cout << "|----------------------|----------------------|----------------------|\n";
		for (const auto& item : inventory) {
			cout << "| " << left << setw(20) << item.productName << " | ";
			cout << left << setw(20) << item.stockLevel << " | ";
			cout << left << setw(20) << item.price << " |\n";
			cout << "|----------------------|----------------------|----------------------|\n";
		}
	}
	else {
		cout << "\nThere are no items in iventory\n" << endl;
	}
}

void InventoryManager::menu() {
	cout << "\n1. Add new inventory item" << endl
		<<"2. Modify inventory item"<<endl
		<<"3. Delete inventory item"<<endl
		<<"4. View all inventory items"<<endl
		<<"5. Exit"<<endl
		<<"> ";
}

void InventoryManager::run() {
	cout << "=============================" << endl;
	cout << "        INVENTORY MENU" << endl;
	cout << "=============================" << endl;

	int choice = 0;
	while (true) {
		menu();
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			addInventoryItem();
			break;
		case 2:
			modifyInventoryItem();
			break;
		case 3:
			deleteInventoryItem();
			break;
		case 4:
			viewInventory();
			break;
		case 5:
			return;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}

void InventoryManager::saveInventory() {
	database.storeInventoryToFile(inventory, filename);
	readInventory();
}

void InventoryManager::readInventory() {
	database.readInventoryFromFile(inventory, filename);
}
