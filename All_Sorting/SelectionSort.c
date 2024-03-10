#include<stdio.h>
#include<stdlib.h>

//Function for Selection Sort :
void selectionSort(int a[],int len){
    int min,min_index,temp,i,j;
    for(i = 0;i < len;i++){
        min = a[i];
        for(j = i+1;j < len;j++){
            //Finding the min element :
            if(min > a[j]){
            min = a[j];
            min_index = j;
            }
        }
        //Swaping the min element with the ith element :
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;

    }
}
//Function for Displaying the Arrqy :
void displayArray(int a[],int len){
    for(int i = 0;i < len;i++){
        printf("\t%d",a[i]);
    }
    printf("\n");
}
//Main Function :
void main(){
    int len,i;
    printf("Enter the length of the Array : ");
    scanf("%d",&len);
    int *a = (int *)malloc(len * sizeof(int));
    printf("Enter the elements of the Array :\n");
    for(i = 0;i < len;i++){
        scanf("%d",&a[i]);
    }
    //Displaying the Array before Sorting :
    printf("The Unsorted Array : ");
    displayArray(a,len);
    //Calling selectionSort :
    selectionSort(a,len);
    //Displaying the Array before Sorting :
    printf("The Sorted Array : ");
    displayArray(a,len);
}