#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = left;
    int comparisons = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
        comparisons++;
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return comparisons;
}

int merge_sort(int arr[], int temp[], int left, int right) {
    int mid, comparisons = 0;

    if (right > left) {
        mid = (right + left) / 2;

        comparisons += merge_sort(arr, temp, left, mid);
        comparisons += merge_sort(arr, temp, mid + 1, right);

        comparisons += merge(arr, temp, left, mid + 1, right);
    }

    return comparisons;
}

void read_data(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void write_data(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("File could not be opened for writing.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void print_array(const char *message, int arr[], int n) {
    printf("%s\n", message);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    const int MAX_SIZE = 500;
    int arr[MAX_SIZE], temp[MAX_SIZE];
    int n;

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");

    int option;
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            read_data("inAsce.dat", arr, MAX_SIZE);
            break;
        case 2:
            read_data("inDesc.dat", arr, MAX_SIZE);
            break;
        case 3:
            read_data("inRand.dat", arr, MAX_SIZE);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
            exit(1);
    }

    n = MAX_SIZE;

    printf("Before Sorting:\n");
    print_array("Content of the input file", arr, n);

    clock_t start_time = clock();
    int comparisons = merge_sort(arr, temp, 0, n - 1);
    clock_t end_time = clock();

    printf("After Sorting:\n");
    print_array("Content of the output file", arr, n);

    printf("Number of Comparisons: %d\n", comparisons);

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1e9;
    printf("Execution Time: %lf nanoseconds\n", execution_time);
    switch (option) {
        case 1:
            write_data("outMergeAsce.dat", arr, n);
            break;
        case 2:
            write_data("outMergeDesc.dat", arr, n);
            break;
        case 3:
            write_data("outMergeRand.dat", arr, n);
            break;
        default:
            break;
    }

    return 0;
}
