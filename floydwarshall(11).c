#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void readGraph(FILE *file, int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
	int i,j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
}
int i,j;
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int result[MAX_VERTICES][MAX_VERTICES]) {
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            result[i][j] = graph[i][j];
        }
    }
int k;
    for (k = 0; k < numVertices; k++) {
        for (i = 0; i < numVertices; i++) {
            for (j = 0; j < numVertices; j++) {
                if (result[i][k] != INT_MAX && result[k][j] != INT_MAX && result[i][k] + result[k][j] < result[i][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
}

void findShortestPath(int result[MAX_VERTICES][MAX_VERTICES], int source, int destination) {
    printf("Shortest Path from vertex %d to vertex %d: %d\n", source, destination, result[source - 1][destination - 1]);

    if (result[source - 1][destination - 1] == INT_MAX) {
        printf("No path exists.\n");
        return;
    }

    printf("Path: %d", source);
int i;
    int intermediate = destination;
    while (intermediate != source) {
        for (i = 0; i < MAX_VERTICES; i++) {
            if (result[source - 1][intermediate - 1] == result[source - 1][i] + result[i][intermediate - 1]) {
                printf(" --> %d", i + 1);
                intermediate = i + 1;
                if (intermediate == destination) {
                    break;
                }
            }
        }
    }

    printf("\n");
}

int main() {
    FILE *inputFile, *outputFile;
    int numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int result[MAX_VERTICES][MAX_VERTICES];

    // Open input file
    inputFile = fopen("floyd.dat", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input from the file
    fscanf(inputFile, "%d", &numVertices);
    int source, destination;
    fscanf(inputFile, "%d %d", &source, &destination);
    readGraph(inputFile, graph, numVertices);
    fclose(inputFile);

    // Perform Floyd-Warshall's algorithm
    floydWarshall(graph, numVertices, result);
int i;
int j;
    // Display the result on the console
    printf("Shortest Path Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Find and display the shortest path
    findShortestPath(result, source, destination);

    return 0;
}
