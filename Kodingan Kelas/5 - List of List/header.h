#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
} mahasiswa;

typedef struct
{
    char kode[10];
    char nilai[2];
} matKul;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    matKul kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    mahasiswa kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;