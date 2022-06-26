//%%writefile Q1.cpp

#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
	int data = 0;
	ListNode* next = nullptr;
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
		cout << n->data << ", ";
		n = n->next;
	}
	cout << endl;
}
void removeAll(ListNode*& front, int value) {
	if (front == nullptr) {
		return;
	}
	while (front->data == value) {
		ListNode* remove = front;
		front = front->next;
		delete (remove);
		if (front == nullptr)return;
	}
	ListNode* current = front;
	while (current->next != nullptr) {
		if (current->next->data == value) {
			ListNode* remove = current->next;
			current->next = current->next->next;
			delete (remove);
		}
		else {
			current = current->next;
		}
	}
}
void removeDuplicate(ListNode*& front) {
	ListNode* dupList = nullptr;
	if (front == nullptr) {
		return;
	}
	ListNode* current = front;
	while (current != nullptr) {
		bool duplicate = false;
		while (current->next != nullptr && current->data == current->next->data) {
			duplicate = true;
			current = current->next;
		}
		if (duplicate == true) {
			addValue(dupList, current->data);
		}
		current = current->next;
	}
	while (dupList != nullptr) {
		removeAll(front, dupList->data);
		dupList = dupList->next;
	}
}
int main() {
	ListNode* n = nullptr;

	addValue(n, 1);
	addValue(n, 1);
	addValue(n, 1);
	addValue(n, 3);
	addValue(n, 3);
	addValue(n, 6);
	addValue(n, 7);
	addValue(n, 7);
	addValue(n, 9);
	addValue(n, 15);
	addValue(n, 23);
	addValue(n, 40);
	addValue(n, 40);
	cout << "Original List: ";
	printData(n);
	cout << endl;

	removeDuplicate(n);
	cout << "After removal List: ";
	printData(n);
	cout << endl;

	return 0;
}
