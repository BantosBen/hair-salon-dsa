#include "Database.h"

using namespace std;

void Database::readCustomersFromFile(BST& customers, const string& filename) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "\nError opening file " << filename << endl;
		return;
	}
	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		string name, phone, email;
		getline(ss, name, ',');
		getline(ss, phone, ',');
		getline(ss, email);
		customers.insert(Customer(name, phone, email));
	}
	infile.close();
}


void Database::storeCustomersToFile(BST& customers, const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "\nError: could not open file " << filename << " for writing" << endl;
		return;
	}

	customers.inorderTraversal([&](Customer c) {
		outfile << c.getName() << "," << c.getPhone() << "," << c.getEmail() << endl;
		});

	outfile.close();
}

void Database::readAppointmentsFromFile(priority_queue<Appointment, vector<Appointment>, greater<Appointment>>& appointments, const string& filename) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "\nError opening file " << filename << endl;
		return;
	}
	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		string name, date, time, service;
		getline(ss, name, ',');
		getline(ss, date, ',');
		getline(ss, time, ',');
		getline(ss, service);
		Appointment appointment(name, date, time, service);
		appointments.push(appointment);
	}
	infile.close();
}

void Database::storeAppointmentsToFile(priority_queue<Appointment, vector<Appointment>, greater<Appointment>>& appointments, const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "\nError: could not open file " << filename << " for writing" << endl;
		return;
	}

	if (!appointments.empty()) {
		while (!appointments.empty()) {
			Appointment appointment = appointments.top();
			appointments.pop();
			outfile << appointment.getCustomerName() << "," << appointment.getDate() << "," << appointment.getTime() << "," << appointment.getService() << endl;
		}
	}
	outfile.close();
}

void Database::readInventoryFromFile(vector<InventoryItem>& inventory, const string& filename) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "\nError opening file " << filename << endl;
		return;
	}
	string line;
	while (getline(infile, line)) {

		stringstream ss(line);
		string productName, description, stockLevelStr, priceStr;
		int stockLevel;
		double price;

		getline(ss, productName, ',');
		getline(ss, description, ',');
		getline(ss, stockLevelStr, ',');
		getline(ss, priceStr);
		stockLevel = stoi(stockLevelStr);

		price = stod(priceStr);
		InventoryItem item{ productName, description, stockLevel, price };
		inventory.push_back(item);
	}
	infile.close();
}

void Database::storeInventoryToFile(vector<InventoryItem>& inventory, const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "\nError: could not open file " << filename << " for writing" << endl;
		return;
	}

	if (!inventory.empty()) {
		for (const auto& item : inventory) {
			outfile << item.productName << "," << item.description << "," << item.stockLevel << "," << item.price << endl;
		}
	}
	outfile.close();
}


void Database::storeSalesToFile(queue<Sale>& sales, const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "\nError: could not open file " << filename << " for writing" << endl;
		return;
	}

	if (!sales.empty()) {
		while (!sales.empty()) {
			Sale sale = sales.front();
			sales.pop();
			outfile << sale.customerName << "," << sale.totalAmount << endl;
		}
	}
	outfile.close();
}
void Database::readSalesFromFile(queue<Sale>& sales, const string& filename) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "\nError opening file " << filename << endl;
		return;
	}
	string line;
	while (getline(infile, line)) {

		stringstream ss(line);
		string customerName, totalAmountStr;
		double amount;

		getline(ss, customerName, ',');
		getline(ss, totalAmountStr);

		amount = stod(totalAmountStr);

		Sale item{ customerName, amount };
		sales.push(item);
	}
	infile.close();
}


void Database::storeWaitingToFile(stack<Waiting>& waiting, const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "\nError: could not open file " << filename << " for writing" << endl;
		return;
	}

	if (!waiting.empty()) {
		while (!waiting.empty()) {
			Waiting nextWaiting = waiting.top();
			waiting.pop();
			outfile << nextWaiting.customerName << "," << nextWaiting.service << endl;
		}
	}
	outfile.close();
}

void Database::readWaitingFromFile(stack<Waiting>& waiting, const string& filename) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "\nError opening file " << filename << endl;
		return;
	}
	string line;
	while (getline(infile, line)) {

		stringstream ss(line);
		string customerName, service;

		getline(ss, customerName, ',');
		getline(ss, service);

		Waiting newCustomer;
		newCustomer.customerName = customerName;
		newCustomer.service = service;
		waiting.push(newCustomer);
	}
	infile.close();
}


// Save data to file
void Database::saveLoyaltyPointsToFile(unordered_map<string, int>& loyaltyData, const string& filename)
{
	ofstream outfile(filename);
	if (outfile.is_open())
	{
		for (auto& kv : loyaltyData)
		{
			outfile << kv.first << ":" << kv.second << endl;
		}
		outfile.close();
	}
}

// Load data from file
void Database::loadLoyaltyPointFromFile(unordered_map<string, int>& loyaltyData, const string& filename)
{
	ifstream infile(filename);
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			size_t pos = line.find(":");
			string name = line.substr(0, pos);
			int points = stoi(line.substr(pos + 1));
			loyaltyData[name] = points;
		}
		infile.close();
	}
}


void Database::saveScheduleDataToFile(AVLTree& tree, const string& filename) {
	ofstream outfile(filename);
	if (outfile) {
		Schedule* root = tree.getRoot();
		saveScheduleDataToFileHelper(root, outfile);
		outfile.close();
	}
	else {
		cerr << "\nUnable to open file for writing: " << filename << endl;
	}
}

void Database::loadScheduleDataFromFile(AVLTree& tree, const string& filename) {

	ifstream infile(filename);
	if (infile) {
		string line;
		while (getline(infile, line)) {
			stringstream ss(line);
			string timeSlot, employeeName;
			ss >> timeSlot >> employeeName;
			tree.setRoot(tree.insert(tree.getRoot(), timeSlot, employeeName));
		}
		infile.close();
	}
	else {
		cerr << "\nUnable to open file for reading: " << filename << endl;
	}
}

void Database::saveScheduleDataToFileHelper(Schedule* node, ofstream& outfile) {
	if (node != nullptr) {
		saveScheduleDataToFileHelper(node->left, outfile);
		outfile << node->timeSlot << " " << node->employeeName << endl;
		saveScheduleDataToFileHelper(node->right, outfile);
	}
}


