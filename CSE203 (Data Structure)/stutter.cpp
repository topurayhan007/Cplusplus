#include<iostream>
#include<string>
using namespace std;
string stutter(string str) {
    int len = str.length();
    string s = "";
    for (int i = 0; i < len; ++i) {
        s = s + str[i]+ str[i];

    }
    return s;
}
int main() {
    string str;
    cout << "Type a string: ";
    cin>>str;
    cout<<stutter(str)<<endl;

    return 0;
}
