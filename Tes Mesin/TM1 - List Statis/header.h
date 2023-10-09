/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 1 dengan jujur
demi keberkahan-Nya.
Aamiin
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char namaPulau[50];
    int populasiPulau;
    float luasPulau;
} dataPulau;

typedef struct
{
    dataPulau kontainer;
    int next;
} elemen;

typedef struct
{
    int first;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char namaPulau[], int populasiPulau, float luasPulau, list *L);
void addAfter(int previous, char namaPulau[], int populasiPulau, float luasPulau, list *L);
void addLast(char namaPulau[], int populasiPulau, float luasPulau, list *L);
void delFirst(list *L);
void delAfter(int previous, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
