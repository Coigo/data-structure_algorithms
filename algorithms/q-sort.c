void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int arr[], int low, int high) {

    int pivot = arr[high];
    int i = (low - 1);
    
    for ( int j = low; j < high; j++ ) {

        if ( arr[j] <= pivot ) {
            i++;
            swap(&arr[i], &arr[j] ); 
        }

    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1 );
        quickSort(arr, pivot + 1, high);
    }
}

int main () {
        int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
        return 0;

}