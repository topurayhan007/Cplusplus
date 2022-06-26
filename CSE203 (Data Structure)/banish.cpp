#include<iostream>
using namespace std;
void shift(int oldArr[], int sz) {
    int x = oldArr[0];
    for (int i = 0; i < sz; ++i) {
        if (i + 1 == sz) { break; }
        oldArr[i] = oldArr[i + 1];
    }
    oldArr[sz - 1] = x;
}
void banish(int a1[], int a, int a2[], int b) {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (a1[i] == a2[j]) {
                for (int k = i; k < a - 1; ++k) {
                    a1[k] = a1[k + 1];
                }
                a1[a - 1] = 0;
                j = -1;
            }
        }
    }
}
int main() {
    int a1[] = { 42,3,9,42,42,0,42,9,42,42,17,8,2222,4,9,0,1 };
    int a2[] = { 42,2222,9 };
    banish(a1, 17, a2, 3);

    for (int i = 0; i < 17; ++i) {
        cout << a1[i] << ", ";
    }

    return 0;
}
