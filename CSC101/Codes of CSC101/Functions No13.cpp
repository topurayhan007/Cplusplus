#include <iostream>
#include <string>
using namespace std;

void lower_to_upperCaseString() {
	string str;
	cout << "Enter a sentence: ";
	getline(cin,str);
	cout << "Sentence you inputed: " << str << endl;
	//Uppercase conversion
	for (int i = 0; i < str.length(); ++i) {
		if (str[i]>=97 && str[i]<=122) {
			str[i] = str[i] - 32;
		}
	}
	cout << "String in Uppercase letter: " << str << endl;
}

int main() {

	lower_to_upperCaseString();
	return 0;
}
