#include<stdio.h>
#include<stdlib.h>

//Function for implementing Insertion Sort
void insertionSort(int a[],int len){
    int i,j,temp;
    for(i = 1;i < len;i++){
        temp = a[i];
        /*for(j = i-1;j >= 0 && a[j] > temp;j--){
            a[j + 1] = a[j];
        }
        */
       //This for loop can be replaced by the above mentioned loop and also by the bellow mentioed loop
        for(j = i-1;j >= 0;j--){
            if(a[j] > temp){
                a[j + 1] = a[j];
            }else{
                break;
            }
        }
        /*j = i - 1;
        while(j >= 0 && a[j] > temp){
            a[j + 1] = a[j];
            j--;
        }
        */
        a[j + 1] = temp;
    }
}

//Function  for displaying the Array
void display(int a[],int len){
    for(int i = 0;i < len;i++){
        printf("%d\t",*(a+i));
    }
    printf("\n");
}

//Main Function
void main(){
    int len,i,*a;
    printf("Enter the size of the Array: ");
    scanf("%d",&len);
    a = (int *)malloc(len * sizeof(int));
    //Taking the value of the Array from the user
    printf("Enter the elements of the Array: \n");
    for(i = 0;i < len;i++){
        scanf("%d",&a[i]);
    }
    //Displaying the Array before sorting
    printf("The unsorted array is : ");
    display(a,len);
    //Applying Insertion Sort algorithm
    insertionSort(a,len);
    //Displaying the Array after sorting
    printf("The sorted array is : ");
    display(a,len);
}