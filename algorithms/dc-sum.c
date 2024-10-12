#include <stdio.h>


// int sumArray ( int arr[], int start, int end  ) {
    
//     if ( start > end ) {
//         return -1;
//     }

//     if ( start == end ) {
//         return arr[start];
//     }

//     int mid = (start + end) / 2;

//     return sumArray( arr, start, mid) + sumArray(arr, mid + 1, end ); 

// }

int sumArray ( int arr[], int start, int lenght ) {

    if ( lenght <= 0 || start > lenght ) {
        return 0;
    }

    if (lenght < 2) {
        return arr[start];
    }

    return arr[start] + sumArray(arr, start + 1, lenght - start + 2);
}

void main () {
    int arr[8] = { 1, 2, 24, 5, 6, 78, 2, 4 };
    int lenght = sizeof(arr) / sizeof(arr[0]);
    // int result = sumArray(arr, 0, size -1);
    int result = sumArray(arr, 0, lenght);
    printf("%d", result);
}