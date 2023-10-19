/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 1
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Struktur node untuk list ganda
struct Node
{
    int order;
    char data[50];
    struct Node *next;
    struct Node *prev;
};

// Fungsi untuk membuat node baru
int createNode(int order, const char *data);

// Fungsi untuk menampilkan kromosom
void displayChromosome(struct Node *head, int fromFront);

// Fungsi untuk melakukan pertukaran gen antara dua kromosom
void exchangeGen(struct Node *chromosome1, struct Node *chromosome2, int order1, int order2);