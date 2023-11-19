#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

typedef struct
{
    simpul *root;
} tree;