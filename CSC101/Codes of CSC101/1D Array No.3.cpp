#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int arr[],int sz) {
	int in = 0;
	cout << "Enter the lower limit of the integer array: ";
	cin >> in;
	int out = 0;
	cout << "Enter the upper limit of the integer array: ";
	cin >> out;
    for (int i = 0; i < sz; ++i) {
        int a =0;
        cout<<"Enter a integer: ";
        cin>>a;
        while(a<in || a>out){
            cout<<"Re-enter integer between the range: ";
            cin>>a;
        }
        arr[i]=a;
    }
	cout << "The random array between the range is: ";
	for (int i = 0; i < sz; ++i) {
		cout << arr[i]<< " ";
	}
}

int main() {
	const int row=25;
	const int col=25;
	int arr[row][col];

	printArray(arr,row,col);

	return 0;
}
