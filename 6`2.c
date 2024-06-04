#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct SYMBOL {
    char alphabet;
    int frequency;
};
struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};


struct MinPriorityQueue {
    int size;
    struct Node** array;
};

struct Node* createNode(struct SYMBOL symbol) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct MinPriorityQueue* createMinPriorityQueue(int capacity) {
    struct MinPriorityQueue* queue = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    queue->size = 0;
    queue->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct MinPriorityQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left]->symbol.frequency < queue->array[smallest]->symbol.frequency) {
        smallest = left;
    }

    if (right < queue->size && queue->array[right]->symbol.frequency < queue->array[smallest]->symbol.frequency) {
        smallest = right;
    }

    if (smallest != index) {
        swapNodes(&queue->array[index], &queue->array[smallest]);
        minHeapify(queue, smallest);
    }
}
void insertNode(struct MinPriorityQueue* queue, struct Node* node) {
    int i = queue->size++;
    while (i > 0 && node->symbol.frequency < queue->array[(i - 1) / 2]->symbol.frequency) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}
struct Node* buildHuffmanTree(char alphabets[], int frequencies[], int n) {
    struct Node *left, *right, *top;
    struct MinPriorityQueue* queue = createMinPriorityQueue(n);
    int i;
    for (i = 0; i < n; i++) {
        struct SYMBOL symbol = {alphabets[i], frequencies[i]};
        insertNode(queue, createNode(symbol));
    }

    while (queue->size > 1) {
        left = queue->array[0];
        queue->array[0] = queue->array[--queue->size];
        minHeapify(queue, 0);

        right = queue->array[0];
        queue->array[0] = queue->array[--queue->size];
        minHeapify(queue, 0);

        struct SYMBOL symbol = {'$', left->symbol.frequency + right->symbol.frequency};
        top = createNode(symbol);
        top->left = left;
        top->right = right;
        insertNode(queue, top);
    }

    return queue->array[0];
}


void inOrderTraversal(struct Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inOrderTraversal(root->right);
    }
}

int main() {
    int n;
    int i;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    char alphabets[n];
    int frequencies[n];

    printf("Enter the alphabets: ");
    for (i = 0; i < n; i++) {
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter its frequencies: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &frequencies[i]);
    }

    struct Node* root = buildHuffmanTree(alphabets, frequencies, n);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
