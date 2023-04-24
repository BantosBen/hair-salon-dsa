#pragma once
#include "customer.h"

class Node {
public:
	Node(Customer customer) : customer(customer), left(nullptr), right(nullptr) {}

	Customer customer;
	Node* left;
	Node* right;
};
