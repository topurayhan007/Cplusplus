#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct BinaryTreeNode {
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void insert(BinaryTreeNode*& n, int i) {
	if (n == nullptr) {
		n = new BinaryTreeNode;
		n->data = i;
		n->right = nullptr;
		n->left = nullptr;
	}
	else if (i > n->data) {
		insert(n->right, i);
	}
	else if (i < n->data) {
		insert(n->left, i);
	}
}

void printData(BinaryTreeNode* a) {
	if (a == nullptr) {
		return;
	}
	printData(a->left);
	cout << a->data << " ";
	printData(a->right);
}

int minValue(BinaryTreeNode* a) {
	if (a == nullptr) {
		cout << "Empty!" << endl;
		throw (404);
	}
	if (a->left == nullptr) {
		return a->data;
	}
	else {
		return minValue(a->left);
	}
}

void remove(BinaryTreeNode*& n, int i) {
	if (n == nullptr) { return; }
	else if (i > n->data) {
		remove(n->right, i);
	}
	else if (i < n->data) {
		remove(n->left, i);
	}
	else if (i == n->data) {
		if (n->right == nullptr && n->left == nullptr) {
			n = nullptr;
		}
		else if (n->right == nullptr) {
			n = n->left;
		}
		else if (n->left == nullptr) {
			n = n->right;
		}
		else {
			int min = minValue(n->right);
			n->data = min;
			remove(n->right, min);
		}
	}
}

void removeLeaf(BinaryTreeNode*& n, int k, int& count) {
	if (n == nullptr) {
		return;
	}
	removeLeaf(n->left, k, count);
	removeLeaf(n->right, k, count);
	if (n->left == nullptr && n->right == nullptr) {
		++count;
		if (count >= ((2 * k) - 1) && count <= (2 * k)) {
			remove(n, n->data);
		}
	}

}
void removeKthLeaf(BinaryTreeNode*& n, int k) {
	if (k <= 0) {
		throw(404);

	}
	int count = 0;
	removeLeaf(n, k, count);
}
int main() {
	BinaryTreeNode* a = nullptr;

	insert(a, 70);
	insert(a, 20);
	insert(a, 81);
	insert(a, 13);
	insert(a, 21);
	insert(a, 75);
	insert(a, 87);
	insert(a, 72);
	insert(a, 79);
	insert(a, 98);
	insert(a, 93);
	insert(a, 113);

	cout << "BST: ";
	printData(a);
	cout << '\n';

	removeKthLeaf(a, 2);
	cout << "BST: ";
	printData(a);

	return 0;
}