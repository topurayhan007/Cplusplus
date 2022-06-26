//%%writefile Q1.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void writeFinal(string filenameO, int* arr){
    ofstream myFile(filenameO);
     if(myFile.is_open()){
        for (int i=0; i<8; ++i){
            myFile << arr[i] <<" ";
        }
     }
     else{
        cout<<"couldn't open file"<<endl;
        return;
    }
}

void sortTheArray(int* arr){
    int temp = 0;
    for (int i = 0; i < 8; ++i) {
        if (arr[i + 1] % 2 != 0) {
            temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
}


void writeintoArray(string filenameI, int*& arr) {
	ifstream myFile(filenameI);
    int num;
    if(myFile.is_open()){
        arr = new int[8];
        int i = 0;
        while (myFile >> num) {
		arr[i] = num;
		++i;
        }
    }
    else{
        cout<<"couldn't open file"<<endl;
        return;
    }
	myFile.close();

}

void writeFile(string filenameI){
    ofstream myFile(filenameI);
     if(myFile.is_open()){
        for (int i=0; i<8; ++i){
            myFile << rand()%100 <<" ";
        }
     }
     else{
        cout<<"couldn't open file"<<endl;
        return;
    }
}
int main(){
    string filenameI = "input.txt";
    string filenameO = "output.txt";
    int* arr = nullptr;
    writeFile(filenameI);
    writeintoArray(filenameI, arr);
    sortTheArray(arr);
    writeFinal(filenameO,arr);

    delete[] arr;


    return 0;
}
