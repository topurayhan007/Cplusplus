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
	cout<<a->data<<" ";
	printData(a->left);
	printData(a->right);
}

int countLeftNodes(BinaryTreeNode* a) {
	if (a == nullptr) {
		return 0;
	}
	else if (a->left == nullptr){
		return countLeftNodes(a->right);
	}
	else{
		return 1 + countLeftNodes(a->left) + countLeftNodes(a->right);
	}
}

int main(){
	BinaryTreeNode* a= nullptr;
	
	insert(a, 7);
	insert(a, 2);
	insert(a, 9);
	insert(a, 1);
	insert(a, 5);
	insert(a, 14);
	
	
	printData(a);
	cout<<'\n';
	
	cout<<"Number of left nodes: "<<countLeftNodes(a)<<endl;

	return 0;
}