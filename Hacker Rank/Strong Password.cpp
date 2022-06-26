#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int lower =0, upper = 0, num = 0, spec = 0, mChar=0;; 
        for(int i=0; i<password.length(); ++i){
            if(password[i]>='a' and password[i]<='z'){
                lower = 1;
            }
            else if(password[i]>='A' and password[i]<='Z'){
                 upper = 1;
            }
            else if(password[i]>='0' and password[i]<='9'){
                 num = 1;
            }
            else {
                spec = 1;
            }
        }
        mChar = (!spec) + (!num) + (!upper) + (!lower);
        
    if(mChar+n <6){
        return mChar+(6-n-mChar);
    }
    else{
        return mChar;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
