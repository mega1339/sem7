#include <stdio.h>
#include <stdlib.h>

void shellSort(int array[], int size) {
    int gap = size / 2;

    while (gap > 0) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }

        gap /= 2;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("enter size of massive: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));

    printf("enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("befor sorting:\n");
    printArray(array, size);

    shellSort(array, size);

    printf("after sorting:\n");
    printArray(array, size);

    free(array);

    return 0;
}
