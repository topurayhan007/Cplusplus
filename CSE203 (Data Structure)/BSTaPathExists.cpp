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
	else{
		return false;
	}
}
bool hasPath(BinaryTreeNode* n, int start, int end) {
	int count = 0;
	if (n == nullptr) {
		return false;
	}
	if((find(n, start)) != true && (find(n, end)) != true){
			return false;
	}
	else {
			return true;
	}
	if (start > n->data) {
		return hasPath(n->right, start, end);
	}
	else if (start < n->data) {
		return hasPath(n->left, start, end);
	}
}

int main(){
	BinaryTreeNode* a = nullptr;
	
	insert(a, 67);
	insert(a, 152);
	insert(a, 38);
	insert(a, 16);
	insert(a, 42);
	insert(a, 99);
	insert(a, 40);
	
	
	cout<<"BST: ";
	printData(a);
	cout<<'\n';
	cout<<hasPath(a,99,67)<<endl;

	return 0;
}