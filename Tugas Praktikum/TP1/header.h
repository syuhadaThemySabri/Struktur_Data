/*
Saya Themy Sabri Syuhada dengan NIM 2203903
mengerjakan Tugas Praktikum 1 dengan jujur
dan tidak melakukan kecurangan seperti yang telah
dispesifikasikan demi keberkahan-Nya
Aamiin
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char namaChar[50];
    char namaTeknik[50];
    int power;
} dataPenyihir;

typedef struct elmt /*elmt itu untuk alokasi pointer yang belum didefinisikan tipe datanya*/ *alamatelmt /*nama pointer sementara*/;
typedef struct elmt
{
    dataPenyihir kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first; // karena udah dikasih nama, si pointer sementara bisa dihapus
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char namaChar[], char namaTeknik[], int power, list *L);
void addAfter(elemen *previous, char namaChar[], char namaTeknik[], int power, list *L);
void addLast(char namaChar[], char namaTeknik[], int power, list *L);
void printElement(list L, int totalPower);
