//DSA with Vishal -  Diagonal sum




#include<iostream>
#include<climits>
using namespace std;


int diagonalSum(int mat[][4], int n){  //TC- O(n * n) - O(n^2)
    int sum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                sum += mat[i][j];
            } else if (j == n-i-1){
                sum += mat[i][j];
            }
        }
    }
    return sum;
    }

    int diagSum(int mat[][4], int n){  //TC- O(n)
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += mat[i][i];
            if(i != n-i-1){
                sum += mat[i][i];
            }
    }
    return sum;
    }



int main(){

    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4;

    cout << diagSum(matrix, n) << endl;

    return 0;
}