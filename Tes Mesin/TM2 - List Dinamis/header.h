/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 2 dengan jujur
demi keberkahan-Nya.
Aamiin
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char namaIdol[50];
    char namaGrup[50];
    int tahunLahir;
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
void addFirst(char namaIdol[], char namaGrup[], int tahunLahir, list *L);
void addAfter(elemen *previous, char namaIdol[], char namaGrup[], int tahunLahir, list *L);
void addLast(char namaIdol[], char namaGrup[], int tahunLahir, list *L);
void delFirst(list *L);
void delAfter(elemen *previous, list *L);
void delLast(list *L);
void printElement(list L, int tahun);
void delAll(list *L);
