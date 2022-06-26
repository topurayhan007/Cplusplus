#include<iostream>
#include<string>
using namespace std;
string reverseWordOrder(string str) {
    int lenf = str.length();
    string s = "";
    string r = "";
    for (int i = lenf; i > 0; --i) {
        if (str[i] == ' ') {
            for (int j = i+1; j <= lenf; ++j) {
                s = s + str[j];
            }
            lenf = i;
        }
    }
    for (int i = 0; i < lenf; ++i) {
        r = r + str[i];
    }
    return s+r;
}
int main() {
    string str = "Hello what is your name?";
    cout<<reverseWordOrder(str) << endl;

    return 0;
}
