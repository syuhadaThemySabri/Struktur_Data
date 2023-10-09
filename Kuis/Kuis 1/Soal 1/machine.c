/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 1
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include "header.h"

// fungsi untuk membuat list
void createList(list *L)
{
    (*L).first = NULL;
}

// fungsi untuk menghitung elemen
int countElement(list L)
{
    int result = 0;

    if (L.first != NULL)
    {
        // Kalo listnya ga kosong
        elemen *pointer;

        // inisialisasi proses
        pointer = L.first;

        // selama pointernya gak null
        while (pointer != NULL)
        {
            // proses dieksekusi
            result++;
            // iterasi
            pointer = pointer->next;
        }
    }

    // mengembalikan nilai hasil
    return result;
}

// fungsi untuk menambahkan list pada urutan pertama
void addFirst(char namaIdol[], char namaGrup[], int tahunLahir, list *L)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen)); // assign alokasi pointer memori ke variabel new
    // assign the nim, nama, and nilai value
    strcpy(new->kontainer.namaIdol, namaIdol);
    strcpy(new->kontainer.namaGrup, namaGrup);
    new->kontainer.tahunLahir = tahunLahir;
    if ((*L).first == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

// fungsi untuk menambahkan pada list di tengah-tengah
void addAfter(elemen *previous, char namaIdol[], char namaGrup[], int tahunLahir, list *L)
{
    if (previous != NULL) // cek kalo null dia ga bisa nambah elemen soalnya
    {
        // kalo ga null dia bisa nambah elemen baru
        elemen *new;
        new = (elemen *)malloc(sizeof(elemen));
        strcpy(new->kontainer.namaIdol, namaIdol);
        strcpy(new->kontainer.namaGrup, namaGrup);
        new->kontainer.tahunLahir = tahunLahir;
        if (previous->next == NULL)
        {
            new->next = NULL;
        }
        else
        {
            new->next = previous->next;
        }
        previous->next = new;
        new = NULL;
    }
    else // kalo previousnya null maka kasih error message
    {
        printf("Error due to the previous element is null.\n");
    }
}

// fungsi untuk menambahkan elemen pada urutan terakhir di dalam list
void addLast(char namaIdol[], char namaGrup[], int tahunLahir, list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(namaIdol, namaGrup, tahunLahir, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        elemen *prev = (*L).first;
        while (prev->next != NULL)
        {
            /*iterasi*/
            prev = prev->next;
        }
        addAfter(prev, namaIdol, namaGrup, tahunLahir, L);
    }
}

// fungsi untuk menghapus elemen pertama pada list
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        elemen *remove = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            remove->next = NULL;
        }
        free(remove);
    }
}

// fungsi untuk menghapus elemen yang berada di tengah-tengah list
void delAfter(elemen *previous, list *L)
{
    if (previous != NULL)
    {
        elemen *remove = previous->next;
        if (remove != NULL)
        {
            if (remove->next == NULL)
            {
                previous->next = NULL;
            }
            else
            {
                previous->next = remove->next;
                remove->next = NULL;
            }
            free(remove);
        }
    }
    else
    {
        printf("Error due to the previous element is null.\n");
    }
}

// fungsi untuk menghapus elemen terakhir pada list
void delLast(list *L)
{

    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if (countElement(*L) == 1)
        {
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            elemen *last = (*L).first;
            elemen *previous;

            while (last->next != NULL)
            {
                /*iterasi*/
                previous = last;
                last = last->next;
            }
            delAfter(previous, L);
        }
    }
}

// fungsi untuk print list
void printElement(list L, int tahun)
{
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen *tunjuk = L.first;
        int counter = 1;
        printf(":) :) :) :) :) :) :) :) :) :)\n");
        while (tunjuk != NULL)
        {
            /*proses*/
            printf("%s ", tunjuk->kontainer.namaIdol);
            printf("%s - ", tunjuk->kontainer.namaGrup);
            printf("%d tahun\n", tahun - tunjuk->kontainer.tahunLahir);
            /*iterasi*/
            tunjuk = tunjuk->next;
            counter++;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

// fungsi untuk menghapus seluruh elemen di dalam list
void delAll(list *L)
{

    if (countElement(*L) != 0)
    {
        int counter;

        for (counter = countElement(*L); counter >= 1; counter--)
        {
            /*proses menghapus elemen list*/
            delLast(L);
        }
    }
}