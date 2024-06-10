#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void matrixChainMultiplication(int* dim, int n){
    //Creating dp matrix
    int** dp = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        dp[i] = (int*)malloc(n * sizeof(int));
    }
    //Initialising dp matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 0;
        }
    }
    //Filling the dp matrix
    for(int l = 2; l < n; l++){
        for(int row = 0, col = l; row < n-l, col < n; row++, col++){
            dp[row][col] = INT_MAX;
            for(int k = row+1; k < col; k++){
                int temp = dp[row][k] + dp[k][col] + (dim[row] * dim[k] * dim[col]);
                if(temp < dp[row][col]){
                    dp[row][col] = temp;
                }
            }
        }
    }
    //Printing the minimum number of multiplications
    printf("Minimum number of multiplications: --> %d\n", dp[0][n-1]);
    //Freeing the dp matrix
    for(int i = 0; i < n; i++){
        free(dp[i]);
    }
}

void main(){
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    n++;
    int* dimention = (int*)malloc(n*sizeof(int));
    printf("Enter the dimention of matrices:\n");
    for(int i=0; i<n; i++){
        printf("(P%d) --> ", i);
        scanf("%d", &dimention[i]);
    }
    matrixChainMultiplication(dimention, n);
    free(dimention);
}