/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan UTS dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"
void createList(list *L)
{

    (*L).first = NULL;
}

int countElementB(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        /*list tidak kosong*/
        eBaris *bantu;
        /*inisialisasi*/
        bantu = L.first;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L)
{
    int hasil = 0;
    if (L.col != NULL)
    {
        /*list tidak kosong*/
        eKolom *bantu;
        /*inisialisasi*/
        bantu = L.col;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(char merekPowerBank[], list *L) // fungsi menambahkan elemen ke baris sebagai elemen pertama
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    strcpy(baru->kontainer.merekPowerBank, merekPowerBank);

    baru->col = NULL;
    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char seriPowerBank[], int kapasitasAwal, int ketahanan, int kapasitasAkhir, int tahunBeli, eBaris *L) // fungsi menambahkan elemen ke kolom sebagai elemen pertama
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    strcpy(baru->kontainer_kol.seriPowerBank, seriPowerBank);
    baru->kontainer_kol.kapasitasAwal = kapasitasAwal;
    baru->kontainer_kol.ketahanan = ketahanan;
    baru->kontainer_kol.kapasitasAkhir = kapasitasAkhir;
    baru->kontainer_kol.tahunBeli = tahunBeli;
    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris *prev, char merekPowerBank[]) // fungsi menambahkan elemen ke baris sebagai elemen setelah elemen pertama
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    strcpy(baru->kontainer.merekPowerBank, merekPowerBank);

    baru->col = NULL;
    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom *prev, char seriPowerBank[], int kapasitasAwal, int ketahanan, int kapasitasAkhir, int tahunBeli) // fungsi menambahkan elemen ke kolom sebagai elemen setelah elemen pertama
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    strcpy(baru->kontainer_kol.seriPowerBank, seriPowerBank);
    baru->kontainer_kol.kapasitasAwal = kapasitasAwal;
    baru->kontainer_kol.ketahanan = ketahanan;
    baru->kontainer_kol.kapasitasAkhir = kapasitasAkhir;
    baru->kontainer_kol.tahunBeli = tahunBeli;
    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char merekPowerBank[], list *L) // fungsi menambahkan elemen ke baris sebagai elemen terakhir
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirstB(merekPowerBank, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eBaris *last = (*L).first;
        while (last->next != NULL)
        {
            /*iterasi*/
            last = last->next;
        }
        addAfterB(last, merekPowerBank);
    }
}

void addLastK(char seriPowerBank[], int kapasitasAwal, int ketahanan, int kapasitasAkhir, int tahunBeli, eBaris *L) // fungsi menambahkan elemen ke kolom sebagai elemen terakhir
{
    if ((*L).col == NULL)
    {
        /*jika list adalah list kosong*/
        addFirstK(seriPowerBank, kapasitasAwal, ketahanan, kapasitasAkhir, tahunBeli, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eKolom *last = (*L).col;
        while (last->next_kol != NULL)
        {
            /*iterasi*/
            last = last->next_kol;
        }
        addAfterK(last, seriPowerBank, kapasitasAwal, ketahanan, kapasitasAkhir, tahunBeli);
    }
}

void delFirstK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list bukan list kosong*/
        eKolom *hapus = (*L).col;
        if (countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delAfterK(eKolom *prev)
{
    eKolom *hapus = prev->next_kol;
    if (hapus != NULL)
    {
        if (hapus->next_kol == NULL)
        {
            prev->next_kol = NULL;
        }
        else
        {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delLastK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementK(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstK(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while (last->next_kol != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L)
{
    if (countElementK(*L) != 0)
    {
        int i;
        for (i = countElementK(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

void delFirstB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        eBaris *hapus = (*L).first;
        if (hapus->col != NULL)
        {
            // menghapus semua elemen kolom jika ada
            delAllK(hapus);
        }
        if (countElementB(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev)
{
    if (prev != NULL)
    {
        eBaris *hapus = prev->next;
        if (hapus != NULL)
        {
            if (hapus->col != NULL)
            {
                // menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }
            if (hapus->next == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementB(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstB(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;
            while (last->next != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L)
{
    if (countElementB(*L) != 0)
    {
        int i;
        for (i = countElementB(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris *bantu = L.first;
        int i = 1;
        while (bantu != NULL)
        {
            /*proses*/
            printf("%s", bantu->kontainer.merekPowerBank);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf(" %s %d %d %d %d\n", eCol->kontainer_kol.seriPowerBank, eCol->kontainer_kol.kapasitasAwal, eCol->kontainer_kol.ketahanan, eCol->kontainer_kol.kapasitasAkhir, eCol->kontainer_kol.tahunBeli);
                eCol = eCol->next_kol;
            }
            /*iterasi*/
            bantu = bantu->next;
            i++;
        }
    }
}

eBaris *barisLast(list L)
{
    eBaris *last = L.first;

    while (last->next != NULL)
    {
        last = last->next;
    }
    return last;
}
