#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string reverseWordOrder(string str) {
    stringstream ss;
    ss << str;

    string word = "";
    string s = "";
    while (ss >> word) {
        s = word + " " + s;
    }
    return s.substr(0,s.length()-1);
}
int main() {
    string str = "Hello what is your name?";
    cout<<reverseWordOrder(str) << endl;

    return 0;
}
