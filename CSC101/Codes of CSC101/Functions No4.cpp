#include <iostream>

using namespace std;
int countDigit(int num) {
	int digit = 0;
	for (int i =0; (num!=0); ++i){
		num = num / 10;
		digit = digit + 1;
	}
	return digit;
}
int main() {
	int num = 0;
	cout << "Enter a number: ";
	cin >> num;

	cout<<"Digit is: "<<countDigit(num);

	return 0;
}
