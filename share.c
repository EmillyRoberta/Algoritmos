#ifndef MEUHEADER_H
#define MEUHEADER_H
typedef struct
{
    int algorithm;
    char inputType[30];
    int inputSize;
    double timeTaken;
} TypeOfProperty;

void filterNumber(TypeOfProperty *option)
{
    int sizes[] = {10,100,1000,10000,100000,1000000};
    option->inputSize = sizes[option->inputSize - 1];
}

void filterNumbersChoice(TypeOfProperty *option)
{
    if(option->inputType[0]=='r')
    {
        strcpy(option->inputType, "random");
    }
    if(option->inputType[0]=='c')
    {
        strcpy(option->inputType, "crescente");
    }
    if(option->inputType[0]=='d')
    {
        strcpy(option->inputType, "decrescente");
    }
}

char* createPath(TypeOfProperty *option, char *pathDefault)
{
    char *filePath =  (char *)malloc(60 * sizeof(char));
    if (filePath == NULL)
    {
        perror("Erro de alocação de memória");
        exit(1);
    }

    char inputSize[10];
    sprintf(inputSize, "%d", option->inputSize); //converto int pra string
    strcpy(filePath, pathDefault);
    strcat(filePath, option->inputType);
    strcat(filePath, inputSize);
    strcat(filePath, ".txt");
    return filePath;
}

void createFileNumbers(TypeOfProperty *option)
{
    FILE *file;
    char pathDefault[60];
    char path[30] = ".\\arquivodeentrada\\";
    strcpy(pathDefault, path);
    strcat(pathDefault, option->inputType);
    strcat(pathDefault, "\\entrada");

    char *filePath = createPath(option, pathDefault);
     printf("%s", filePath);
    file = fopen(filePath, "w");

    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
     fprintf(file, "%d\n", option->inputSize);
    if(strcmp(option->inputType, "random") == 0)
    {
        srand(time(NULL));
        for (int i = 0; i < option->inputSize; i++)
        {
            int randleNumbers = rand();
            fprintf(file, "%d\n", randleNumbers);
        }
    }
    if(strcmp(option->inputType, "crescente") == 0)
    {
        for (int i = 1; i <= option->inputSize; i++)
        {
            fprintf(file, "%d\n", i);
        }
    }
    if(strcmp(option->inputType, "decrescente") == 0)
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
    FILE *file;
    char pathDefault[60];
    char path[30] = ".\\arquivodeentrada\\";
    strcpy(pathDefault, path);
    strcat(pathDefault, option->inputType);
    strcat(pathDefault, "\\entrada");
    char *filePath = createPath(option, pathDefault);
    file = fopen(filePath, "r");
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
    char pathDefault[60];
    char path[30] = ".\\arquivodesaida\\";
    strcpy(pathDefault, path);
    strcat(pathDefault, option->inputType);
    strcat(pathDefault, "\\saida");
    char *filePath = createPath(option, pathDefault);
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
    char pathDefault[60];
    char path[30] = ".\\arquivodetempo\\";
    strcpy(pathDefault, path);
    strcat(pathDefault, option->inputType);
    strcat(pathDefault, "\\tempo");
    char *filePath = createPath(option, pathDefault);
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
