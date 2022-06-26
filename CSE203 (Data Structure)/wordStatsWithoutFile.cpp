#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void wordStats(string str) {
    ifstream myFile(str);
    if (!myFile.is_open()) {
        cout << "Error, bad input file." << endl;
    }
    //Word count and total word letter count
    stringstream ss;
    ss << str;
    string word = "";
    string s = "";
    float countw = 0;
    while (ss >> word) {
        ++countw;
        s = word + s;
    }
    float w = s.length();
    cout << "Total words    = " << countw << endl;
    float avg = w / countw;
    cout << "Average length = " << avg << endl;

    /*//Letter count
    int a = str.length();
    int count = 0;
    for (int i = 0; i < a; ++i) {
        if (isalpha(str[i])) {
            ++count;
        }
    }
    cout << "Total letters    = " << count << endl;
    */

    //Unique Letters
    int a = str.length();
    int alphabet[26];
    for (int i = 0; i < 26; ++i) {
        alphabet[i] = 0;
    }

    for (int i = 0; i < a; ++i) {
        if (isalpha(str[i])) {
            int x = tolower(str[i]) % 97;
            alphabet[x] += 1;
        }

    }
    int unique = 0;
    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] >= 1) {
            ++unique;
        }
    }
    cout << "Unique letters = "<< unique << endl;

    myFile.close();
}
int main() {
    string str = "To be  or not  TO BE,    THAT IS   the question.";
    wordStats(str);


    return 0;
}
