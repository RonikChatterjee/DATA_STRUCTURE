#include<stdio.h>
void bubbleSort(int a[]){

}
int main(){
    int len,*a,i;
    printf("Enter the size of the Array : ");
    scanf("%d",&len);
    a = (int *)malloc(len * sizeof(int));
    printf("Enter the values to be inserted in the Array : \n");
    for(i = 0;i < len;i++){
        scanf("%d",&a[i]);
    }


}