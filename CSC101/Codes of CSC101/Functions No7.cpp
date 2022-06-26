#include <iostream>

using namespace std;
int HCF(int a, int b){
    int x = 1;
	while(!((x%a ==0) && (x%b ==0))){
		x= x+1;

	}
	return ((a*b)/x);
}
int main() {
    int a = 0;
	cout << "Enter a: ";
	cin >> a;
	int b = 0;
	cout << "Enter b: ";
	cin >> b;

	cout<<"HCF is: "<<HCF(a,b);

	return 0;
}
