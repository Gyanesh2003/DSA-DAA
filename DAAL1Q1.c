#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        int j;
        for (j = left; j <= right - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        
        swap(&arr[i + 1], &arr[right]);
        int pivot_index = i + 1;
        
        quicksort(arr, left, pivot_index - 1);
        quicksort(arr, pivot_index + 1, right);
    }
}

int main() {
    int n,i,j;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        free(arr);
        return 1;
    }
    printf("Reading elements from the disc file...\n");
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    quicksort(arr, 0, n - 1);
    int second_smallest = arr[1];
    int second_largest = arr[n - 2];
    printf("Second smallest element: %d\n", second_smallest);
    printf("Second largest element: %d\n", second_largest);
    free(arr);
    
    return 0;
}
