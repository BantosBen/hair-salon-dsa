#pragma once

#include <string>

using namespace std;

class Schedule {
public:
    string timeSlot;
    string employeeName;
    Schedule* left;
    Schedule* right;
    int height;

    Schedule(string time, string name) {
        timeSlot = time;
        employeeName = name;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};