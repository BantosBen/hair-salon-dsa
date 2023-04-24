#pragma once

#include <stack>
#include "database.h"
#include "waiting.h"

using namespace std;

class WaitingList {

private:
	Database database;
	string filename = "waitlist.txt";
	void addCustomer();
	void viewNextCustomer();
	void saveToFile();
	void readFromFile();
	stack<Waiting> waitingStack;

public:
	void run();
	WaitingList() {
		std::ifstream infile(filename);
		if (!infile.good()) {
			std::ofstream outfile(filename);
			outfile.close();
		}
		infile.close();

		readFromFile();
	}

};

