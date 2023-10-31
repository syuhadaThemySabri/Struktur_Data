#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatkul;

typedef struct
{
    int top; // buat stack paling atas
    nilaiMatkul data[10];
} stack;

void createEmptyStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void pushToStack(char nim[], char nama[], float nilai, stack *S);
void popOutStack(stack *S);
void printStack(stack S);
