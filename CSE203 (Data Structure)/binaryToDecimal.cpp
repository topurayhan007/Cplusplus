#include<iostream>
using namespace std;

int binaryToDecimal(int bin) {
    int a = 0; int dec = 0; int i = 0;
    while (bin != 0) {
        int a = bin % 10;
        dec = dec + a * pow(2, i);
        ++i;
        bin = bin / 10;
    }
    return dec;
}
int main() {
    int x = 0;
    cout << "Enter a binary number: ";
    cin >> x;
    cout<<binaryToDecimal(x)<<endl;

    return 0;
}
