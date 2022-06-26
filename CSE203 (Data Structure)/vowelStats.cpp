#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void vowelStats(string str1) {
    ifstream myFile(str1);
    string str;
    if (myFile.is_open()) {
        int x = 0;
        double total = 0;
        int longest = 0;
        int count = 0;
        int vcount = 0;
        for (int i = 1; getline(myFile, str); ++i) {
            int len = str.length();
            total += len;
            //Vowel count
            int count = 0;
            for (int i = 0; i < str.length(); ++i) {
                if ((str[i]) == 'a' || (str[i]) == 'e' || (str[i]) == 'i' || (str[i]) == 'o' || (str[i]) == 'u' ||
                    (str[i]) == 'A' || (str[i]) == 'E' || (str[i]) == 'I' || (str[i]) == 'O' || (str[i]) == 'U') {
                    ++count;
                }
            }
            cout << "Line " << i << " has " << len << " chars" << " and " << count << " vowels" << endl;

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
    vowelStats(str);


    return 0;
}
