#include<stdio.h>
#include<stdlib.h>

void binarySearch(int array[], int lb, int ub, int target){
    if(lb > ub){
        printf("Element not found in the array\n");
        return;
    }else{
        int mid = (lb + ub) / 2;
        if(array[mid] == target){
            printf("%d found at index %d\n", target, mid);
        }else if (array[mid] > target){
            binarySearch(array, lb, mid-1, target);
        }else{
            binarySearch(array, mid+1, ub, target);
        }
    }    
}

void main(){
    int size,target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));
    printf("Enter the elements of the array in sorted(increasing) orders:\n");
    for(int i = 0; i < size; i++){
        printf("(%d) --> ", i);
        scanf("%d", &array[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &target);
    binarySearch(array, 0, size-1, target);
}