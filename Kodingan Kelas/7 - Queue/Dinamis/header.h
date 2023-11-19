#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char nim;
} nilaiMatKul;

typedef struct elm *alamatelmt;
typedef struct elm
{
    nilaiMatKul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(int nim, char nama[], queue *Q);
void del(queue *Q, queue *R);
void printQueue(queue Q);