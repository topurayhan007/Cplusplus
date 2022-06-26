#include<iostream>
#include<string>
using namespace std;
string removeAll(string str, char x) {
    int len = str.length();
    string s = ""; string b = "";
    for (int i = 0; i < len; ++i) {
        if (str[i] != x) {
            s = s + str[i];
        }
    }
    return s;
}
int main() {
    string str;
    cout << "Type a string: ";
    getline(cin, str);
    char x;
    cout << "Type a character: ";
    cin >> x;
    cout<<removeAll(str,x)<<endl;

    return 0;
}
