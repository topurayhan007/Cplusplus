#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int count = 0;
    for (int i =0; i<s.length(); i++) {
        if(int(s[i]) >= 65 && int(s[i]) <= 90){
            ++count;
        }
    }
    return count+1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
