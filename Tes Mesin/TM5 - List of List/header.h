/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 5 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char genre[50];
    int kode;
} genreBuku;

typedef struct
{
    char judul[50];
} judulBuku;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    judulBuku kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    genreBuku kontainer;
    eKolom *col;
    alamatebaris next;
    alamatebaris prev;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char genre[], int kode, list *L);
void addFirstK(char judul[], eBaris *L);
void addAfterB(eBaris *prev, char genre[], int kode);
void addAfterK(eKolom *prev, char judul[]);
void addLastB(char genre[], int kode, list *L);
void addLastK(char judul[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
eBaris *barisLast(list L);
