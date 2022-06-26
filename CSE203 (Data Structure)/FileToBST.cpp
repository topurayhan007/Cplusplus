#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
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

void fileToBST(string filename, BinaryTreeNode*& a) {
	ifstream myFile;
	myFile.open(filename);

	if (myFile.is_open()) {
		int num;
		while (myFile >> num) {
			insert(a,num);
		}
	}
	else {
		cout<<"Couldn't Open File"<<endl;
	}
	myFile.close();

}

int main(){
	BinaryTreeNode* a = nullptr;
	string filename = "D:/input.txt";
	
	fileToBST(filename, a);
	printData(a);

	return 0;
}