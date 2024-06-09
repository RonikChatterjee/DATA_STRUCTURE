// Graph Traversal: Depth First Search (DFS)
#include<stdio.h>
#include<stdlib.h>

void findDFS(int** graph, int edges, int root){
    int top = -1;
    int* stack = (int*)malloc(edges * sizeof(int));
    //Creating the visited array
    int* visited = (int*)malloc(edges * sizeof(int));
    //Inisialising the visited array with 0
    for(int i=0;i<edges;i++){
        visited[i] = 0;
    }
    stack[++top] = root;
    visited[root] = 1;
    printf("The DFS traversal of the tree is: [ %d ", root);
    //BFS Traversal
    while(top != -1){
        int flag = 0;
        for(int i = 0;i < edges;i++){
            if(graph[stack[top]][i] == 1 && visited[i] == 0){
                stack[++top] = i;
                visited[i] = 1;
                flag = 1;
                printf("%d ",stack[top]);
                break;
            }
        }
        if(flag == 0){
            top--;
        }
    }
    printf("]\n");
}

void main(){
    int edges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d",&edges);
    //Creating the adjacency matrix
    int** graph = (int**)malloc(edges * sizeof(int*));
    for(int i=0;i<edges;i++){
        graph[i] = (int*)malloc(edges * sizeof(int));
    }
    //Initialising the adjacency matrix
    printf("Inisialize the adjacency matrix:\n");
    for(int i=0;i<edges;i++){
        printf("Initialize the connecting edges (using 1/0) with vertex (%d): ", i);
        for(int j=0;j<edges;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    //Printing the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i=0;i<edges;i++){
        printf("(%d) --> [", i);
        for(int j=0;j<edges;j++){
            printf("%d ",graph[i][j]);
        }
        printf("]\n");
    }
    //Taking the root node orr starting node as input
    int root;
    printf("Enter the root or starting node: ");
    scanf("%d",&root);
    //calling findBFS
    findDFS(graph, edges, root);
}
