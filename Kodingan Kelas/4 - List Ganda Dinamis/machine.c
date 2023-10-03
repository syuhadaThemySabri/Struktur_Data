#include "header.h"

// prosedur untuk membuat list
void createList(list *L)
{
    (*L).first = NULL; // buat dari depan
    (*L).tail = NULL;  // buat dari belakang
}

// function untuk menghitung elemen
int countElement(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        // kalo listnya ga kosong
        elemen *bantu;
        // inisialisasi
        bantu = L.first;
        while (bantu != NULL)
        {
            // proses
            hasil = hasil + 1;
            // iterasi
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);
    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *before, char nim[], char nama[], char nilai[], list *L)
{

    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.nilai, nilai);
        if (before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        // kalo listnya kosong
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        // kalo listnya ga kosong
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        // kalo listnya bukan list kosong
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *hapus = before->next;
        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                before->next = NULL;
                (*L).tail = before;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
    }
}

void delLast(list *L)
{
    // checking apakah listnya punya elemen atau ga
    if ((*L).first != NULL)
    {
        // cek jumlah elemen dari listnya
        if (countElement(*L) == 1)
        {
            // kalo listnya cuma berisi satu elemen
            delFirst(L);
        }
        else
        {
            // jika banyak elemen
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        // kalo lisnya ga kosong
        // inisialisasi
        elemen *bantu = L.first;
        int i = 1;
        while (bantu != NULL)
        {
            // proses print element di dalam list
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", bantu->kontainer.nim);
            printf("nama : %s\n", bantu->kontainer.nama);
            printf("nilai : %s\n", bantu->kontainer.nilai);
            printf("------------\n");

            // iterasi
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        // kalo listnya kosong, kasih message
        printf("list kosong\n");
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;

        for (i = countElement(*L); i >= 1; i--)
        {
            // proses menghapus seluruh elemen di dalam list
            delLast(L);
        }
    }
}