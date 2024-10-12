#include <stdio.h>

int main (void) {

    int arr[] = { 1, 2, 3, 4, 5 };
    
    for (int i = 0; i <=  sizeof(arr[0]); i++ ) {
        printf("%d\n", arr[i]);
    }
    return 0;
}