#ifndef STRUCT_H
#define STRUCT_H

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

#endif
