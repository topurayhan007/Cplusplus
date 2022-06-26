#include <iostream>

using namespace std;
int sumDigit(int num) {
	int sum = 0; int mod =0;
	for (int i =0; (num!=0); ++i){
		mod = num%10;
		num = num / 10;
		sum = sum + mod;
	}
	return sum;
}
int main() {
	int num = 0;
	cout << "Enter a number: ";
	cin >> num;

	cout<<"Sum of digits is: "<<sumDigit(num);

	return 0;
}
