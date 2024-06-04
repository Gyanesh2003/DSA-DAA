#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int size, int *comparisons) {
	int i;
    for ( i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }

        arr[j + 1] = key;
    }
}
int readFromFile(const char *filename, int arr[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    int size = 0;
    while (fscanf(file, "%d", &arr[size]) != EOF) {
        size++;
    }

    fclose(file);
    return size;
}
void writeToFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing '%s'\n", filename);
        exit(1);
    }
    int i;
    for (i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    int arr[500];
    int comparisons = 0;
    int size;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");

    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            size = readFromFile("inAsce.dat", arr);
            insertionSort(arr, size, &comparisons);
            writeToFile("outInsAsce.dat", arr, size);
            break;

        case 2:
            size = readFromFile("inDesc.dat", arr);
            insertionSort(arr, size, &comparisons);
            writeToFile("outInsDesc.dat", arr, size);
            break;

        case 3:
            size = readFromFile("inRand.dat", arr);
            insertionSort(arr, size, &comparisons);
            writeToFile("outInsRand.dat", arr, size);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option\n");
            break;
    }
    int i;
    printf("Before Sorting: Content of the input file\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr);
       
    }
    
    printf("\nAfter Sorting: Content of the output file\n");
    for (i = 0; i < size; i++) {
        printf("%d ",arr);
    }

    printf("\nNumber of Comparisons: %d\n", comparisons);
    if (comparisons == (size - 1) * size / 2) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == (size * (size - 1)) / 2) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Average-case\n");
    }

    return 0;
}

