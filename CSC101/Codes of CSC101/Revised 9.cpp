#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int x = 0;
	cout << "Enter a number: " << endl;
	cin >> x;

	if (x == 0) {
		cout << x;
	}

	int reversedNum = 0;
	while (x != 0) {
		if (x % 10 == 0) {
			cout << "0" << endl;
		}
		reversedNum = reversedNum * 10 + x % 10;
		x = x / 10;
	}


	int digit = 0;
	while (reversedNum != 0) {
		digit = reversedNum % 10;
		cout << digit << endl;
		reversedNum = reversedNum / 10;
	}

	return 0;
}
