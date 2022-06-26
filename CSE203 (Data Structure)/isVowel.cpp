#include<iostream>
#include<string.h>
using namespace std;
bool isVowel(string str) {
    bool returnValue = false;
    int len = str.length();
    if (len > 1) {
        returnValue = false;
    }
    else {
        for (int i = 0; i < 1; ++i) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
                str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
                str[i] == 'O' || str[i] == 'U') {
                returnValue = true;
            }
        }
    }
    return returnValue;
}
int main() {
    string str;
    cout << "Type a string: ";
    cin >> str;
    cout<< isVowel(str);

    return 0;
}
