#include <iostream>
#include <string>
#include <fstream>
using namespace std;

float averageValueInFile(string str) {
    //string str is the file path
    ifstream myFile(str);
    if (!myFile.is_open()) {
        return -1;
    }
    float num = 0.0;
    int count = 0;
    float sum = 0;
    while (myFile >> num) {
        ++count;
        sum += num;
    }
    if (count == 0) {
        return 0;
    }
    myFile.close();
    return (sum / count);
}
int main() {
    string str = "path of the file here";
    cout << averageValueInFile << endl;

    return 0;
}
