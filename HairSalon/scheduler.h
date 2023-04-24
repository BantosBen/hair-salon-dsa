#pragma once

#include <iostream>
#include <string>
#include "avltree.h"

using namespace std;

class Scheduler {
public:
	Scheduler();
	void run();

private:
	AVLTree* tree;
	void menu();
};
