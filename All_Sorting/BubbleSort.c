#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[],int len){
    int i,j,temp;
    for(i = 0;i < len;i++){
        for(j = i + 1;j < len;j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void display(int a[],int len){
    int i;
    for(i = 0;i < len;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void main(){
    int len,*a,i;
    printf("Enter the size of the Array : ");
    scanf("%d",&len);
    a = (int*)malloc(len * sizeof(int));
    printf("Enter the values to be inserted in the Array : \n");
    for(i = 0;i < len;i++){
        scanf("%d",&a[i]);
    }
    printf("The Array before sorting is : \n");
    display(a,len);
    bubbleSort(a,len);
    printf("The Array after sorting(Bubble Sort) is : \n");
    display(a,len);
}