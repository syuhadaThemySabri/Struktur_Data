#include <stdio.h>
#include <string.h>

typedef struct
{
    char warna[51];
    int panjang;
    int lebar;
    char nama[51];
} nilaiMatkul;

typedef struct
{
    int top; // buat stack paling atas
    nilaiMatkul data[100];
} stack;

void createEmptyStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void pushToStack(char warna[], int panjang, int lebar, char nama[], stack *S);
void popOutStack(stack *S);
void printStack(stack S);
