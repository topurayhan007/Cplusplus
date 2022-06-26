//%%writefile 1.cpp

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
    int data;         
    ListNode* next;
};
void addValue(ListNode*& a, int value) {
	if (a == nullptr) {
		ListNode* x = new ListNode;
		x->data = value;
		x->next = a;//a is nullptr
		a = x;
	}
	else {
		ListNode* current = a;
		while (current->next != nullptr) {
			current = current->next;
		}
		ListNode* x = new ListNode;
		x->data = value;

		x->next = current->next;//current->next is nullptr
		current->next = x;
	}
}
void printData(ListNode* n) {
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}
ListNode* transferFrom(ListNode* list1, ListNode* list2) {
    ListNode* node = nullptr;
    if (list1 == nullptr){
        return (list2);
    }
    if (list2 == nullptr){
        return (list1);
    }
    
    node = list1;
    node->next = transferFrom(list1->next, list2);
    //printData(node);
    return node;
}


int main(){
	//list1: [8, 17, 2, 4]
  	//list2: [1, 2, 3]

  ListNode* list1 = nullptr;
  ListNode* list2 = nullptr;
  addValue(list1, 8);
  addValue(list1, 17);
  addValue(list1, 2);
  addValue(list1, 4);

  addValue(list2, 1);
  addValue(list2, 2);
  addValue(list2, 3);
  
  //printData(list1);
  //printData(list2);

  printData(transferFrom(list1, list2));

	return 0;
}