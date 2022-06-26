#include <iostream>
#include <cstdlib>
using namespace std;

int const row= 4; int const col =4;
void printMatrix(int matrix[][4], int row, int col){
     for (int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
                matrix[i][j]=rand()%10;
                cout <<matrix[i][j]<<" ";
        }
        cout<<endl;
     }
}
 void swapMatrix(int matrix[row][col]){
    int swapM[row][col];
    for (int i = 0; i<row; i++){
            for (int j=0; j<col; j++){
                if (swapM[i][j]= matrix[row-j-1][col-i-1]){
                    cout<<swapM[i][j]<<" ";
                }
            }
            cout<<endl;
    }
         cout<<endl;
}
int main() {
    int matrix [row][col];
    printMatrix(matrix,row,col);
    cout<<endl;
    swapMatrix(matrix);

    return 0;
}
