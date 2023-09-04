#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "share.c"

void insertionSort(int* values, TypeOfProperty *option)
{
    clock_t start = clock();
    int i, key, j;
    for (i = 1; i < option->inputSize; i++)
    {
        key = values[i];
        j = i - 1;

        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            j = j - 1;
        }
        values[j + 1] = key;
    }
    clock_t end = clock();
    option->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}
