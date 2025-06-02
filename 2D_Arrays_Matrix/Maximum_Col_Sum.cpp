//DSA with Vishal -  Maximum col sum

/*

 Visual representation:
                    
 Row 0:  1  2  3   
 Row 1:  4  5  6  
 Row 2:  7  8  9  

        12 15 18 --  sum

 Maximum col sum - 18
*/


#include<iostream>
#include<climits>
using namespace std;





//Maximum Col Sum
int getMaxColSum(int mat[][3], int rows, int cols){
    int maxColSum = INT_MIN;
    for(int j = 0; j < cols; j++) {
        int colSumJ = 0;
        for(int i = 0; i < rows; i++) {
            colSumJ += mat[i][j];
        }
        maxColSum = max(maxColSum, colSumJ);
    }
    return maxColSum;
    }



int main(){

    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3;
    int cols = 3;

    cout << getMaxColSum(matrix, rows, cols) << endl;

    return 0;
}