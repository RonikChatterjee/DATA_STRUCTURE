#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an edge in the graph
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Define a structure to represent a graph
typedef struct Graph {
    int V, E; // V = number of vertices, E = number of edges
    Edge* edges; // Array of edges
} Graph;

// A structure to represent a subset for union-find
typedef struct subset {
    int parent;
    int rank;
} subset;

// Function prototypes
Graph* createGraph(int V, int E);
void addEdge(Graph* graph, int src, int dest, int weight, int edgeIndex);
int find(subset subsets[], int i);
void Union(subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void KruskalMST(Graph* graph);

int main() {
    int V, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int** adjMatrix = (int**)malloc(V * sizeof(int*));
    for (i = 0; i < V; i++) {
        adjMatrix[i] = (int*)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Count the number of edges
    int E = 0;
    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] != 0) {
                E++;
            }
        }
    }

    Graph* graph = createGraph(V, E);

    int edgeIndex = 0;
    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] != 0) {
                addEdge(graph, i, j, adjMatrix[i][j], edgeIndex);
                edgeIndex++;
            }
        }
    }

    KruskalMST(graph);

    // Free allocated memory
    for (i = 0; i < V; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(graph->edges);
    free(graph);

    return 0;
}

// Function to create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight, int edgeIndex) {
    graph->edges[edgeIndex].src = src;
    graph->edges[edgeIndex].dest = dest;
    graph->edges[edgeIndex].weight = weight;
}

// A utility function to find the set of an element i (uses path compression technique)
int find(subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function to sort edges based on their weight
int compare(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V]; // This will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare);

    // Allocate memory for creating V subsets
    subset* subsets = (subset*)malloc(V * sizeof(subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it in the result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    int cost = 0;
    // Print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        cost += result[i].weight;
    }
    printf("Cost of the MST is: %d\n", cost);
    // Free memory
    free(subsets);
}