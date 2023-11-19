/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 2
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[51];
    char menu[51];
    int harga;
    int jam;
    int menit;
    int detik;
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
void add(char nama[], char menu[], int harga, int jam, int menit, int detik, queue *Q);
void addPriority(char nama[], char menu[], int harga, int jam, int menit, int detik, queue *Q);
void del(queue *Q, queue *R);
void printQueue(queue Q);