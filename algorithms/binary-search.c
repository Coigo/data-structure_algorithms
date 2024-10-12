#include <stdio.h>

int main (void) {
    int arr[13] = { 1, 5, 7, 9, 14, 25, 26, 56, 67, 78, 89, 90, 91};
    int searchFor = 25;
    int steps = 0;
    int result = -1;

    int init = 0;
    int end = sizeof(arr) / sizeof(arr[0]) -1;

    while (init <= end) {
        int mid = init + (end - init) / 2;
        int guess = arr[mid]; 
        steps++;
        printf("The mid value is now: %d\n", guess);

        if (guess == searchFor) {
            result = guess;
            break;
        }
        else if (guess < searchFor) {
            init = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    if ( result != -1 ) {
        printf("The result is %d, and it leasted %d steps\n", result, steps);
    }
    else {
        printf("Not found the result, but it leasted %d steps\n", steps);
    }
}