/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 6 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char buku[50];
    int harga;
} hargaBuku;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    hargaBuku kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createEmptyStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void pushToStack(char buku[], int harga, stack *S);
void popOutStack(stack *S);
void popStackAndReturn(stack *S, stack *T);
void printStack(stack S);
void printStack2(stack T);
