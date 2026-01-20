#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void buublesort(int arr[], int n) {
    for (int i =0; i<n-1; i++) {
        int swapCounter = 0;

        for (int j =0; j<n-1-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapCounter =1;
            }

        }
        if (swapCounter ==0) {
            break;
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);
    }
}
int main() {
    int n; 
    printf("Enter array size: ");
    scanf("%d", &n);



    int *arr = malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 2001) - 1000;
    }
    if (n <= 50) {
        printf("\nUnsorted array:\n");
        print_array(arr, n);
    }

    clock_t start = clock();
    buublesort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start) /CLOCKS_PER_SEC;

    if (n <= 50) {
        printf("\nSorted array:\n");
        print_array(arr, n);
    }

    printf("\nTime taken: %.1f\n", time_taken );

    free(arr);
    return 0;

}