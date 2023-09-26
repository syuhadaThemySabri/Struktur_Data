/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 3 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

void createList(list *L)
{

    (*L).head = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].previous = -2;
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.head != -1)
    {
        // kalo listnya ga kosong
        int bantu;
        // inisialisasi looping
        bantu = L.head;
        while (bantu != -1)
        {
            // proses
            hasil++;
            // iterasi
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

int emptyElement(list L)
{
    int result = -1;

    // checking kalo listnya masih kurang dari 10 (alokasi di awal 10 soalnya)
    if (countElement(L) < 10)
    {
        int find = 0;
        int i = 0;
        while ((find == 0) && (i < 10))
        {
            if (L.data[i].next == -2)
            {
                result = i;
                find = 1;
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}

void addFirst(char jenis[], char platNomor[], int tahun, char pemilik[], list *L)
{
    // checking kalo listnya masih kurang dari 10 (alokasi di awal 10 soalnya)
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.jenis, jenis);
        strcpy((*L).data[baru].kontainer.platNomor, platNomor);
        (*L).data[baru].kontainer.tahun = tahun;
        strcpy((*L).data[baru].kontainer.pemilik, pemilik);

        if ((*L).head == -1)
        {
            // kalo listnya kosong
            (*L).data[baru].previous = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else
        {
            // kalo listnya ga kosong
            (*L).data[baru].previous = -1;
            (*L).data[baru].next = (*L).head;
            (*L).data[(*L).head].previous = baru;
        }

        (*L).head = baru;
    }
    else
    {
        // kali listnya udah penuh
        printf("List sudah penuh dan sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char jenis[], char platNomor[], int tahun, char pemilik[], list *L)
{
    // checking kalo listnya masih kurang dari 10 (alokasi di awal 10 soalnya)
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);

        strcpy((*L).data[baru].kontainer.jenis, jenis);
        strcpy((*L).data[baru].kontainer.platNomor, platNomor);
        (*L).data[baru].kontainer.tahun = tahun;
        strcpy((*L).data[baru].kontainer.pemilik, pemilik);

        if ((*L).data[before].next != -1)
        {
            // jika baru bukan menjadi elemen terakhir
            (*L).data[baru].previous = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].previous = baru;
        }
        else
        {
            // jika baru menjadi elemen terakhir
            (*L).data[baru].previous = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    }
    else
    {
        // kali listnya udah penuh
        printf("List sudah penuh dan sudah tidak dapat ditambah\n");
    }
}

void addLast(char jenis[], char platNomor[], int tahun, char pemilik[], list *L)
{

    if ((*L).head == -1)
    {
        // proses jika list masih kosong
        addFirst(jenis, platNomor, tahun, pemilik, L);
    }
    else
    {
        // proses jika list telah berisi elemen
        addAfter((*L).tail, jenis, platNomor, tahun, pemilik, L);
    }
}

void delFirst(list *L)
{
    if ((*L).head != -1)
    {
        int hapus = (*L).head;
        if (countElement(*L) == 1)
        {
            (*L).head = -1;
            (*L).tail = -1;
        }
        else
        {
            (*L).head = (*L).data[(*L).head].next;
            (*L).data[(*L).head].previous = -1;
        }
        // elemen awal sebelumnya dikosongkan
        (*L).data[hapus].previous = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        // proses jika listnya kosong
        printf("List Kosong.\n");
    }
}

void delAfter(int before, list *L)
{
    int hapus = (*L).data[before].next;
    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).tail = before;
            (*L).data[before].next = -1;
        }
        else
        {
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].previous = before;
        }
        // proses pengosongan elemen
        (*L).data[hapus].previous = -2;
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{

    if ((*L).head != -1)
    {
        if (countElement(*L) == 1)
        {
            // kalo listnya cuma berisi 1 elemen, maka langsung panggil delFirst
            delFirst(L);
        }
        else
        {
            // elemen sebelum elemen terakhir menjadi elemen terakhir
            delAfter((*L).data[(*L).tail].previous, L);
        }
    }
    else
    {
        // Proses jika listnya kosong
        printf("List Kosong.\n");
    }
}

void printElement(list L)
{
    if (L.head != -1)
    {
        // inisialisasi
        int bantu = L.head;
        while (bantu != -1)
        {
            // proses menampilkan elemen
            printf("%s - %s - %d - %s\n", L.data[bantu].kontainer.jenis, L.data[bantu].kontainer.platNomor, L.data[bantu].kontainer.tahun, L.data[bantu].kontainer.pemilik);
            // iterasi
            bantu = L.data[bantu].next;
        }
        printf("Jumlah Elemen; %d\n", countElement(L));
    }
    else
    {
        // proses jika listnya kosong
        printf("List Kosong.\n");
    }

    printf("========================================\n");
}

void printElementReverse(list L)
{
    if (L.tail != -1)
    {
        // inisialisasi
        int bantu = L.tail;
        while (bantu != -1)
        {
            // proses menampilkan elemen
            printf("%s - %s - %d - %s\n", L.data[bantu].kontainer.jenis, L.data[bantu].kontainer.platNomor, L.data[bantu].kontainer.tahun, L.data[bantu].kontainer.pemilik);
            // iterasi
            bantu = L.data[bantu].previous;
        }
        printf("Jumlah Elemen; %d\n", countElement(L));
    }
    else
    {
        // proses jika listnya kosong
        printf("List Kosong.\n");
    }
    printf("****************************************\n");
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        // proses pengosongan list
        delLast(L);
    }
}