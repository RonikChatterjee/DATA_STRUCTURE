//Representing a tree using adjacency matrix and traversing it using BFS 
#include<stdioo.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the adjacency matrix of the tree: ");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    int queue[n];
    int front = 0, rear = 0;
    printf("Enter the starting node: ");
    int start;
    scanf("%d", &start);
    queue[rear++] = start;
    visited[start] = 1;
    printf("The BFS traversal of the tree is: ");
    while(front != rear)
    {
        int current = queue[front++];
        printf("%d ", current);
        for(int i=0; i<n; i++)
        {
            if(a[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}