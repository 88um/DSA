#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* sortedArr = (int*)malloc(size * sizeof(int));

   
    int i, j, min_index;

    for (i = 0; i < n; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        sortedArr[i] = arr[min_index];

    free(sortedArr);

    return 0;
}
