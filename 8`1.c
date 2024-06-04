#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100

// Structure to represent an edge
struct Edge {
    int u, v;
};

// Structure to represent a node
struct Node {
    int value;
    struct Node* next;
};

// Structure to represent a queue
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Function to initialize a queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to perform Breadth-First Search
void BFS(int n, int m, struct Edge edges[], int start, struct Node* adjacencyList[], int distances[]) {
    bool visited[n + 1];
    int i;
    for (i = 1; i <= n; i++) {
        visited[i] = false;
        distances[i] = -1;
    }

    struct Queue queue;
    initializeQueue(&queue);

    visited[start] = true;
    distances[start] = 0;
    enqueue(&queue, start);

    while (!isEmpty(&queue)) {
        int current = dequeue(&queue);
        struct Node* neighbor = adjacencyList[current];
        while (neighbor != NULL) {
            int v = neighbor->value;
            if (!visited[v]) {
                visited[v] = true;
                distances[v] = distances[current] + 2;
                enqueue(&queue, v);
            }
            neighbor = neighbor->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
int i;
    struct Node* adjacencyList[n + 1];
    for (i = 1; i <= n; i++) {
        adjacencyList[i] = NULL;
    }
    
    struct Edge edges[MAX_EDGES];
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Create an edge
        edges[i].u = u;
        edges[i].v = v;
        // Add to adjacency list
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = v;
        newNode->next = adjacencyList[u];
        adjacencyList[u] = newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = u;
        newNode->next = adjacencyList[v];
        adjacencyList[v] = newNode;
    }

    int start;
   
    scanf("%d", &start);

    // Perform BFS
    int distances[n + 1];
    BFS(n, m, edges, start, adjacencyList, distances);

    // Output BFS traversal
    printf("BFS Traversal: %d", start);
    bool first = true;
    for (i = 1; i <= n; i++) {
        if (i != start) {
            printf("%s %d", first ? " " : "", i);
            first = false;
        }
    }
    printf("\n");

    // Output distances
    printf("Distance [");
    first = true;
    for (i = 1; i <= n; i++) {
        printf("%s%d", first ? " " : " ", distances[i]);
        first = false;
    }
    printf("]\n");

    return 0;
}

