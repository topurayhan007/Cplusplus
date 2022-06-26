#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int numUnique(int list[], int a){
    int unique = 1;
    if (a == 0) {
        unique = 0;
        return unique;
    }
    else {
        for (int i = 1; i < a; i++) {
            int j = 0;
            for (j = 0; j < i; j++) {
                if (list[i] == list[j]) {
                    break;
                }
            }
            if (i == j) {
                ++unique;
            }
        }
    }
    return unique;
}
int main() {
    int list[] = { 5,7,7,7,8,22,22,23,31,35,35,40,40,40,41 };
    cout << numUnique(list,15) << endl;

    return 0;
}
