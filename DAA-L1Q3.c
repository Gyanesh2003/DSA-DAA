#include <stdio.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int countDuplicates(int arr[], int n) {
    int count = 0,i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
            while (i < n - 1 && arr[i] == arr[i + 1]) {
                i++;
            }
        }
    }
    return count;
}

int findMostRepeatingElement(int arr[], int n) {
    int maxElement = arr[0];
    int maxCount = 1;
    int currentElement = arr[0];
    int currentCount = 1,i;

    for (i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxElement = currentElement;
            }
            currentElement = arr[i];
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxElement = currentElement;
    }

    return maxElement;
}

int main() {
    int n;
    int arr[MAX_SIZE];
  
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    FILE *file = fopen("dup.txt", "r"); 
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter the numbers from the file separated by spaces: ");int i;
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
  bubbleSort(arr, n);

    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int totalDuplicates = countDuplicates(arr, n);
    printf("\nTotal number of duplicate values = %d\n", totalDuplicates);

    int mostRepeatingElement = findMostRepeatingElement(arr, n);
    printf("The most repeating element in the array = %d\n", mostRepeatingElement);

    return 0;
}
