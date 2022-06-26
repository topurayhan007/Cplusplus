#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int k = n - 1; k > i; --k)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; ++j)
        {
            cout << char(219);
        }
        cout << '\n';
    }
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
