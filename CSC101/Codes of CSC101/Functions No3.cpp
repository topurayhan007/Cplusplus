#include <iostream>

using namespace std;
int Factorial(int num) {
	int factorial = 1;
	for (int i = 1; i <= num; ++i) {
		factorial = factorial * i;
	}
	return factorial;
}
int main() {
	int num = 0;
	cout << "Enter a number: ";
	cin >> num;

	cout<<"Factorial is: "<<Factorial(num);

	return 0;
}
