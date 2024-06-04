#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
void KruskalMST(int n, int m, struct Edge edges[]);

int main() {
    int n, m;
    int i;
    printf("Enter the Number of Nodes and Edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    printf("Enter the Edges (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    KruskalMST(n, m, edges);

    return 0;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
void KruskalMST(int n, int m, struct Edge edges[]) {
	int i;
    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));

    for ( i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int e;
    qsort(edges, m, sizeof(edges[0]), compareEdges);

    printf("Edge Cost\n");

    int totalWeight = 0;

    for (i = 0, e = 0; e < n - 1; i++) {
        int x = find(subsets, edges[i].src - 1);
        int y = find(subsets, edges[i].dest - 1);

        if (x != y) {
            printf("%d--%d %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            totalWeight += edges[i].weight;
            Union(subsets, x, y);
            e++;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    free(subsets);
}
