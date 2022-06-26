#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void flipAndReverseLines(){
    string str;
    cout << "Input file name? ";
    cin>>str;
    ifstream myFile(str);
    int z=0;
    for(int i=0;!myFile.is_open(); ++i) {
        cout << "Input file name? ";
        cin>>str;
        if (myFile.is_open()){
            break;
        }
        cout << "Unable to open that file.  Try again." << endl;
    }
    cout << endl;

    int x,y=0;
    string fline="";
    string sline = "";
    while (getline(myFile, fline)) {
        if (getline(myFile, sline)) {
            string s = "";
            for (int i = sline.length()-1; i >= 0; --i) {
                s += toupper(sline[i]);

            }
            cout << s << endl;
            string f = "";
            for (int i = fline.length()-1; i >= 0; --i) {
                f += tolower(fline[i]);

            }
            cout << f << endl;
            ++x;

        }

        else {
            string f = "";
            for (int i = fline.length()-1; i >= 0; --i) {
                f += toupper(fline[i]);

            }
            cout << f << endl;

        }
        ++y;

    }
    z=x+y;

    cout<< z<<endl;

}
int main(){
    cout<<flipAndReverseLines<<endl;
    return 0;

}
