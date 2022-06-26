#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void wordStats(string str1) {
    ifstream myFile(str1);
    if (!myFile.is_open()) {
        cout << "Error, bad input file." << endl;
    }
    else{
    string str;
    float countw = 0;
    int countl=0;
    float w = 0;
    int unique = 0;
    while (getline(myFile, str)) {
        //Word count and total word letter count
        stringstream ss;
        ss << str;
        string word = "";
        string s = "";
        float cntw = 0;
        while (ss >> word) {
            ++cntw;
            s = word + s;
        }
        float pw = s.length();
        w += pw;
        countw += cntw;

        //Unique Letters
        int a = s.length();
        int alphabet[26];
        for (int i = 0; i < 26; ++i) {
            alphabet[i] = 0;
        }
        for (int i = 0; i < a; ++i) {
            if (isalpha(s[i])) {
                int x = tolower(s[i]) % 97;
                alphabet[x] += 1;
            }
        }
        int uniqueO = 0;
        for (int i = 0; i < 26; ++i) {
            if (alphabet[i] >= 1) {
                ++uniqueO;
            }
        }
        unique += uniqueO;

    }
    cout << "Total words    = " << countw << endl;
    float avg = w / countw;
    cout << "Average length = " << avg << endl;
    cout << "Unique letters = " << unique << endl;
    }
    myFile.close();
}
int main() {
    string str = "C:/Users/topur/OneDrive/Desktop/sun.txt";
    wordStats(str);


    return 0;
}
