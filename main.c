#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "Insertion_sort.c"
#include <time.h>
#include "share.c"

void menuFileSize(TypeOfProperty *option)
{
    printf("                                                 \n");
    printf("\t****Escolha a quantidade de algoritmos:********\n");
    printf("\t|                                              |\n");
    printf("\t|           1. 10                              |\n");
    printf("\t|           2. 100                             |\n");
    printf("\t|           3. 1000                            |\n");
    printf("\t|           4. 10000                           |\n");
    printf("\t|           5. 100000                          |\n");
    printf("\t|           6. 1000000                         |\n");
    printf("\t|                                              |\n");
    printf("\t|______________________________________________|\n\n");

    printf("\tDigite a opcao: ");
    scanf("%d", &option->inputSize);

    if(option->inputSize<1 || option->inputSize>7){
      printf("Digite uma opção válida!\n");
    }
    system("cls");
}

void menuNumbersChoice(TypeOfProperty *option)
{
    printf("                                                 \n");
    printf("\t***Escolha a forma em que serão geradas:*******\n");
    printf("\t|                                              |\n");
    printf("\t|           r. Números Randômicos              |\n");
    printf("\t|           c. Números Crescentes              |\n");
    printf("\t|           d. Números Descrescentes           |\n");
    printf("\t|                                              |\n");
    printf("\t|______________________________________________|\n\n");

    printf("\tDigite a opcao: ");
    scanf(" %c", &option->inputType);

    if(option->inputType[0]=='r' || option->inputType[0]=='c' ||
            option->inputType[0]=='d' || option->inputType[0]=='s')
    {
        system("cls");
        menuFileSize(option);
    }
    else
    {
        printf("Digite uma opção válida!\n");
    }
}

void menuAlgorithmChoice(TypeOfProperty *option)
{
    printf("                                                 \n");
    printf("\t***Escolha o Algoritmo de Ordenação Desejado***\n");
    printf("\t|                                              |\n");
    printf("\t|           1. InsertionSort                   |\n");
    printf("\t|           2. Sair                            |\n");
    printf("\t|                                              |\n");
    printf("\t|                                              |\n");
    printf("\t|______________________________________________|\n\n");

    printf("\tDigite a opcao: ");
    scanf("%d", &option->algorithm);

    if(option->algorithm == 1)
    {
        system("cls");
        menuNumbersChoice(option);
    }
    else
    {
        printf("Digite uma opção válida!\n");
    }

}

void dataOutput(TypeOfProperty *option)
{
    printf("                                                 \n");
    printf("\t***************Dados Apurados******************\n");
    printf("\t                                              \n");
    printf("\t Tipo de Entrada: %s                          \n", option->inputType);
    printf("\t Tamanho: %d                                  \n", option->inputSize);
    printf("\t Tempo: %f segundos                           \n", option->timeTaken);
    printf("\t                                              \n");
    printf("\t______________________________________________\n\n");
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    TypeOfProperty option;
    menuAlgorithmChoice(&option);
    filterNumber(&option);
    filterNumbersChoice(&option);
    createFileNumbers(&option);
    int* numbersVector = readFileNumbers(&option);

    switch(option.algorithm)
    {
    case 1:
        insertionSort(numbersVector, &option);
        resultOrdenation(numbersVector, &option);
        resultTime(&option);
        dataOutput(&option);
        break;
    default:
        printf("Digite uma opcao valida\n");
        system("cls");
        break;
    }
    return 0;
}
