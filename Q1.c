#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void read_file(char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File %s not found.\n", filename);
        exit(1);
    }
    *size = 0;
    while (fscanf(file, "%d", &arr[*size]) != EOF) {
        (*size)++;
    }
    fclose(file);
}

void write_file(char *filename, int arr[], int size) {
	int i;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file %s.\n", filename);
        exit(1);
    }
    
    for (i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        if (choice == 4) {
            break;
        }
        int arr[500];
        int size;

        switch (choice) {
            case 1:
                read_file("inASCE.dat", arr, &size);
                break;
            case 2:
                read_file("inDESC.dat", arr, &size);
                break;
            case 3:
                read_file("inRAND.dat", arr, &size);
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }
        int i;
        printf("Before Sorting: ");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quick_sort(arr, 0, size - 1);
        
        printf("After Sorting: ");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nNumber of Comparisons: %d\n", size - 1);
        
        int mid = size / 2;
        if (mid % 2 == 0 && partition(arr, 0, mid) == mid) {
            printf("Scenario: Best-case partitioning\n");
        } else if (partition(arr, 0, size - 1) == size - 1) {
            printf("Scenario: Worst-case partitioning\n");
        }
        
        switch (choice) {
            case 1:
                write_file("outQuickAsce.dat", arr, size);
                break;
            case 2:
                write_file("outQuickDesc.dat", arr, size);
                break;
            case 3:
                write_file("outQuickRand.dat", arr, size);
                break;
        }
    }

    return 0;
}
