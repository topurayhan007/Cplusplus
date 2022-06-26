#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

int helper(int n, int& max){
	if(n == 0){
		return 0;
	}
	int x = n % 10;
	helper((n/10), max);
	if (x > max){
		max = x;
	}
	return max;
}
int largestDigit (int n){
	int max = INT32_MIN;
	if(n<0){
		n = n*(-1);
	}
	return helper(n,max);

}


int main(){
	
	cout<<largestDigit(-573026)<<endl;

	return 0;
}