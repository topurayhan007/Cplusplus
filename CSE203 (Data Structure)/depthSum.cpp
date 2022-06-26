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


int depthSum(BinaryTreeNode* n) {
	queue<BinaryTreeNode*> q;
	q.push(n);
	int numNodesEachLevel = 1;
	int sum = 0; int i = 1;
	int sumA = 0;
	while (!q.empty()) {
		BinaryTreeNode* p = q.front();
		q.pop(); 
		numNodesEachLevel -= 1;
		
		sum = (sum+p->data);
		
		if (p->left != nullptr) { q.push(p->left); }
		if (p->right != nullptr) { q.push(p->right); }

		if (numNodesEachLevel == 0) {
			sumA = sumA + i*sum;			
			sum=0; i++;

			numNodesEachLevel = q.size();
		}
	}
	return sumA;
}

int main(){
	BinaryTreeNode* a = nullptr;
	
	insert(a, 10);
	insert(a, 7);
	insert(a, 16);
	insert(a, 3);
	insert(a, 9);
	insert(a, 24);
	insert(a, 8);
	insert(a, 25);
	
	cout<<"BST: ";
	printData(a);
	cout<<'\n';
	cout<<"Sum is: ";
	cout<<depthSum(a)<<endl;

	return 0;
}