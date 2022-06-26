#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void inputStats(string str1) {
    ifstream myFile(str1);
    string str;
    if (myFile.is_open()) {
        int x = 0;
        double total = 0;
        int longest = 0;
        for (int i = 1; getline(myFile, str); ++i) {
            int len = str.length();
            total += len;
            cout << "Line " << i << " has " << len << " chars" << endl;
            if (len > longest) {
                longest = len;
            }
            x = i;
        }
        cout << x <<" lines;";
        cout << " longest = " << longest << ", average = " << total/x ;


    }
    else {}
    myFile.close();

}
int main() {
    string str = "C:/Users/topur/OneDrive/Desktop/sun.txt";
    inputStats(str);


    return 0;
}
