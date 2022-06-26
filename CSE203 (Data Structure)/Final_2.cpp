#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

void fileToBST(string filename) {
	ifstream myFile;
	myFile.open(filename);

	if (myFile.is_open()) {
		float num; string str = "";
		int n; float sum; float count;
		while (myFile >> str) {
			stringstream ss;
			ss<<str;
			
			while(ss>>num){
				cout<<num<<" ";
				sum += num;
				++count;
			}
		}

		cout<<endl;
		cout<<"Sum: "<<sum<<endl;
		cout<<"Count: "<<count<<endl;
		cout<<"Average = "<<sum/count<<endl;

	}
	else {
		cout<<"Couldn't Open File"<<endl;
	}
	myFile.close();
}

int main(){
	string filename = "D:/input.txt";
	
	fileToBST(filename);
	

	return 0;
}