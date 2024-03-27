//Implementing  Stack using Array(Static).
#include<stdio.h>
#include<stdlib.h>
#define max_size 100

int stack[max_size], size, top = -1;//Declaring Globally :

//Function for Constructing Stack :
void createStack ()
{
    printf("\nEnter the size of the stack : ");
    scanf("%d",&size);
    top = -1;
    printf("\nStack of size %d created sucessfully.\n", size);
}
//Function for Performing Push Operation in Stack :
void push ()
{
    if (top < -1 || top >= size )//Error checking condition :
    {
        printf("\n!!! Problem in PUSH operation !!!\n");
    }
    else if (top == (size - 1))//Checking Stack Overflow :
    {
        printf("\n!!! Stack Overflow !!!\n");
    }
    else
    {
        int data;
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&data);
        top++;
        stack[top] = data;
        printf("\n%d is pushed succesfully into the stack.\n",stack[top]); 
    }
}
//Function for Performing Pop Operation :
void pop ()
{
    if (top < -1 || top >= size)//Error checking condition :
    {
        printf("\n!!! Problem in POP operation !!!\n");
    }
    else if (top == -1)//Condition to check Stack Empty :
    {
        printf("\n!!! Stack Empty !!!\n");
    }
    else
    {
        int data;
        data = stack[top];
        top--;
        printf("\n%d is popped out from the stack.\n", data);
    }
}
//Function for Perporming Peek Operation :
void peek ()
{
    if (top < -1 || top >= size)//Error checking condition :
    {
        printf("\n!!! Problem in PEEK operation !!!\n");
    }
    else if (top == -1)//Condition to check Stack Empty :
    {
        printf("\n!!! Stack Empty !!!\n");
    }
    else
    {
        printf("\nTop is at position(%d)->data(%d)\n", top + 1, stack[top]);
    }
}
//Function for Displaying the Stack :
void displayStack ()
{
    if (top < -1 || top >= size)//Error checking condition :
    {
        printf("\n!!! Problem in DISPLAY operation !!!\n");
    }
    else if (top == -1)
    {
        printf("\n!!! Stack Empty !!!\n");
    }
    else
    {
        printf("\nThe Stack is -> ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d  ",stack[i]);
        }
    }
}
//Function for SEARCH operation in the Stack :
void search ()
{
    if (top < -1 || top >= size)//Error checking condition :
    {
        printf("\n!!! Problem in SEARCH operation !!!\n");
    }
    else if (top == -1)
    {
        printf("\n!!! Stack Empty !!!\n");
    }
    else
    {
        int data, count = 0;
        printf("Enter the element to be searched : ");
        scanf("%d",&data);
        for (int i = 0; i <= top; i++)
        {
            if (data == stack[i])
            {
                printf("\n%d is found at position->(%d).\n", stack[i], i+1);
                count++;
            }
        }
        if (count > 0)
        {
            printf("\n%d is found %dtimes in the stack.\n", data, count);
        }
        else
        {
            printf("\n%d is not found in the stack.\n",data);
        }
    }
}
//Function for Finding the Length of the Stack :
void stackLen ()
{
    if (top < -1 || top >= size)//Error checking condition :
    {
        printf("\n!!! Problem in LENGTH operation !!!\n");
    }
    else if (top == -1)//Checking the Empty condition of Stack :
    {
        printf("\nLenght of the Stack->(0)\n");
    }
    else
    {
        printf("\nLength of the Stack->(%d).\nSpace remaining->(%d).\n", top + 1, size - (top + 1));
    }
}
//Displaying the List of Operations :
void displayOption ()
{
    printf("\n1.\tCreate Stack\n2.\tPush\n3.\tPop\n4.\tPeek\n5.\tDisplay\n6.\tSearch\n7.\tLength\n8.\tExit\n");
}

int  main ()
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
            createStack();
            break;
        
        case 2:
            push();
            break;

        case 3:
            pop();
            break;

        case 4:
            peek();
            break;

        case 5:
            displayStack();
            break;

        case 6:
            search();
            break;

        case 7:
            stackLen();
            break;

        case 8:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}