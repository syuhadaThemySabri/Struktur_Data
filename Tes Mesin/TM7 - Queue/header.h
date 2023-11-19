/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 7 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    long long nim;
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
void add(long long nim, char nama[], queue *Q);
void addPriority(long long nim, char nama[], int priorityNumber, queue *Q);
void del(queue *Q, queue *R);
void printQueue(queue Q);