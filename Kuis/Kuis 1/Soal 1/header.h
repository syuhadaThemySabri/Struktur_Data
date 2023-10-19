/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 1
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include <string.h>
#include <stdio.h>

typedef struct
{
    int hargaMenu;
    char namaMenu[51];
    char statusMenu[51];
} dataMenu;

typedef struct
{
    dataMenu kontainer;
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
void addFirst(char namaMenu[], int hargaMenu, char statusMenu[], list *L);
void addAfter(int previous, char namaMenu[], int hargaMenu, char statusMenu[], list *L);
void addLast(char namaMenu[], int hargaMenu, char statusMenu[], list *L);
void delFirst(list *L);
void delAfter(int previous, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);