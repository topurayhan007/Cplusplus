#include<iostream>
using namespace std;

int decimalToBinary(int dec) {
    int bin = 0;
    for (int i = 0; dec != 0; ++i) {
        int mod = (dec % 2) * pow(10, i);
        dec = dec / 2;
        bin = bin + mod;
    }
    return bin;
}
int main() {
    int x = 0; int sum = 0;
    cout << "Enter a Decimal: ";
    cin >> x;
    cout << decimalToBinary(x) << endl;

    return 0;
}
