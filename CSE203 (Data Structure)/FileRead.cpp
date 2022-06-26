#include<iostream>
#include <string>
#include<fstream>
using namespace std;
int main() {
    string str = "C:/Users/topur/OneDrive/Documents/sun.txt";  //Path of File | replace'\' by '/'
    ifstream File(str);

    if (!File.is_open()) {
        cout << "Couldn't open file" << endl;
        return -1;
    }
    string line;
    getline(File, line);
    cout << line << endl;

    return 0;
}
