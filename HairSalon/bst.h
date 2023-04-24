#pragma once

#include "node.h"
#include <functional>

class BST {
public:
	BST();
	~BST();
	void insert(Customer customer);
	Node* search(Customer customer);
	bool remove(Customer customer);
	void printInOrder();
	void inorderTraversal(function<void(Customer)> visit);
private:
	Node* root;
	void destroy(Node* node);
	Node* insertHelper(Node* node, Customer customer);
	Node* searchHelper(Node* node, Customer customer);
	Node* removeHelper(Node* node, Customer customer);
	Node* findMin(Node* node);
	void printInOrderHelper(Node* node);
	void inorderTraversalHelper(Node* node, function<void(Customer)> visit);
};
