#include <iostream>
#include <cstdlib>
using namespace std;

void multiplyMatrix() {
	int A[10][10]; int B[10][10]; int C[10][10];
	int r1, c1, r2, c2;

	//Prints Matrix A
	cout << "Enter row and column for the Matrix A: ";
	cin >> r1 >> c1;
	cout << endl << "Matrix A: " << endl;
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c1; ++j) {
			A[i][j] = rand() % 10;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Prints Matrix B
	cout << "Enter row and column for the Matrix B: ";
	cin >> r2 >> c2;
	cout << endl << "Matrix B: " << endl;
	for (int i = 0; i < r2; ++i) {
		for (int j = 0; j < c2; ++j) {
			B[i][j] = rand() % 10;
			cout << B[i][j] << " ";
		}
		cout << endl;
	}

	//Multiply Matrix A&B and prints C
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
			C[i][j] = 0;
		}
	}
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
			for (int k = 0; k < c1; ++k) {
				C[i][j] += (A[i][k] * B[k][j]);
			}
		}

	}
	cout << endl << "Matrix C: " << endl;
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j){
            cout << C[i][j] << " ";
			if (j == c2 - 1) {
				cout << endl;
			}
		}
	}

}

int main() {

	multiplyMatrix();

	return 0;
}
