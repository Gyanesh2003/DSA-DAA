#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = NULL;
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertAtPosition(int data, int pos) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position not valid\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    struct Node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position not valid\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void displayList() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, n, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

