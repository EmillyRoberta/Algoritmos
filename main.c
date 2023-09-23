#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "algorithms.c"
#include <time.h>
#include <sys/types.h>
#ifdef _WIN32
#include <direct.h>
#define mkdir(directory, mode) _mkdir(directory)
#endif
#include "share.c"
#define PATH_SEPARATOR "\\"


void menuFileSize(TypeOfPropertyMenu *optionMenu)
{
    do
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
        scanf("%d", &optionMenu->inputSize);

        if(optionMenu->inputSize<1 || optionMenu->inputSize>6)
        {
            printf("Digite uma opção válida!\n");
            Sleep(1000);
        }
        system("cls");
    }
    while(optionMenu->inputSize<1 || optionMenu->inputSize>6);
}

void menuNumbersChoice(TypeOfPropertyMenu *optionMenu)
{
    do
    {
        printf("                                                 \n");
        printf("\t***Escolha a forma em que serão geradas:*******\n");
        printf("\t|                                              |\n");
        printf("\t|           1. Números Randômicos              |\n");
        printf("\t|           2. Números Crescentes              |\n");
        printf("\t|           3. Números Decrescentes            |\n");
        printf("\t|                                              |\n");
        printf("\t|______________________________________________|\n\n");

        printf("\tDigite a opcao: ");
        scanf(" %d", &optionMenu->inputType);

        if(optionMenu->inputType>0 && optionMenu->inputType<4)
        {
            system("cls");
            menuFileSize(optionMenu);
        }
        else
        {
            printf("Digite uma opção válida!\n");
            Sleep(1000);
            system("cls");
        }
    }
    while(optionMenu->inputType<1 || optionMenu->inputType>3);
}

void menuAlgorithmChoice(TypeOfPropertyMenu *optionMenu)
{
    do
    {
        printf("                                                 \n");
        printf("\t***Escolha o Algoritmo de Ordenação Desejado***\n");
        printf("\t|                                              |\n");
        printf("\t|           1. InsertionSort                   |\n");
        printf("\t|           2. BubbleSort                      |\n");
        printf("\t|           3. SelectionSort                   |\n");
        printf("\t|           4. ShellSort                       |\n");
        printf("\t|                                              |\n");
        printf("\t|______________________________________________|\n\n");

        printf("\tDigite a opcao: ");
        scanf("%d", &optionMenu->algorithm);

        if(optionMenu->algorithm>0 && optionMenu->algorithm<5)
        {
            system("cls");
            menuNumbersChoice(optionMenu);
        }
        else
        {
            printf("Digite uma opção válida!\n");
            Sleep(1000);
            system("cls");
        }
    }
    while(optionMenu->algorithm<1 || optionMenu->algorithm>4);

}

void dataOutput(TypeOfProperty *option)
{
    printf("                                                 \n");
    printf("\t***************Dados Apurados******************\n");
    printf("\t                                              \n");
    printf("\t Algoritmo Usado: %s                          \n", option->algorithm);
    printf("\t Tipo de Entrada: %s                          \n", option->inputType);
    printf("\t Tamanho: %d                                  \n", option->inputSize);
    printf("\t Tempo: %f segundos                           \n", option->timeTaken);
    printf("\t                                              \n");
    printf("\t______________________________________________\n\n");
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    TypeOfPropertyMenu optionMenu;
    TypeOfProperty option;
    menuAlgorithmChoice(&optionMenu);
    filterNumber(&option, &optionMenu);
    createFiles(&option);
    createFileNumbers(&option);
    int* numbersVector = readFileNumbers(&option);

    switch(optionMenu.algorithm)
    {
    case 1:
        insertionSort(numbersVector, &option);
        resultOrdenation(numbersVector, &option);
        resultTime(&option);
        dataOutput(&option);
        break;
    case 2:
        bubbleSort(numbersVector, &option);
        resultOrdenation(numbersVector, &option);
        resultTime(&option);
        dataOutput(&option);
        break;
    case 3:
        selectionSort(numbersVector, &option);
        resultOrdenation(numbersVector, &option);
        resultTime(&option);
        dataOutput(&option);
        break;
    case 4:
        shellSort(numbersVector, &option);
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
