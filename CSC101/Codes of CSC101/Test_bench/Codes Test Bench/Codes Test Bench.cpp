// Codes Test Bench.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
string reverseString(string str) {
	int len = str.length();
	string s = "";
	for (int i = len - 1; i >= 0; --i) {
		s = s + str[i];
	}
	return s;
}
int main() {
	string str = "yellow";
	cout << reverseString(str) << endl;
	if (reverseString(str) == str) {
		cout << "palindrome" << endl;
	}
	else {
		cout << "Not palindrome" << endl;
	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
