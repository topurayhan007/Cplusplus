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

bool find(BinaryTreeNode* n, int i) {
	if (n == nullptr) {
		return false;
	}
	if (n->data == i) {
		return true;
	}
	else if (i > n->data) {
		return find(n->right, i);
	}
	else if (i < n->data) {
		return find(n->left, i);
	}
}
bool hasPath(BinaryTreeNode* n, int start, int end) {
	if (start > end){
		return false;
	}
	if (n == nullptr) {
		return false;
	}
	else if (start == end && n->data == start){
		return true;
	}

	else if (n->data >= start && n->data <= end){
		if((find(n, n->data)) != true){
			return false;
		}
		else {
			return true;
		}
	}
	else if (start > n->data) {
		return hasPath(n->right, start, end);
	}
	else if (start < n->data) {
		return hasPath(n->left, start, end);
	}

}


int main(){
	BinaryTreeNode* a = nullptr;

	insert(a, 50);
	insert(a, 38);
	insert(a, 90);
	insert(a, 14);
	insert(a, 42);
	insert(a, 54);
	insert(a, 8);
	insert(a, 20);
	insert(a, 72);
	insert(a, 26);
	insert(a, 61);
	insert(a, 83);

	cout<<"BST: ";
	printData(a);
	cout<<'\n';
	cout<<hasPath(a,67,99)<<endl;
	printData(a);

	return 0;
}
