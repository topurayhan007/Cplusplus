#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

void numberSquare(int min, int max) {
    int count1 = 0;
    for (int i = min; i <= max; ++i) {
        int count2 = 0;
        for (int j = min; j <= max; ++j) {
            if ((j + count1) > max) {
                cout << min + count2;
                ++count2;
            }
            else {
                cout << j + count1;
            }
        }
        ++count1;
        cout << endl;
    }

}
int main() {
    int x = 0;
    cout << "Min: ";
    cin >> x;
    int y = 0;
    cout << "Max: ";
    cin >> y;
    numberSquare(x, y);
    return 0;
}
