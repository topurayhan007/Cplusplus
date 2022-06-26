#include <iostream>

using namespace std;
int reversedNumber(int num) {
	int sum = 0; int reversedNum =0;
	for (int i =0; (num!=0); ++i){
		reversedNum = reversedNum*10 + num%10;
		num = num / 10;

	}
	return reversedNum;
}
int main() {
	int num = 0;
	cout << "Enter a number: ";
	cin >> num;

	cout<<"Reversed number is: "<<reversedNumber(num);

	return 0;
}
