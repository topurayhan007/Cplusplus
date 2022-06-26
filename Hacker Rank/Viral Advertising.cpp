#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int liked = 0; int shared = 5; int total=0;
    for (int i = 0; i < n; ++i) {
        liked = floor(shared/2);
        total +=liked;
        shared = liked*3;
        
    }
    return total;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
