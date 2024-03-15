//Complete Representation of Simple Linked List :
#include<stdio.h>
#include<stdlib.h>
//Creating the structure of each node of the Linked List :
typedef struct LinkedList
{
    struct LinkedList* next;
    int data;
} ll;
//Globally initializing the the pointers to the linked List : 
ll* head = NULL;
ll* tail = NULL;
ll* temp = NULL;
ll* prev = NULL;
//Function which returns 0 if the list is empty or returns the length of the list :
int findLength ()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int count = 0;
        temp = head;
        while (temp != tail->next)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
}
//Function used to insert a node at the end of the list :
void insertAtEnd ()
{
    int info;
    ll* newnode = (ll *)malloc(sizeof(ll));
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&info);
        head->data = info;
        tail = head;
        printf("\nList is Created sucessfully !!!\n");
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        printf("\nEnter the element to be inserted at the end : ");
        scanf("%d",&info);
        tail->data = info;
        printf("\n%d is inserted successfully at the end !!!",info);
    }
    
}
//Function used to insert a node at the begining of the list :
void insertAtStart ()
{
    int info;
    ll* newnode = (ll*)malloc(sizeof(ll));
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&info);
        head->data = info;
        tail = head;
        printf("\nList is Created sucessfully !!!\n");
    }
    else
    {
        newnode->next = head;
        head = newnode;
        printf("\nEnter the element to be inserted at begining : ");
        scanf("%d",&info);
        head->data = info;
        printf("\n%d is inserted successfully at the begining !!!",info);
    }
}
//Function used to insert a node at the given position of the list only if the position is valid :
void insertAtPos ()
{
    int len = findLength();
    int pos;
    printf("\nEnter the position where the element is to be inserted : ");
    scanf("%d",&pos);
    if (pos > 1 && pos < len + 1)
    {
        int index = 1, info;
        printf("Enter the element to be inserted : ");
        scanf("%d",&info);
        temp = head;
        while (index < pos - 1)
        {
            temp = temp->next;
            index++;
        }
        ll* newnode = (ll*)malloc(sizeof(ll));
        newnode->data = info;
        newnode->next = temp->next;
        temp->next = newnode;
        printf("\n%d is inserted in the position %d successfully !!!\n", info, pos);
    }
    else if (pos == 1)
    {
        insertAtStart();
    }
    else if (pos == len + 1)
    {
        insertAtEnd();
    }
    else
    {
        printf("\nInvalid Position. Please enter a correct position !!!\n");
    }  
}
//Function used to delete the last node from the list only if the list is not empty :
void deleteAtEnd ()
{
    if (tail == NULL)
    {
        printf("List is already empty !!!");
    }
    else
    {
        temp = head;
        while (temp->next != tail)
        {
            prev = temp;
            temp = temp->next;
        }
        tail = prev;
        printf("\n%d is successfully deleted :\n", temp->data);
        free(temp);
    }
}
//Function used to delete the first node from the list only if the list is not empty :
void deleteAtStart ()
{
    if (head == NULL)
    {
        printf("List is already empty !!!");
    }
    else
    {
        temp = head;
        head = head->next;
        printf("\n%d is deleted sucessfully !!!\n", temp->data);
        free(temp);
    }
}
//Function used to delete the node according to the position given by user from the list only if the list is not empty :
void deleteAtPos ()
{
    if (head == NULL)
    {
        printf("List is already empty !!!");
    }
    else
    {
        int pos;
        int len = findLength();
        printf("\nEnter the position where the  element is to be deleted : ");
        scanf("%d",&pos);
        if (pos == 1)
        {
            deleteAtStart();
        }
        else if (pos == len)
        {
            deleteAtEnd();
        }
        else if (pos < 1 && pos > len)
        {
            int index = 0;
            temp = head;
            while (index < pos - 1)
            {
                prev = temp;
                temp = temp->next;
                index++;
            }
            prev->next = temp->next;
            printf("\n%d is deleted sucessfully from position->%d !!!\n", temp->data, pos);
            free(temp);
        }
        else
        {
            printf("\nInvalid Position. Please enter a correct position !!!\n");
        }
    } 
}
//Function used for searching the given element in the list :
void search ()
{
    if (head != NULL)
    {
        int info, count = 0, flag = 0;
        printf("Enter the elements to be searched :");
        scanf("%d",&info);
        temp = head;
        while (temp != tail->next)
        {
            if (temp->data == info)
            {
                flag = 1;
                printf("\nThe element is found at position->%d\n",count + 1);
                break;
            }
            else
            {
                temp = temp->next;
            }
            count++;
        }
        if (flag == 0)
        {
            printf("%d not found in the list !!!",info);
        }
        
    }
    else
    {
        printf("List is already empty !!!");
    }
}
//Function displaying the content of the Linked List :
void displayList ()
{
    if (head != NULL)
    {
        temp = head;
        printf("\nThe List is:\n");
        while (temp != tail->next)
        {
            printf("  %d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
                printf("\nThe list is empty !!!\n");
    }
}
//Functions displaying the options to the user :
void displayOption ()
{
    printf("\n01.\tInsert at the End\n02.\tInsert at the Begining\n03.\tInsert at the given Position\n04.\tDelete from End\n05.\tDelete from Begining\n06.\tDelete from the given Position\n07.\tSearch\n8.\tCheck Length\n09.\tDisplay List\n10.\tExit\nEnter Your Choice : ");
}
//Main Function :
int main () 
{
    int choice;
    while (1)//infinite loop
    {
        displayOption();
        scanf("%d",&choice);
        switch (choice)//initiating switch case on the basis of the value in the choice variable
        {
        case 1:
            insertAtEnd();
            break;

        case 2:
            insertAtStart();
            break;

        case 3:
            insertAtPos();
            break;

        case 4:
            deleteAtEnd();
            break;

        case 5:
            deleteAtStart();
            break;

        case 6:
            deleteAtPos();
            break;

        case 7:
            search();
            break;
        
        case 8:
            int len = findLength();
            printf("\nThe length of the list is %d.\n", len);
            break;

        case 9:
            displayList();
            break;

        case 10:
            exit(0);//Exits from the infinite Loop
            break;
        default:
            break;
        }
    }
}