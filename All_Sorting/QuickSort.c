#include<stdio.h>
#include<stdlib.h>

//Partition Function(Backbone of the Quick Sort) used for Dividing the Array into two halves according to the Pivot Element :
int partition(int* A,int lb, int ub){
    int pivot = lb, start = lb, end = ub;
    while(start < end){
        while(A[start] <= A[pivot]){
            start++;
        }
        while(A[end] > A[pivot]){
            end--;
        }
        if(start < end){
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }
    int temp = A[pivot];
    A[pivot] = A[end];
    A[end] = temp;
    pivot = end;
    return pivot;
}

void quickSort(int* A, int lb, int ub){
    if(lb < ub){
        int pivot = partition(A,lb,ub);
        quickSort(A,lb,pivot-1);
        quickSort(A,pivot+1,ub);
    }
}

void main(){
    int size;
    printf("Enter the size of the array to be sorted: ");
    scanf("%d",&size);
    printf("Enter the elements of the array to be sorted:\n");
    int* array = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        printf("(%d) --> ",i+1);
        scanf("%d",&array[i]);
    }
    printf("Array before sorting: [ ");
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
    quickSort(array,0,size-1);
    printf("Array after sorting: [ ");
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
}