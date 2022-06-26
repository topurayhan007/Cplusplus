#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    int index = 0;
    for (int i = 0; i<s.length(); ++i) {
        if ((s[i] == 'H' || s[i] == 'h') && index==0) {
            index=1;
        }
        else if ((s[i] == 'A' || s[i] == 'a') && index==1) {
            index=2;
        }
        else if ((s[i] == 'C' || s[i] == 'c') && index==2) {
            index=3;
        }
        else if ((s[i] == 'K' || s[i] == 'k') && index==3) {
            index=4;
        }
        else if ((s[i] == 'E' || s[i] == 'e') && index==4) {
            index=5;
        }
        else if ((s[i] == 'R' || s[i] == 'r') && index==5) {
            index=6;
        }
        else if ((s[i] == 'R' || s[i] == 'r') && index==6) {
            index=7;
        }
        else if ((s[i] == 'A' || s[i] == 'a') && index==7) {
            index=8;
        }
        else if ((s[i] == 'N' || s[i] == 'n') && index==8) {
            index=9;
        }
        else if ((s[i] == 'K' || s[i] == 'k') && index==9) {
            index=10;
        }
    }
    if (index == 10) {
        return "YES";
    }
    else{
        return "NO";
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
