#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "structs.h"
void insertionSort(int* values, TypeOfProperty *option);
void shellSort(int* values, TypeOfProperty *option);
void selectionSort(int* values, TypeOfProperty *option);
void bubbleSort(int* values, TypeOfProperty *option);
void merge(int* v, int n);
void mergeSort(int* v, int n);
//void troca(int* v, int i, int j);
//int particionar(int* v, int tami, int tamf);
//int particionarInicio(int *v, int tami, int tamf);
int partitionExtreme(int *vet, int p, int r);
void quickSort_V1(int *vet, int p, int r);
void trocaMedio(int *vet, int i, int y);
int particionaMedio (int* quick, int inicio, int fim, int pivo);
void quickSort_V2(int *X, int inicio, int fim);
int particionaMediana (int *X, int inicio, int fim);
void quickSort_V3(int *X, int inicio, int fim);
int aleatorio(int alfa, int omega);
int particionaAleatorio(int *vet, int alfa, int omega);
int quickSort_V4(int *vet,int p,int r);
#endif
