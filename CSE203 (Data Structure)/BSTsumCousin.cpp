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

int parentFind(BinaryTreeNode* a, int n, int& parent){
	if (a == nullptr) {
		return -404404404;
	}
	else if (a->data == n){
		return parent;
	}
	else{
		if (n < a->data) {
			parent = a->data;
			parentFind(a->left, n, parent);
		}
		else if (n > a->data) {
			parent = a->data;
			parentFind(a->right, n, parent);
		}
	}
	return parent;
}
void printLevel(BinaryTreeNode* n, int s, int check, queue<int>& level) {
	queue<BinaryTreeNode*> q;
	q.push(n);
	int numNodesEachLevel = 1;

	while (!q.empty()) {
		BinaryTreeNode* p = q.front();
		q.pop(); 
		numNodesEachLevel -= 1;
		if(p->data == s){
			check = 1;
		}
		level.push(p->data);

		if (p->left != nullptr) { q.push(p->left); }
		if (p->right != nullptr) { q.push(p->right); }

		if (numNodesEachLevel == 0) {
			if(check == 1){
				return;
			}
			while(!level.empty()){
				level.pop();
			}
			numNodesEachLevel = q.size();
		}
	}
}

int sumCousin(BinaryTreeNode* a, int n){
	int sum = 0; int check = 0; int parent = 0;
	queue<int> level; queue<int> s;
	printLevel(a, n, check, level);
	int x = parentFind(a, n, parent);
	
	while(!level.empty()){
		int first = level.front();
		int y = parentFind(a, first, parent);
		level.pop();
		if (x != y){
			s.push(first);
		}
	}
	while(!s.empty()){
		sum = sum + s.front();
		s.pop();
	}
	return sum;
}

int main() {
	BinaryTreeNode* a = nullptr;
	insert(a, 10);
	insert(a, 4);
	insert(a, 16);
	insert(a, 3);
	insert(a, 9);
	insert(a, 20);
	insert(a, 7);
	insert(a, 25);
	insert(a, 5);
	insert(a, 8);
	insert(a, 22);
	insert(a, 26);
	
	int x = 22;
	//cout<<parentFind(a, 20, parent); cout<<endl;
	cout<<"Sum of cousin of "<<x<<" is "<<sumCousin(a, x)<<endl;
	
	return 0;
}
