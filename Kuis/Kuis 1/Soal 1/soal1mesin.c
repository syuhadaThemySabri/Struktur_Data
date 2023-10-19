#include "soal1header.h"

// Fungsi untuk menambahkan menu ke dalam list
void tambahMenu(struct Menu *head, int harga, const char *nama, const char *jenis)
{
    struct Menu *newNode = (struct Menu *)malloc(sizeof(struct Menu));
    newNode->harga = harga;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jenis, jenis);
    newNode->next = NULL;

    struct Menu *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

// Fungsi untuk memisahkan menu promo dan reguler
void pisahkanMenu(struct Menu *head, struct Menu **promoHead, struct Menu **regulerHead)
{
    struct Menu *current = head->next;

    while (current != NULL)
    {
        if (strcmp(current->jenis, "promo") == 0)
        {
            tambahMenu(*promoHead, current->harga, current->nama, current->jenis);
        }
        else
        {
            tambahMenu(*regulerHead, current->harga, current->nama, current->jenis);
        }
        current = current->next;
    }
}

// Fungsi untuk menampilkan isi list menu
void tampilkanMenu(struct Menu *head, const char *jenis)
{
    printf("list %s:\n", jenis);
    struct Menu *current = head->next;

    while (current != NULL)
    {
        printf("%d %s\n", current->harga, current->nama);
        current = current->next;
    }
}