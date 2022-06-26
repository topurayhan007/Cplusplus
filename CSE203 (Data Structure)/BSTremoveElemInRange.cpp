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

void printData(BinaryTreeNode*a){
	if(a == nullptr){
		return;
	}
	printData(a->left);
	cout<<a->data<<" ";
	printData(a->right);
}

int minValue(BinaryTreeNode* a) {
	if (a == nullptr) {
		cout<<"Empty!"<<endl;
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

BinaryTreeNode* countRemoved(BinaryTreeNode*& n, int min, int max) {
	if (n == nullptr){
		return nullptr;
	}
	n->left = countRemoved(n->left, min, max);
	n->right = countRemoved(n->right,min,max);

	if (n->data >= min && n->data <= max){
		
		remove(n,n->data);
		min++;
	}
	min++;
	return n;
}


int main(){
	BinaryTreeNode* a = nullptr;
	
	insert(a, 10);
	insert(a, 5);
	insert(a, 13);
	insert(a, 3);
	insert(a, 7);
	insert(a, 14);

	
	cout<<"BST: ";
	printData(a);
	cout<<'\n';
	countRemoved(a, 4, 5);
	countRemoved(a, 12, 13);

	cout<<"BST after removal: ";
	printData(a);

	return 0;
}