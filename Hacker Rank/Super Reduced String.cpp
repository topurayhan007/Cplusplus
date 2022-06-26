#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    
    string a = s;
    int len = a.length();
    for (int i = 0; i < len-1; ++i) {
        if (a[i] == a[i+1]){ 
            return  superReducedString(a.substr(0, i) + a.substr(i+2));
        }    
    }
    
    
    if (a.length() == 0) {
        return "Empty String";
    }
    else{
        return a;
    }
}





int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
