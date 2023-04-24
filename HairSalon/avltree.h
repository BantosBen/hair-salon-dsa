#pragma once

#include <iostream>
#include <string>
#include "schedule.h"

using namespace std;

class AVLTree {
public:
    AVLTree();
    Schedule* getRoot();
    void setRoot(Schedule* m_root);
    Schedule* insert(Schedule* node,string timeSlot, string employeeName);
    Schedule* remove(Schedule* node,string timeSlot);
    Schedule* search(string timeSlot);

private:
    Schedule* root;
    int getHeight(Schedule* node);
    int getBalanceFactor(Schedule* node);
    Schedule* rotateLeft(Schedule* node);
    Schedule* rotateRight(Schedule* node);
    Schedule* minValueNode(Schedule* node);
};