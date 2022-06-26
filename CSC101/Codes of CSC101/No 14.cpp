#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int x = 0;
	cout << "Enter a number: " << endl;
	cin >> x;
    int y=0;

	for (int i = 1; i < x; ++i) {
		if (x % i == 0) {
			cout << i << ", ";
			y=i;
		}
     }
		cout<<y<< " ";

	return 0;
}
