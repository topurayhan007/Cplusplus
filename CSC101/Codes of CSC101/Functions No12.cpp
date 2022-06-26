#include <iostream>
#include <string>
using namespace std;

void Num_letter_wordsString() {
	int letter = 0; int word = 0;
	string str;
	cout << "Enter a sentence: ";
	getline(cin,str);
	cout << "Sentence you inputed: " << str << endl;
	//Letters count
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != ' ') {
			letter = letter + 1;
		}
	}
	cout << "Number of letters in the string: " << letter << endl;
	//Words count
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			word = word + 1;
		}
	}
	cout << "Number of words in the string: " << word +1 << endl;
}

int main() {

	Num_letter_wordsString();
	return 0;
}
