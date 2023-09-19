#include <stdio.h>

typedef struct
{
    float masukan;
} nilai;

typedef struct
{
    nilai kontainer;
    int next;
} elemen;

typedef struct
{
    int first;        //
    elemen data[100]; // Sesuaikan ukuran array dengan batas maksimal yang ada di soal yaitu 100
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(float masukan, list *L);
void printElement(list L);