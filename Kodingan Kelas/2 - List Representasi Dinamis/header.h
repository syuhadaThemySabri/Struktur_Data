#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[2];
} nilaiMatkul;

typedef struct elmt /*elmt itu untuk alokasi pointer yang belum didefinisikan tipe datanya*/ *alamatelmt /*nama pointer sementara*/;
typedef struct elmt
{
    nilaiMatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first; // karena udah dikasih nama, si pointer sementara bisa dihapus
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen *previous, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen *previous, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);