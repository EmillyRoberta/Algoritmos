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

void shellSort(int* values, TypeOfProperty *option)
{

    clock_t start = clock();

    int gap, i, j, temp;
    for (gap = option->inputSize / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < option->inputSize; i++)
        {
            temp = values[i];
            for (j = i; j >= gap && values[j - gap] > temp; j -= gap)
                values[j] = values[j - gap];
            values[j] = temp;
        }
    }
    clock_t end = clock();
    option->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}

void selectionSort(int* values, TypeOfProperty *option)
{

    clock_t start = clock();
    int i, j, minIndex, temp;

    for (i = 0; i < option->inputSize - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < option->inputSize; j++)
        {
            if (values[j] < values[minIndex])
                minIndex = j;
        }

        temp = values[minIndex];
        values[minIndex] = values[i];
        values[i] = temp;
    }

    clock_t end = clock();
    option->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}

void bubbleSort(int* values, TypeOfProperty *option)
{

    clock_t start = clock();
    int i, j, temp;

    for (i = 0; i < option->inputSize-1; i++)
    {
        for (j = 0; j < option->inputSize-i-1; j++)
        {
            if (values[j] > values[j+1])
            {
                // Troca os elementos se estiverem na ordem errada
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }

    clock_t end = clock();
    option->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}
