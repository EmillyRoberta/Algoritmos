#ifndef MEUHEADER_H
#define MEUHEADER_H
#define PATH_SEPARATOR "\\"
typedef struct
{
    char algorithm[40];
    char inputType[30];
    int inputSize;
    double timeTaken;
} TypeOfProperty;

typedef struct
{
    int algorithm;
    int inputType;
    int inputSize;
} TypeOfPropertyMenu;


void filterNumber(TypeOfProperty *option, TypeOfPropertyMenu *optionMenu)
{
    char *algorithmName[] = {"InsertionSort", "BubbleSort", "SelectionSort", "ShellSort"};
    strcpy(option->algorithm, algorithmName[optionMenu->algorithm - 1]);

    char *type[] = {"Random", "Crescente", "Decrescente"};
    strcpy(option->inputType, type[optionMenu->inputType - 1]);

    int sizes[] = {10,100,1000,10000,100000,1000000};
    option->inputSize = sizes[optionMenu->inputSize - 1];
}

void createFiles(TypeOfProperty *option)
{
    char input[30] = "Arquivos de Entrada";
    char output[30] = "Arquivos de Saida";
    char time[30] = "Arquivos de Tempo";
    char result[200];

    mkdir(option->algorithm);

    snprintf(result, sizeof(result), "%s%s%s", option->algorithm, PATH_SEPARATOR, input);
    mkdir(result);

    snprintf(result, sizeof(result), "%s%s%s", option->algorithm, PATH_SEPARATOR, output);
    mkdir(result);

    snprintf(result, sizeof(result), "%s%s%s", option->algorithm, PATH_SEPARATOR, time);
    mkdir(result);
}


char* createPath(TypeOfProperty *option, char *outro)
{
    char result[200];

    snprintf(result, sizeof(result), "%s\\Arquivos de %s\\%s",
             option->algorithm, outro, option->inputType);
    mkdir(result);

    snprintf(result, sizeof(result), "%s\\Arquivos de %s\\%s\\%s%s%d.txt",
             option->algorithm, outro, option->inputType, outro, option->inputType, option->inputSize);

    char *filePath = (char *)malloc(strlen(result) + 1); // +1 para o caractere nulo
    strcpy(filePath, result);
    return filePath;
}

void createFileNumbers(TypeOfProperty *option)
{
    FILE *file;
    char *filePath = createPath(option, "Entrada");
    file = fopen(filePath, "w");

    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(file, "%d\n", option->inputSize);
    if(strcmp(option->inputType, "Random") == 0)
    {
        srand(time(NULL));
        for (int i = 0; i < option->inputSize; i++)
        {
            int randleNumbers = rand();
            fprintf(file, "%d\n", randleNumbers);
        }
    }
    if(strcmp(option->inputType, "Crescente") == 0)
    {
        for (int i = 1; i <= option->inputSize; i++)
        {
            fprintf(file, "%d\n", i);
        }
    }
    if(strcmp(option->inputType, "Decrescente") == 0)
    {
        for (int i = option->inputSize; i >= 1; i--)
        {
            fprintf(file, "%d\n", i);
        }
    }

    fclose(file);
}

int* readFileNumbers(TypeOfProperty *option)
{
    char *filePath = createPath(option, "Entrada");
    FILE* file = fopen(filePath, "r");
    char line[100];
    int sizeFile;

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    if(fgets(line, sizeof(line), file) != NULL)
    {
        sizeFile = atoi(line);
    }

    int* vetor = (int*)malloc((sizeFile) * sizeof(int));
    if (vetor == NULL)
    {
        perror("Erro de alocação de memória");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < sizeFile; i++)
    {
        if (fscanf(file, "%d", &vetor[i]) != 1)
        {
            printf("Erro ao ler números do arquivo.\n");
            fclose(file);
            free(vetor);
            return NULL;
        }
    }
    fclose(file);
    return vetor;
}

void resultOrdenation(int* vector, TypeOfProperty *option)
{
    char *filePath = createPath(option, "Saida");
    FILE* file = fopen(filePath, "w");
    if (file == NULL)
    {
        perror("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(file, "%d\n", option->inputSize);
    for (int i = 0; i < option->inputSize; i++)
    {
        fprintf(file, "%d\n", vector[i]);
    }
    fclose(file);
    free(vector);
}

void resultTime(TypeOfProperty *option)
{
    char *filePath = createPath(option, "Tempo");
    FILE* file = fopen(filePath, "w");
    if (file == NULL)
    {
        perror("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(file, "%f\n", option->timeTaken);
    fclose(file);
}
#endif
