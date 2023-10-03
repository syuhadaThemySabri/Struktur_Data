/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 4 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    long long int nomor;
    char email[50];
} dataOrang;

typedef struct elmt *alamatelmt;

typedef struct elmt
{
    dataOrang kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;
void createList(list *L);
void addFirst(char nama[], long long int nomor, char email[], list *L);
void addAfter(elemen *before, char nama[], long long int nomor, char email[], list *L);
void addBefore(elemen *before, char nama[], long long int nomor, char email[], list *L);
void addLast(char nama[], long long int nomor, char email[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void printElement(list L);
void printElementReverse(list L);
void delAll(list *L);
