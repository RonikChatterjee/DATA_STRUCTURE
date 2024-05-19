#include<stdio.h>
#include<stdlib.h>
//Creating Stucture
typedef struct stack
{
    int data;
    struct stack* prev = NULL;
    struct stack* next = NULL;
}st;

st* head == NULL;
int top = -1;

void push ()
{
    if ()
    {

    }
}

int main ()
{
    int choice;
    
    while (1)
    {
        displayOption();
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            displayStack();
            break;

        case 5:
            search();
            break;

        case 6:
            stackLen();
            break;

        case 7:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
} 