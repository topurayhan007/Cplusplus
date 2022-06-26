#include <iostream>

using namespace std;
int LCM(int a, int b){

	int x = 1;
	while(!((x%a ==0) && (x%b ==0))){
		x= x+1;

	}
	return x;
}
int main() {
    int a = 0;
	cout << "Enter a: ";
	cin >> a;
	int b = 0;
	cout << "Enter b: ";
	cin >> b;

	cout<<"LCM is: "<<LCM(a,b);

	return 0;
}
