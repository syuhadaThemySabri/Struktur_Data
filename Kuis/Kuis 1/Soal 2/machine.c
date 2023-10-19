/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 1
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include "header.h"

// Fungsi untuk membuat node baru
int createNode(int order, const char *data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->order = order;
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Fungsi untuk menampilkan kromosom
void displayChromosome(struct Node *head, int fromFront)
{
    struct Node *current = fromFront ? head : NULL;

    while (current != NULL)
    {
        printf("%s ", current->data);
        current = fromFront ? current->next : current->prev;
    }
}

// Fungsi untuk melakukan pertukaran gen antara dua kromosom
void exchangeGen(struct Node *chromosome1, struct Node *chromosome2, int order1, int order2)
{
    struct Node *node1 = chromosome1;
    struct Node *node2 = chromosome2;

    while (node1 != NULL && node1->order != order1)
    {
        node1 = node1->next;
    }

    while (node2 != NULL && node2->order != order2)
    {
        node2 = node2->prev;
    }

    if (node1 != NULL && node2 != NULL)
    {
        char temp[50];
        strcpy(temp, node1->data);
        strcpy(node1->data, node2->data);
        strcpy(node2->data, temp);
    }
}