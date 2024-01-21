#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"

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
        if(i != minIndex)
        {
            temp = values[minIndex];
            values[minIndex] = values[i];
            values[i] = temp;
        }
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

void merge(int* v, int n)
{
    int metade, i, j, k;
    int *aux;
    aux = (int *)malloc(n * sizeof(int));
    if (aux == NULL)
    {
        return;
    }
    metade = n / 2;
    i = 0;
    k = 0;
    j = metade;
    while (i < metade && j < n)
    {
        if (v[i] <= v[j])
        {
            aux[k] = v[i++];
        }
        else
        {
            aux[k] = v[j++];
        }
        ++k;
    }
    if (i == metade)
    {
        while (j < n)
        {
            aux[k++] = v[j++];
        }
    }
    else
    {
        while (i < metade)
        {
            aux[k++] = v[i++];
        }
    }
    for (i = 0; i < n; ++i)
    {
        v[i] = aux[i];
    }
    free(aux);
}

void mergeSort(int* v, int n)
{
    int metade = 0;
    if (n > 1)
    {
        metade = n / 2;
        mergeSort(v, metade);
        mergeSort(v + metade, n - metade);
        merge(v, n);
    }
}

//Quick_Sort versão 1
/*void troca(int* v, int i, int j)
{
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

int particionar(int* v, int tami, int tamf)
{
	int p, pivo, i;

	p = v[tamf];
	pivo = tami;

	for (i = tami; i < tamf; i++)
	{
		if (v[i] <= p)
		{
			troca(v, i, pivo);

			pivo++;
		}
	}

	troca(v, pivo, tamf);

	return pivo;
}

int particionarInicio(int *v, int tami, int tamf)
{
	int pivo, p;

	pivo = tami;

	troca(v, pivo, tamf);

	p = particionar(v, tami, tamf);

	return p;
}*/

int partitionExtreme(int *vet, int p, int r){
    int x = vet[p];
    int i = p-1;
    int j = r+1;
    while(1){
        do{
            i++;
        }while(vet[i] < x);
        do{
            j--;
        }while(vet[j] > x);

        if(i<j){
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }else{
            return j;
        }
    }
}

void quickSort_V1(int *vet, int p, int r){
    if(p < r){
        int q = partitionExtreme(vet,p,r);
        quickSort_V1(vet,p,q);
        quickSort_V1(vet,q+1,r);
    }
}

//Quick_Sort Média
void trocaMedio(int *vet, int i, int y){
    int aux;
    aux = vet[y];
    vet[y] = vet[i]; //vet[i] = vet[j];
    vet[i] = aux; // vet[j] = temp
}

int particionaMedio (int* quick, int inicio, int fim, int pivo){
    int y, i;
    trocaMedio(quick, pivo, fim);
    y = inicio;
    for(i = inicio; i < fim; i++){
    	if (quick[i] < quick[fim]){
        	trocaMedio(quick, i, y);
        	y++;
		}
	}
    trocaMedio(quick, fim, y);
    return y;
}

void quickSort_V2(int *X, int inicio, int fim){
	int pivo, y;
	clock_t start = clock();
    if (inicio < fim){
    	pivo = (inicio+fim)/2;
        y = particionaMedio(X, inicio, fim, pivo);
        quickSort_V2(X, inicio, y-1);
        quickSort_V2(X, y+1, fim);
    }
}

//quicksort V3 (Mediana)
int particionaMediana (int *X, int inicio, int fim) {
	int pivo, aux, aux2, i, j;
	pivo = X[inicio];
	aux = X[(fim-inicio)/2+inicio];
	aux2 = X[fim-1];
	i = inicio - 1;
	j = fim;
	if (aux > pivo && aux < aux2 || aux > aux2 && aux < pivo){
		pivo = aux;
	}else{
		if (aux2 > pivo && aux2 < aux || aux2 > aux && aux2 < pivo ){
			pivo = aux2;
		}
	}
	while (1){
		do{
			j--;
		}while (X[j] > pivo);

		do{
			i++;
		}while (X[i] < pivo);

		if  (i < j){
			trocaMedio(X, i, j);
		}else{
			return j+1;
		}

	}
	return 0;
}

void quickSort_V3(int *X, int inicio, int fim){
	int y;
    if (fim-inicio < 2)
		return;

    y = particionaMediana(X, inicio, fim);
    quickSort_V3(X, inicio, y);
    quickSort_V3(X, y, fim);

    clock_t end = clock();
}

//quicksort V4 (Aleatório)
int aleatorio(int alfa, int omega){
	int valor, aux;
	aux = omega - alfa;
	srand(valor*aux);
	valor=rand() % aux;
	return valor;
}

int particionaAleatorio(int *vet, int alfa, int omega){
	int pivo, i, j, k;
	i = alfa - 1;
	j = omega + 1;
	k = aleatorio(alfa, omega);
	k+= alfa;
	pivo = vet[k];
	while(1){

	do
		j--;
	while(vet[j] > pivo);


	do
		i++;
	while(vet[i] < pivo);


	if(i < j)
		trocaMedio(vet, i, j);

	else return j;

	}
	return 0;
}

int quickSort_V4(int *vet,int p,int r){
	int q;
	if(p<r)
	{
		q=particionaAleatorio(vet,p,r);
		quickSort_V4(vet,p,q);
		quickSort_V4(vet,q+1,r);
	}
}

