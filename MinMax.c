#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void findMinMax(int* A, int size, int lb, int* B){
    if(lb == size){
        return;
    }
    else if(lb < size){
        if(A[lb] < B[0]){
            B[0] = A[lb];
        }
        if(A[lb] > B[1]){
            B[1] = A[lb];
        }
        lb++;
        findMinMax(A, size, lb, B);
    }
}

int main(){
    int* min_max = (int*)malloc(2*sizeof(int));
    //0th index for min and 1st index for max
    min_max[0] = INT_MAX, min_max[1] = INT_MIN;
    int size;
    printf("Enter the size of the array to be sorted: ");
    scanf("%d",&size);
    printf("Enter the elements of the array to be sorted:\n");
    int* array = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        printf("(%d) --> ",i+1);
        scanf("%d",&array[i]);
    }
    printf("Array: --> [ ");
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
    findMinMax(array, size, 0, min_max);
    printf("Minimum Element: --> %d\nMaximum Element: --> %d\n", min_max[0], min_max[1]);
    return 0;
}
