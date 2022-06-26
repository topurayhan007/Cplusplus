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
void max_min_avgArray(int arr[], int sz) {
	//Maximum
	for (int j = 0; j < sz - 1; ++j) {
		if (arr[j] > arr[j + 1]) {
			int a = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = a;
		}
	}
	cout << "Maximum is: " << arr[sz - 1] << endl;

	//Minimum
	for (int j = 0; j < sz - 1; ++j) {
		if (arr[j] < arr[j + 1]) {
			int a = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = a;
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
	/*int sz = 0;
	cout << "Enter size of array: ";
	cin >> sz;*/
	int const sz = 5;
	int arr[sz];

	//Print array
	printArray(arr, sz);
	cout << endl;

	//Maximum, minimum and average in the array
    max_min_avgArray(arr, sz);

	return 0;
}
