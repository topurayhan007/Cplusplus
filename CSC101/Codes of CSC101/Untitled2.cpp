#include <cstdlib>
void printMatrix(int matrix[][5], int row, int col){
   for (int i=0; i<row; ++i){
      for(int j=0; j<col; ++j){
         matrix[i][j]=rand()%10;
         cout <<matrix[i][j]<<" ";
      }
      cout<<endl;
   }
}
void sumMatrix(int matrix[][5],int row, int col){
int sum =0;
  for (int i=0; i<=4; ++i){
    for(int j=0; j<i; ++j){
        if(i+j>=5){
            sum = sum + matrix[i][j];
        }
    }
  }
  cout <<"Sum of shaded matrix is: "<<sum;
}
int main(){
    const int row=5;
    const int col=5;
    int matrix[row][col];
    printMatrix(matrix,row,col);
    sumMatrix(matrix,row,col);
    return 0;
}
