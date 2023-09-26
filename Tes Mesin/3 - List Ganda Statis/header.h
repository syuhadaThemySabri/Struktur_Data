/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 3 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include <stdio.h>
#include <string.h>

// Struct buat nyimpen data nilai
typedef struct
{
    char jenis[15];
    char platNomor[50];
    int tahun;
    char pemilik[50];
} dataKendaraan;

// Struct buat nyimpen var prev (mundur), next(maju), sama kontainer buat nilaimatkul
typedef struct
{
    dataKendaraan kontainer;
    int previous;
    int next;
} elemen;

typedef struct
{
    int head;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char jenis[], char platNomor[], int tahun, char pemilik[], list *L);
void addAfter(int before, char jenis[], char platNomor[], int tahun, char pemilik[], list *L);
void addLast(char jenis[], char platNomor[], int tahun, char pemilik[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void printElementReverse(list L);
void delAll(list *L);
