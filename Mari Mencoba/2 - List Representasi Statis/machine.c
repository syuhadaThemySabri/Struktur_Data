#include "header.h"

void createList(list *L)
{
    (*L).first = -1;
    int i;

    for (i = 0; i < 100; i++)
    {
        // inisialisasi isi array
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int hitung;
        hitung = L.first;

        while (hitung != -1)
        {
            hasil = hasil + 1;
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < 100)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 100))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(float masukan, list *L)
{
    if (countElement(*L) < 100)
    {
        int baru = emptyElement(*L);
        (*L).data[baru].kontainer.masukan = masukan;

        if ((*L).first == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).first;
        }

        (*L).first = baru;
    }
    else
    {
        printf("Sudah tidak dapat ditambah.\n");
    }
}

void printElement(list L)
{
    if (L.first != -1)
    {
        int tunjuk = L.first;

        while (tunjuk != -1)
        {
            printf("%.2f\n", L.data[tunjuk].kontainer.masukan);
            tunjuk = L.data[tunjuk].next;
        }
    }
    else
    {
        printf("List kosong\n");
    }
}