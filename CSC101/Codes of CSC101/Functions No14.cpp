#include <iostream>
#include <string>
using namespace std;

void ID_validation() {
	string ID;
	cout << "Enter your ID: ";
	getline(cin, ID);

	//Converts string to integers
	int id = stoi(ID);
	if (id >= 1000000 && id < 2000000) {
			cout << "True" << endl;
	}
	else {
			cout << "False" << endl;
	}
}

int main() {
	ID_validation();

	return 0;
}
