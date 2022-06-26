#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void collapsePairs(int arr[], int x) {
    int y = 0;

    if (x % 2 == 0) {
        for (int i = 0; i < x; i = i + 2) {
            y = arr[i] + arr[i + 1];
            if (y % 2 == 0 || y == 1) {
                arr[i] = y;
                arr[i + 1] = 0;
            }
            else{
                arr[i] = 0;
                arr[i + 1] = y;
            }
            y = 0;
        }
    }
    else{
        if (arr[x - 1] % 2 == 0 && (x - 1) % 2 != 0) {
            arr[x - 1] = 0;
        }
        if (arr[x - 1] == 1) {
            arr[x - 1] = 1;
        }
        for (int i = 0; i < x - 1; i += 2) {
            y = arr[i] + arr[i + 1];
            if (y % 2 == 0 || y == 1) {
                arr[i] = y;
                arr[i + 1] = 0;
            }
            else{
                arr[i] = 0;
                arr[i + 1] = y;
            }
            y = 0;
        }
    }
    for (int i = 0; i < x; i++) {
        cout << arr[i];
        if (i != x - 1) {
            cout << ",";
        }
    }
}
int main() {
    string str = "C:/Users/topur/OneDrive/Desktop/sun.txt";
    cout << flipAndReverseLines(str);


    return 0;
}
