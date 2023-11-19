/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 7 dengan jujur
demi keberkahan-Nya.
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

void add(long long nim, char nama[], queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nim = nim;
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

void addPriority(long long nim, char nama[], int priorityNumber, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nim = nim;
    baru->next = NULL;

    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
        (*Q).last = baru;
    }
    else
    {
        int counter = 1;
        elemen *bantu1 = (*Q).first;
        elemen *bantu2 = (*Q).first;
        elemen *previous;
        while (counter < priorityNumber && bantu1 != NULL)
        {
            bantu1 = bantu1->next;
            counter++;
        }
        while (bantu2 != bantu1)
        {
            previous = bantu2;
            bantu2 = bantu2->next;
        }
        if (bantu1 != NULL)
        {
            if (bantu1 == (*Q).first) // priority itu 1
            {
                baru->next = (*Q).first;
                (*Q).first = baru;
            }
            else // priority tengah-tengah antrian
            {
                previous->next = baru;
                baru->next = bantu1;
            }
        }
        else // priority lebih dari jumlah antrian
        {
            (*Q).last->next = baru;
            (*Q).last = baru;
        }
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
            printf("%s %lld\n", bantu->kontainer.nama, bantu->kontainer.nim);
            /* iterasi */
            bantu = bantu->next;
            i++;
        }
    }
}
