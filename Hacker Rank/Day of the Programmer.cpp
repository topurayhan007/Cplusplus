#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    vector<int> y29 = {31,29,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> y28 = {31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap = 244; int nleap =243;
    if(year == 1918){
        return  to_string(256-leap)+ ".09."+ to_string(year);
    }
    else if ((year < 1918 && year%4==0) || (year > 1918 && (year%400==0 || (year%4==0 && !year%100==0)))){
        return  to_string(256-leap)+ ".09."+ to_string(year);
    }
    else {
        return to_string(256-nleap)+ ".09."+ to_string(year);
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
