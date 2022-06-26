#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int arr[], int sz) {
    for (int i = 0; i < sz; ++i) {
		arr[i] = rand() % 10;
	}
	cout << "Inputed array is: ";
	for (int i = 0; i < sz; ++i) {
		cout << arr[i]<< ", ";
	}
	cout << "\b" << endl;
}
void max_min_avgArray(int arr[], int sz) {
	//Maximum
	for (int i = 0; i < sz - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			int a = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = a;
		}
	}
	cout << "Maximum is: " << arr[sz - 1] << endl;

	//Minimum
	for (int i = 0; i < sz - 1; ++i) {
		if (arr[i] < arr[i + 1]) {
			int a = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = a;
		}
	}
	cout << "Minimum is: " << arr[sz - 1] << endl;

	//Average
	float sum = 0; int element = 0;
	for (int i = 0; i < sz; ++i) {
		sum = sum + arr[i];
		element = element + 1;
	}
	cout << "Average is: " << sum / element << endl;
}

int main() {
	const int sz = 100;
	int arr[sz];
	printArray(arr,sz);
	max_min_avgArray(arr, sz);
	return 0;
}


