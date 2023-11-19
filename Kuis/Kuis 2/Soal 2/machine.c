/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 2
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil++;
    }
    return hasil;
}

int countElement(queue Q)
{
    int hasil = 0;
    if (Q.first != NULL)
    {
        /* queue tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = Q.first;
        while (bantu != NULL)
        {
            /* proses */
            hasil++;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nama[], char menu[], int harga, int jam, int menit, int detik, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.menu, menu);
    baru->kontainer.harga = harga;
    baru->kontainer.jam = jam;
    baru->kontainer.menit = menit;
    baru->kontainer.detik = detik;
    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char nama[], char menu[], int harga, int jam, int menit, int detik, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.menu, menu);
    baru->kontainer.harga = harga;
    baru->kontainer.jam = jam;
    baru->kontainer.menit = menit;
    baru->kontainer.detik = detik;
    baru->next = NULL;

    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
        (*Q).last = baru;
    }
    else
    {
        int counter = 0;
        elemen *bantu1 = (*Q).first;
        elemen *bantu2 = (*Q).first;
        elemen *previous;
        while (counter < jam || bantu1 != NULL)
        {
            bantu1->next = (*Q).first;
            (*Q).first = baru;
            counter++;
        }
        while (bantu2->kontainer.jam > bantu1->kontainer.jam || bantu2->kontainer.menit > bantu1->kontainer.menit || bantu2->kontainer.detik > bantu1->kontainer.detik)
        {
            previous = bantu2;
            bantu2 = bantu2->next;
        }
        if (bantu1 != NULL)
        {
            if (bantu1->next->kontainer.nama == (*Q).first->kontainer.nama) // priority itu 1
            {
                // baru->next = (*Q).first;
                bantu1->next = baru;
            }
            else // priority tengah-tengah antrian
            {
                previous->next = baru;
                baru->next = bantu1;
            }
        }
        // else // priority lebih dari jumlah antrian
        // {
        //     (*Q).last->next = baru;
        //     (*Q).last = baru;
        // }
    }
    baru = NULL;
}

void del(queue *Q, queue *R)
{
    if ((*Q).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q).first;
        if (countElement(*Q) == 1)
        {
            if ((*R).first == NULL)
            {
                (*R).first = hapus;
                (*R).last = hapus;
            }
            else
            {
                (*R).last->next = hapus;
                (*R).last = hapus;
            }
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else
        {
            if ((*R).first == NULL)
            {
                (*R).first = hapus;
                (*R).last = hapus;
            }
            else
            {
                (*R).last->next = hapus;
                (*R).last = hapus;
            }
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        hapus = NULL;
    }
}

void printQueue(queue Q)
{
    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s %s %d %d %d %d\n",
                   bantu->kontainer.nama, bantu->kontainer.menu, bantu->kontainer.harga,
                   bantu->kontainer.jam, bantu->kontainer.menit, bantu->kontainer.detik);
            /* iterasi */
            bantu = bantu->next;
            i++;
        }
    }
}
