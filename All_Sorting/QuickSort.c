//Quick Sort using Recursion :
#include<stdio.h>
#include<stdlib.h>

//Function used for Displaying Array :
void displayArray (int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    printf("]\n");
}
//Partition Function(Backbone of the Quick Sort) used for Dividing the Array into two halves according to the Pivot Element :
int partition (int *a, int lb, int ub)
{
    int pivotElement = a[lb], temp;
    int start = lb, end = ub;
    while (start < end)
    {
        while (a[start] <= pivotElement)
        {
            start++;
        }
        while (a[end] > pivotElement)
        {
            end--;
        }
        if (start < end)
        {//Swapping of the Elements in Start & end Positions :
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    //Final Swapping of the Pivot Element :
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;

    return end;
}
//Implementing Quick Sort :
void quickSort (int *a, int lb, int ub)
{
    if (lb < ub)
    {
        int pivot = partition(a, lb, ub);//Calling Partition Function to Create partition according to the Pivot Element :
        quickSort(a, lb, pivot - 1);//Recurssive call
        quickSort(a, pivot + 1, ub);//Recurssive Call
    }
}
//Main Function :
int main ()
{
    int len, i;
    printf("Enter the length of the Array : ");
    scanf("%d",&len);
    //Declaring & Initializing an Array of length 'len' Dinamically :
    int *a = (int *)malloc(len * sizeof(int));
    //Taking the Input Elements of the Array from the User :
    printf("\nEnter the Elements of the Array : \n");
    //Inserting the Input Elements into the Array :
    for (i = 0; i < len; i++)
    {
        printf("(%d) --> ",i+1);
        scanf("%d",&a[i]);
    }
    //Displaying the Array before Sorting :
    printf("\nThe Elements of the Array before Sorting : [ ");
    displayArray(a, len);
    //Calling quickSort :
    quickSort(a, 0, len - 1);
    //Displaying the Array after Sorting :
    printf("\nThe Elements of the Array after Sorting : [");
    displayArray(a, len);

    return 0;
}