#ifndef SHARE_H
#define SHARE_H
#include "structs.h"
void filterNumber(TypeOfProperty *option, TypeOfPropertyMenu *optionMenu);
void createFiles(TypeOfProperty *option);
char* createPath(TypeOfProperty *option, char *outro);
void createFileNumbers(TypeOfProperty *option);
int* readFileNumbers(TypeOfProperty *option);
void resultOrdenation(int* vector, TypeOfProperty *option);
void resultTime(TypeOfProperty *option);
#endif
