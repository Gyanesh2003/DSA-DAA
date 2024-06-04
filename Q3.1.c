#include <stdio.h>

int binary_search_leftmost(int arr[], int size, int key, int *comparisons) {
    int left = 0;
    int right = size - 1;
    int position = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        
        if (arr[mid] == key) {
            position = mid;
            right = mid - 1;  
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return position;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    int i;
    printf("Enter elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    
    int comparisons = 0;
    int position = binary_search_leftmost(arr, size, key, &comparisons);
    
    if (position != -1) {
        printf("%d found at index position %d\n", key, position);
        printf("Number of comparisons: %d\n", comparisons);
    } else {
        printf("%d not found in the array\n", key);
    }
    
    return 0;
}

