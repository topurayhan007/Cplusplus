#include<iostream>
using namespace std;

int main() {
    int x = 0; int sum = 0;
    cout << "Type an integer: ";
    cin >> x;
    for (int i = 0; x != 0; ++i) {
        int a = x % 10;
        x = x / 10;
        sum = sum + a;
    }
    cout << "Digit sum is "<<sum;

    return 0;
}
