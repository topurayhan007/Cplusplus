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

void depthSum(BinaryTreeNode* n, int& e, int x, int sum, queue<int>& q) {
	
	e = n->data;
	sum = sum + e;
	if(sum > x){
		q.push(e);
		//cout<<"E: "<<e<<endl;
		
	}
	if (n->left != nullptr){

		depthSum(n->left, e, x, sum, q);
	}
	if (n->right != nullptr){
		depthSum(n->right, e, x, sum, q);
	}
}

void limitPathSum(BinaryTreeNode* n, int x){
	int e = 0; int sum = 0; queue<int> q;
	depthSum(n, e, x, sum, q);
	while(!q.empty()){
		int a = q.front();
		remove(n,a);
		q.pop();
	}
	
}

int main(){
	BinaryTreeNode* a = nullptr;
	
	insert(a, 29);
	insert(a, 17);
	insert(a, 115);
	insert(a, 11);
	insert(a, 18);
	insert(a, 44);
	insert(a, 214);
	insert(a, 8);
	insert(a, 12);
	insert(a, 26);
	insert(a, 200);
	insert(a, 219);
	
	cout<<"BST: ";
	printData(a);
	cout<<'\n';
	limitPathSum(a,50);
	cout<<"BST: ";
	printData(a);

	return 0;
}