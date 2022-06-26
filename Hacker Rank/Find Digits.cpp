#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int d = n; int count=0;
    for (int i = 0; d != 0; ++i){
        int x = d%10;
        d = d/10;
        if (x!=0){
            if(n%x == 0)
            ++count;
        }
    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
