/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan UTS dengan jujur
demi keberkahan-Nya.
Aamiin
*/
// declare library
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// macro buat declare maksimal karakter string
#define MAXCHAR 51

// struct sebagai baris
typedef struct
{
    char merekPowerBank[MAXCHAR];
} merekPB;

// struct sebagai kolom
typedef struct
{
    char seriPowerBank[MAXCHAR];
    int kapasitasAwal;
    int ketahanan;
    int kapasitasAkhir;
    int tahunBeli;
} detailPB;

// struct pointer kolom
typedef struct eklm *alamatekolom;
typedef struct eklm
{
    detailPB kontainer_kol;
    alamatekolom next_kol;
} eKolom;

// struct pointer baris
typedef struct ebr *alamatebaris;
typedef struct ebr
{
    merekPB kontainer;
    eKolom *col;
    alamatebaris next;
    alamatebaris prev;
} eBaris;

// struct pointer buat nunjuk elemen pertama baris
typedef struct
{
    eBaris *first;
} list;

void createList(list *L);                                                                                                // fungsi create list
int countElementB(list L);                                                                                               // fungsi menghitung elemen baris
int countElementK(eBaris L);                                                                                             // fungsi menghitung elemen kolom
void addFirstB(char merekPowerBank[], list *L);                                                                          // fungsi menambahkan elemen ke baris sebagai elemen pertama
void addFirstK(char seriPowerBank[], int kapasitasAwal, int ketahanan, int kapasitasAkhir, int tahunBeli, eBaris *L);    // fungsi menambahkan elemen ke kolom sebagai elemen pertama
void addAfterB(eBaris *prev, char merekPowerBank[]);                                                                     // fungsi menambahkan elemen ke baris sebagai elemen setelah elemen pertama
void addAfterK(eKolom *prev, char seriPowerBank[], int kapasitasAwal, int ketahanan, int kapasitasAkhir, int tahunBeli); // fungsi menambahkan elemen ke kolom sebagai elemen setelah elemen pertama
void addLastB(char merekPowerBank[], list *L);                                                                           // fungsi menambahkan elemen ke baris sebagai elemen terakhir
void addLastK(char seriPowerBank[], int kapasitasAwal, int ketahanan, int kapasitasAkhir, int tahunBeli, eBaris *L);     // fungsi menambahkan elemen ke kolom sebagai elemen terakhir
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