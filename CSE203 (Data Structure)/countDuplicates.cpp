#include<iostream>

using namespace std;
int countDuplicates(int a1[], int a) {
    int count = 0;
    for (int i = 0; i < a; ++i) {
        for (int j = i+1; j < a; ++j) {
            if (a1[i] == a1[j]) {
                ++count;
                break;
            }
        }
    }
    return count;
}
int main() {
    int a1[] = { 1, 4, 2, 4, 7, 1, 1, 9, 2, 3, 4, 1 };
    int a = 12;
    cout << countDuplicates(a1, a) << endl;

    return 0;
}
