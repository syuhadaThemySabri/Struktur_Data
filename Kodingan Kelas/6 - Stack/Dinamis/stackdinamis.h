#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatKul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatKul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;