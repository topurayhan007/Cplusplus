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


int findKthLevel (BinaryTreeNode* n) {
	queue<BinaryTreeNode*> q;
	q.push(n);
	int numNodesEachLevel = 1;
	int c = 0; int level  = 0; int r = 0; int j=-1;
	while (!q.empty()) {
		BinaryTreeNode* p = q.front();
		q.pop(); 
		numNodesEachLevel -= 1;
		++c;

		if (p->left != nullptr) { q.push(p->left); }
		if (p->right != nullptr) { q.push(p->right); }

		if (numNodesEachLevel == 0) {
			++j;
			if(c > r){
				r = c;
				level = j;
			}
			c=0;
			numNodesEachLevel = q.size();
		}
	}
	return level;

}

int main(){
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
	
	cout<<"BST: ";
	printData(a);
	cout<<'\n';
	cout<<"The Kth level is: ";
	cout<<findKthLevel (a)<<endl;

	return 0;
}