#include <iostream>
#include <cstdlib>

using namespace std;

void printMatrix(int matrix[][5], int row, int col){
     for (int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
                matrix[i][j]=rand()%10;
            cout <<matrix[i][j]<<" ";

        }
        cout<<endl;
     }
}
void diffMatrix(int matrix[][5],int row, int col){
    int sumOdd=0;int sumEven=0;int difference=0;
     for (int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            if((i+j)%2 != 0){
                sumOdd = sumOdd + matrix[i][j];
            }
            else{
                sumEven = sumEven + matrix[i][j];
            }
        }

    }
    cout<<"Sum of odds: "<<sumOdd<<endl;
    cout<<"Sum of evens: "<<sumEven<<endl;
    difference = sumOdd - sumEven;
    cout <<"Difference is: "<<difference;
}

int main(){
    const int row=5;
    const int col=5;
    int matrix[row][col];
    printMatrix(matrix,row,col);
    diffMatrix(matrix,row,col);
    return 0;
}
