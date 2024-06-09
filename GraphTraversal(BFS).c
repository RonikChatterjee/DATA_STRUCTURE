// Graph Traversal: Breadth First Search (BFS)
#include<stdio.h>
#include<stdlib.h>

void findBFS(int** graph, int edges, int root){
    int front = 0, rear = 0;
    int* queue = (int*)malloc(edges * sizeof(int));
    //Creating the visited array
    int* visited = (int*)malloc(edges * sizeof(int));
    //Inisialising the visited array with 0
    for(int i=0;i<edges;i++){
        visited[i] = 0;
    }
    //Enqueue the root node
    visited[root] = 1;
    queue[rear] = root;
    rear++;
    printf("The BFS traversal of the tree is: [ ");
    //BFS Traversal
    while(front != rear){
        for(int i = 0;i < edges;i++){
            if(graph[queue[front]][i] == 1 && visited[i] == 0){
                queue[rear] = i;
                visited[i] = 1;
                rear++; 
            }
        }
        printf("%d ",queue[front]);
        front++;
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
    findBFS(graph, edges, root);
}