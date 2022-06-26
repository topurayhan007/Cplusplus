#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int flipAndReverseLines(string str) {
    ifstream myFile(str);

    if (!myFile.is_open()) {
        cout << "Unable to open that file.Try again." << endl;
        return -1;
    }
    int x = 0; int y = 0; int z = 0;
    string fline = "";
    string sline = "";
    while (getline(myFile, fline)) {
        if (getline(myFile, sline)) {
            string s = "";
            for (int i = sline.length() - 1; i >= 0; --i) {
                s += toupper(sline[i]);

            }
            cout << s << endl;
            string f = "";
            for (int i = fline.length() - 1; i >= 0; --i) {
                f += tolower(fline[i]);

            }
            cout << f << endl;
            ++x;

        }

        else {
            string f = "";
            for (int i = fline.length() - 1; i >= 0; --i) {
                f += toupper(fline[i]);

            }
            cout << f << endl;

        }
        ++y;

    }
    z = y + x;

    myFile.close();
    return z;

}
int main() {
    string str = "C:/Users/topur/OneDrive/Desktop/sun.txt";
    cout << flipAndReverseLines(str);


    return 0;
}
