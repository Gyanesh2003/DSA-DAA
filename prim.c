#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

void primMST(int **graph, int n, int startVertex, FILE *outputFile);

int main() {
    FILE *inputFile, *outputFile;
    int n, startVertex;

    inputFile = fopen("prims.dat", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
int i;
int j;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            fscanf(inputFile, "%d", &graph[i][j]);
        }
    }

    fclose(inputFile);
    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    primMST(graph, n, startVertex, stdout);
    outputFile = fopen("primsout.dat", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    primMST(graph, n, startVertex, outputFile); 

    fclose(outputFile);

    for (i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

void primMST(int **graph, int n, int startVertex, FILE *outputFile) {
    int parent[n];  
    int key[n];     

    int mstSet[n];  
int i;
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[startVertex - 1] = 0;  
    parent[startVertex - 1] = -1; 
int count;
    for (count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
int v;
        for (v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
int j;
    fprintf(outputFile, "Cost adjacency matrix of the minimum spanning tree:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fprintf(outputFile, "%d ", graph[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fprintf(outputFile, "\nTotal Weight of the Spanning Tree: ");
    int totalWeight = 0;
    for (i = 1; i < n; i++) {
        fprintf(outputFile, "%d ", parent[i] + 1);
        totalWeight += graph[i][parent[i]];
    }
    fprintf(outputFile, "\nTotal Weight: %d\n", totalWeight);
    printf("Cost adjacency matrix of the minimum spanning tree:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: ");
    for (i = 1; i < n; i++) {
        printf("%d ", parent[i] + 1);
    }
    printf("\nTotal Weight: %d\n", totalWeight);
}
