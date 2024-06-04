#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person {
    int id;
    char name[15];
    int age;
    int height;
    int weight;
};
void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void createHeap(struct person arr[], int n, int option) {
	int i;
    if (option == 2) { 
        for ( i = n / 2 - 1; i >= 0; i--)
            minHeapify(arr, n, i);
    } else if (option == 3) { 
        for (i = n / 2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i);
    }
}

void displayWeightOfYoungest(struct person arr[], int n) {
    if (n > 0)
        printf("Weight of youngest student: %.2lf kg\n", arr[0].weight * 0.45359237); 
    else
        printf("No data available.\n");
}

void insertPerson(struct person arr[], int *n, struct person newPerson) {
    (*n)++;
    int i = *n - 1;
    arr[i] = newPerson;

    while (i > 0 && arr[(i - 1) / 2].age > arr[i].age) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteOldestPerson(struct person arr[], int *n) {
    if (*n <= 0) {
        printf("No data available.\n");
        return;
    }

    if (*n == 1) {
        (*n)--;
        return;
    }

    arr[0] = arr[(*n) - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
}

void saveDataToFile(struct person arr[], int n) {
    FILE *file = fopen("personal_data.dat", "wb");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    fwrite(arr, sizeof(struct person), n, file);
    fclose(file);
    printf("Data saved to 'personal_data.dat'.\n");
}

void readDataFromFile(struct person **arr, int *n) {
    FILE *file = fopen("personal_data.dat", "rb");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *n = file_size / sizeof(struct person);
    *arr = (struct person *)malloc(*n * sizeof(struct person));

    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    fread(*arr, sizeof(struct person), *n, file);
    fclose(file);
    int i;
    printf("Id\tName\t\t\tAge\tHeight\tWeight(pound)\n");
    for (i = 0; i < *n; i++) {
        printf("%d\t%-20s\t%d\t%d\t%d\n", (*arr)[i].id, (*arr)[i].name, (*arr)[i].age, (*arr)[i].height, (*arr)[i].weight);
    }

    printf("Data loaded from 'personal_data.dat'.\n");
}

void displayAllData(struct person arr[], int n) {
	int i;
    if (n == 0) {
        printf("No data available.\n");
        return;
    }

    printf("Id\tName\tAge\tHeight\tWeight\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}

int main() {
    struct person *originalData = NULL; 
    struct person *heapOrderedData = NULL; 
    int originalDataSize = 0;
    int heapOrderedDataSize = 0;
    int option;

    while (1) {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data from File\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Display All Data\n"); 
        printf("8. Save Data to File\n");
        printf("9. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: 
                if (originalData != NULL) {
                    free(originalData); 
                }
                readDataFromFile(&originalData, &originalDataSize);
                heapOrderedDataSize = originalDataSize; 
                if (heapOrderedData != NULL) {
                    free(heapOrderedData); 
                }
                heapOrderedData = (struct person *)malloc(heapOrderedDataSize * sizeof(struct person)); 
                memcpy(heapOrderedData, originalData, heapOrderedDataSize * sizeof(struct person)); 
                break;

            case 2:
                createHeap(heapOrderedData, heapOrderedDataSize, 2);
                break;

            case 3:
                createHeap(heapOrderedData, heapOrderedDataSize, 3);
                break;

            case 4:
                displayWeightOfYoungest(heapOrderedData, heapOrderedDataSize);
                break;

            case 5:
                if (originalData == NULL) {
                    printf("Please read data first.\n");
                } else {
                    struct person newPerson;
                    printf("Enter the details of the new person (Id Name Age Height Weight): ");
                    scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                    insertPerson(heapOrderedData, &heapOrderedDataSize, newPerson);
                    printf("New person inserted into the Min-heap.\n");
                }
                break;

            case 6:
                if (originalData == NULL) {
                    printf("Please read data first.\n");
                } else {
                    deleteOldestPerson(heapOrderedData, &heapOrderedDataSize);
                    printf("Oldest person deleted from the Min-heap.\n");
                }
                break;

            case 7:
                printf("Original Data:\n");
                displayAllData(originalData, originalDataSize);
                printf("Heap-Ordered Data:\n");
                displayAllData(heapOrderedData, heapOrderedDataSize);
                break;

            case 8:
                if (originalData == NULL) {
                    printf("No data available to save.\n");
                } else {
                    saveDataToFile(originalData, originalDataSize);
                }
                break;

            case 9:
                if (originalData != NULL) {
                    free(originalData);
                }
                if (heapOrderedData != NULL) {
                    free(heapOrderedData);
                }
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
