#include <stdio.h>

int findLower (int arr[], int size) {
    int lowerIndex = 0; 
    for (int i = 0; i < size; i ++) {
        if (arr[i] < arr[lowerIndex]) {
            lowerIndex = i;
        }        
    }
    return lowerIndex;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int lower = findLower(arr + i , size - i ) + i;
        int temp = arr[i];
        arr[i] = arr[lower];
        arr[lower] = temp;
    }
}

int main () {
    int arr[10] = {41,2,5,1,53,12,52,87,23,61};
    int size = sizeof(arr) / sizeof(arr[0]); 

    selectionSort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    return 0;
}