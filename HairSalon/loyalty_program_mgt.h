#pragma once

#ifndef LOYALTYPROGRAM_H
#define LOYALTYPROGRAM_H

#include "database.h"
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class LoyaltyProgram {
public:
    LoyaltyProgram(); // constructor
    void run();

private:
    string filename = "loyalty_program.txt";
    unordered_map<string, int> customers;
    Database* database;
    void enrollCustomer(string name);
    void viewPoints(string name);
    void addPoints(string name, int points);
    void redeemPoints(string name, int points);
};

#endif // LOYALTYPROGRAM_H

