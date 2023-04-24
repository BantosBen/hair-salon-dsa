#pragma once

#include <iostream>
#include <string>
#include "avltree.h"
#include "database.h"

using namespace std;

class Scheduler {
public:
	Scheduler();
	void run();

private:
	string filename = "schedule.txt";
	Database database;
	AVLTree tree;
	void menu();
};
