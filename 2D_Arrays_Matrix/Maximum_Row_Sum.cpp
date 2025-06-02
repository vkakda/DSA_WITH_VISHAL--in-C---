//DSA with Vishal - Maximum Row Sum  +  Maximum col sum

/*

 Visual representation:
                    sum
 Row 0:  1  2  3  -- 6
 Row 1:  4  5  6  -- 15
 Row 2:  7  8  9  -- 24

 Maximum row sum - 24
*/


#include<iostream>
#include<climits>
using namespace std;



int getMaxSum(int mat[][3], int rows, int cols) {
    int maxRowSum = INT_MIN;
    for(int i = 0; i< rows; i++){
        int rowSumI = 0;
        for(int j=0; j<cols; j++){
            rowSumI += mat[i][j];
        }

        maxRowSum = max(maxRowSum, rowSumI);
    }
    return maxRowSum;
}

//Maximum Col Sum
int getColSum(int mat[][3], int rows, int cols){
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

    cout << getMaxSum(matrix, rows, cols) << endl;
    cout << getColSum(matrix, rows, cols) << endl;

    return 0;
}