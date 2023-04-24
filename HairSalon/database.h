#pragma once

#include <stack>
#include "bst.h"
#include "customer.h"
#include "appointment.h"
#include "inventoryitem.h"
#include "sale.h"
#include "waiting.h"
#include "avltree.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>


using namespace std;

class Database {
public:
	void readCustomersFromFile(BST& customers, const string& filename);
	void storeCustomersToFile(BST& customers, const string& filename);

	void readAppointmentsFromFile(priority_queue<Appointment, vector<Appointment>, greater<Appointment>>& appointments, const string& filename);
	void storeAppointmentsToFile(priority_queue<Appointment, vector<Appointment>, greater<Appointment>>& appointments, const string& filename);

	void storeInventoryToFile(vector<InventoryItem>& inventory, const string& filename);
	void readInventoryFromFile(vector<InventoryItem>& inventory, const string& filename);

	void storeSalesToFile(queue<Sale>& sales, const string& filename);
	void readSalesFromFile(queue<Sale>& sales, const string& filename);

	void storeWaitingToFile(stack<Waiting>& waiting, const string& filename);
	void readWaitingFromFile(stack<Waiting>& waiting, const string& filename);

	void saveLoyaltyPointsToFile(unordered_map<string, int>& loyaltyData, const string& filename);
	void loadLoyaltyPointFromFile(unordered_map<string, int>& loyaltyData, const string& filename);

	void saveScheduleDataToFile(AVLTree& tree, const string& filename);
	void loadScheduleDataFromFile(AVLTree& tree, const string& filename);
	void saveScheduleDataToFileHelper(Schedule* node, ofstream& outfile);

	void saveEmployeeMetricsToFile(map<string, double>& employeeMetrics, const string& fileName);
	void loadEmployeeMetricsFromFile(map<string, double>& employeeMetrics, const string& fileName);
};