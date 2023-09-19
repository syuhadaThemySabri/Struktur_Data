#include <stdio.h>
#include <string.h>

// struct buat nampung nama, nim, nilai
typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[1];
} nilaiMatkul;

// struct buat jadi "kontainer" untuk nilai matkul + ditambah dnegan var next untuk list selanjutnya
typedef struct
{
    nilaiMatkul kontainer;
    int next;
} elemen;

// struct untuk membungkus struct elemen + var first untuk inisialisasi awal
typedef struct
{
    int first;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(int previous, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(int previous, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);