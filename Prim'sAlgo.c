#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int key[], int mstSet[], int size) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[100][100], int size) {
    int totalWeight =0;
    int weight;
    printf("Edge \tWeight\n");
    for (int i = 1; i < size; i++){
            weight = graph[i][parent[i]];
        printf("%d - %d \t%d \n", parent[i], i,weight );
        totalWeight+=weight;
    }
    printf("Total weight -> %d",totalWeight);
}

void primMST(int graph[100][100], int size) {
    int parent[size];
    int key[size];
    int mstSet[size];

    for (int i = 0; i < size; i++){
        key[i] = INT_MAX, mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < size - 1; count++) {
        int u = minKey(key, mstSet, size);
        mstSet[u] = 1;
        for (int v = 0; v < size; v++){
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]){
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, size);
}
int main() {
/*int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    */
    int size;
    printf("Enter no. of vertices : ");
    scanf("%d",&size);
    int graph[100][100];
    printf("Enter Adjacency Matrix :\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    primMST(graph,size);
    return 0;
}