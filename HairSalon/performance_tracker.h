#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include "database.h"

using namespace std;

class PerformanceTracker {
private:
    string filename="metrics.txt";
    map<string, double> employeeMetrics;
    Database database;
    void addEmployee(string name, double points);
    void removeEmployee(string name);
    void printMetrics();
    void menu();

public:
    PerformanceTracker();
    void run();

};