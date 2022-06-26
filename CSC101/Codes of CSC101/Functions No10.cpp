#include <iostream>
using namespace std;

void printArray(int arr[], int sz) {
	for (int i = 0; i < sz; ++i) {
		int a = 0;
		cout << i + 1 << " no. array: ";
		cin >> a;

		arr[i] = a;
	}
	cout<<"The inputed array is: ";
	for (int i = 0; i < sz; ++i) {
		cout << arr[i] << " ";
	}
}
void sortArray(int arr[], int sz) {
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int a = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = a;
			}
		}
	}
	for (int i = 0; i < sz; ++i) {
		cout << arr[i] << " ";
	}
}
int main() {
    int sz=0;
	cout << "Enter size of array: ";
	cin >> sz;
    int arr[sz];

	//Print array
	printArray(arr, sz);
	cout << endl;

	//Sort array ascending order
	cout << "Sorted array in ascending order: ";
	sortArray(arr, sz);

	return 0;
}
