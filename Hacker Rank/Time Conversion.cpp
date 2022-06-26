#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */

string timeConversion(string s){
    int len = s.length(); 
    string str = " ";
    int hh = stoi(s) + 12;
    str = to_string(hh);

    if (s[len - 2] == 'P' && stoi(s) != 12){
        s[0] = str[0];
        s[1] = str[1];
    }
    if (s[len - 2] == 'A' && stoi(s) == 12){
        s[0] = '0';
        s[1] = '0';
    }
    s.erase(remove(s.begin(), s.end(), 'A'), s.end());
    s.erase(remove(s.begin(), s.end(), 'P'), s.end());
    s.erase(remove(s.begin(), s.end(), 'M'), s.end());
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    cout<<"Enter the 12-hour format(eg: hh:mm:ss PM/AM): ";
    getline(cin, s);

    string result = timeConversion(s);

    cout << "The 24-hour format is: " << result << "\n";

    fout.close();

    return 0;
}
