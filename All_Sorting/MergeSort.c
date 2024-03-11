//Merge Sort using Recursion :
#include<stdio.h>
#include<stdlib.h>

//Function for Displaying the Array :
void displayArray(int *a,int len){
    for(int i = 0; i < len; i++){
        printf("\t%d",a[i]);
    }
    printf("\n");
}

//Function to Merge(Conquer) :
void merge(int *a,int lb,int mid,int ub){
    int i = lb, j = mid+1, k = lb;
    int len = (ub - lb) + 1;
    int b[100];
    //int *b = (int *)malloc(len * sizeof(int));

    while(i <= mid && j <= ub){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;   
        }else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while(j <= ub){
        b[k] = a[j];
        j++;
        k++;
    }
    for(k = 0; k <= ub; k++){
        a[k] = b[k];
    }
}

//Function for MergeSort Sort(Devide) :
void mergeSort(int *a,int lb,int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

//Main Function :
int main(){
    int len, i;
    printf("Enter the length of the Array : ");
    scanf("%d",&len);
    //Declaring & Initializing Array Dinamically :
    int *a = (int *)malloc(len * sizeof(int));
    printf("Enter the elements of the Array :\n");
    //Inserting the Input Elements into the Array :
    for(i = 0; i < len; i++){
        scanf("%d",&a[i]);
    }
    //Displaying the Array before Sorting :
    printf("\nThe Unsorted Array : ");
    displayArray(a, len);
    //Calling mergeSort :
    mergeSort(a, 0, len-1);
    //Displaying the Array before Sorting :
    printf("\nThe Sorted Array : ");
    displayArray(a, len);

    return 0;
}