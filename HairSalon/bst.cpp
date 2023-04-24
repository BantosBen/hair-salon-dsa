#include "bst.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
	destroy(root);
}

void BST::insert(Customer customer) {
	root = insertHelper(root, customer);
}

Node* BST::search(Customer customer) {
	return searchHelper(root, customer);
}

bool BST::remove(Customer customer) {
	root = removeHelper(root, customer);
	return root != NULL;
}

void BST::printInOrder() {
	printInOrderHelper(root);
}

void BST::destroy(Node* node) {
	if (node != nullptr) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

Node* BST::insertHelper(Node* node, Customer customer) {
	if (node == nullptr) {
		return new Node(customer);
	}
	else if (customer < node->customer) {
		node->left = insertHelper(node->left, customer);
	}
	else {
		node->right = insertHelper(node->right, customer);
	}
	return node;
}

Node* BST::searchHelper(Node* node, Customer customer) {
	if (node == nullptr) {
		return nullptr;
	}
	else if (customer < node->customer) {
		return searchHelper(node->left, customer);
	}
	else if (node->customer < customer) {
		return searchHelper(node->right, customer);
	}
	else {
		return node;
	}
}

Node* BST::removeHelper(Node* node, Customer customer) {
	if (node == nullptr) {
		return nullptr;
	}
	else if (customer < node->customer) {
		node->left = removeHelper(node->left, customer);
	}
	else if (node->customer < customer) {
		node->right = removeHelper(node->right, customer);
	}
	else {
		if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}
		else {
			Node* successor = findMin(node->right);
			node->customer = successor->customer;
			node->right = removeHelper(node->right, successor->customer);
		}
	}
	return node;
}

Node* BST::findMin(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

void BST::printInOrderHelper(Node* node) {
	if (node == nullptr) {
		return;
	}
	printInOrderHelper(node->left);
	node->customer.displayCustomerInfo();
	printInOrderHelper(node->right);
}

void BST::inorderTraversal(function<void(Customer)> visit) {
	inorderTraversalHelper(root, visit);
}

void BST::inorderTraversalHelper(Node* node, function<void(Customer)> visit) {
	if (node != nullptr) {
		inorderTraversalHelper(node->left, visit);
		visit(node->customer);
		inorderTraversalHelper(node->right, visit);
	}
}