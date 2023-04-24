#include "avltree.h"



AVLTree::AVLTree() {
	root = nullptr;
}

Schedule* AVLTree::getRoot() {
	return root;
}

void AVLTree::setRoot(Schedule* m_root)
{
	root = m_root;
}


int AVLTree::getHeight(Schedule* node) {
	if (node == nullptr) {
		return 0;
	}
	return node->height;
}

int AVLTree::getBalanceFactor(Schedule* node) {
	if (node == nullptr) {
		return 0;
	}
	return getHeight(node->left) - getHeight(node->right);
}

Schedule* AVLTree::rotateLeft(Schedule* node) {
	Schedule* rightNode = node->right;
	Schedule* leftSubtree = rightNode->left;

	rightNode->left = node;
	node->right = leftSubtree;

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	rightNode->height = 1 + max(getHeight(rightNode->left), getHeight(rightNode->right));

	return rightNode;
}

Schedule* AVLTree::rotateRight(Schedule* node) {
	Schedule* leftNode = node->left;
	Schedule* rightSubtree = leftNode->right;

	leftNode->right = node;
	node->left = rightSubtree;

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	leftNode->height = 1 + max(getHeight(leftNode->left), getHeight(leftNode->right));

	return leftNode;
}

Schedule* AVLTree::insert(Schedule* node, string timeSlot, string employeeName) {
	if (node == nullptr) {
		return new Schedule(timeSlot, employeeName);
	}
	if (timeSlot < node->timeSlot) {
		node->left = insert(node->left, timeSlot, employeeName);
	}
	else if (timeSlot > node->timeSlot) {
		node->right = insert(node->right, timeSlot, employeeName);
	}
	else {
		cout << "Time slot already exists." << endl;
		return nullptr;
	}

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	int balance = getBalanceFactor(node);

	if (balance > 1 && timeSlot < node->left->timeSlot) {
		return rotateRight(node);
	}
	if (balance < -1 && timeSlot > node->right->timeSlot) {
		return rotateLeft(node);
	}
	if (balance > 1 && timeSlot > node->left->timeSlot) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	if (balance < -1 && timeSlot < node->right->timeSlot) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	return node;
}

Schedule* AVLTree::remove(Schedule* node, string timeSlot) {
	if (node == nullptr) {
		return node;
	}
	if (timeSlot < node->timeSlot) {
		node->left = remove(node->left, timeSlot);
	}
	else if (timeSlot > node->timeSlot) {
		node->right = remove(node->right, timeSlot);
	}
	else {
		// Case 1: Node has no child or only one child
		if (node->left == nullptr || node->right == nullptr) {
			Schedule* temp;
			if (node->left != nullptr) {
				temp = node->left;
			}
			else {
				temp = node->right;
			}
			// If no child
			if (temp == nullptr) {
				temp = node;
				node = nullptr;
			}
			else { // If one child
				*node = *temp;
				delete temp;
			}
		}
		else { // Case 2: Node has two children
			Schedule* temp = minValueNode(node->right);
			node->timeSlot = temp->timeSlot;
			node->employeeName = temp->employeeName;
			node->right = remove(node->right, temp->timeSlot);
		}
	}

	if (node == nullptr) {
		return node;
	}

	// Update the height of the current node
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));

	// Get the balance factor of the current node
	int balance = getBalanceFactor(node);

	// Left Left Case
	if (balance > 1 && getBalanceFactor(node->left) >= 0) {
		return rotateRight(node);
	}

	// Left Right Case
	if (balance > 1 && getBalanceFactor(node->left) < 0) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	// Right Right Case
	if (balance < -1 && getBalanceFactor(node->right) <= 0) {
		return rotateLeft(node);
	}

	// Right Left Case
	if (balance < -1 && getBalanceFactor(node->right) > 0) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

// Helper method to get the minimum value node in a subtree
Schedule* AVLTree::minValueNode(Schedule* node) {
	Schedule* current = node;
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}

Schedule* AVLTree::search(string timeSlot) {
	Schedule* current = root;
	while (current != nullptr) {
		cout << "Time Slot: " << current->timeSlot << endl;
		if (timeSlot == current->timeSlot) {
			return current;
		}
		else if (timeSlot < current->timeSlot) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return nullptr;
}

