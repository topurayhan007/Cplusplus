#include <iostream>
using namespace std;

void printArray(int arr[], int sz) {
    for (int i = 0; i < sz; ++i) {
		int a = 0;
		cout << i + 1 << "no. array: ";
		cin >> a;
		arr[i] = a;
	}
	cout << "Inputed array is: ";
	for (int i = 0; i < sz; ++i) {
		cout << arr[i]<< " ";
	}
	cout << endl;
}
void forward_backwardArray(int arr[],int sz){
	//Forward array print
	cout << "Forward printed array is: ";
	for (int i = 0; i < sz; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//Backward array print
	cout << "Backward printed array is: ";
	for (int j = sz - 1; j >= 0; --j) {
		cout << arr[j] << " ";
	}
}

int main() {
	const int sz = 5;
	int arr[sz];
	printArray(arr,sz);
	forward_backwardArray(arr, sz);
	return 0;
}
