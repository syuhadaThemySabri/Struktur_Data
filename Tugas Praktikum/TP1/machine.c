/*
Saya Themy Sabri Syuhada dengan NIM 2203903
mengerjakan Tugas Praktikum 1 dengan jujur
dan tidak melakukan kecurangan seperti yang telah
dispesifikasikan demi keberkahan-Nya
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
void addFirst(char namaChar[], char namaTeknik[], int power, list *L)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen)); // assign alokasi pointer memori ke variabel new
    // assign the nim, nama, and nilai value
    strcpy(new->kontainer.namaChar, namaChar);
    strcpy(new->kontainer.namaTeknik, namaTeknik);
    new->kontainer.power = power;
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
void addAfter(elemen *previous, char namaChar[], char namaTeknik[], int power, list *L)
{
    if (previous != NULL) // cek kalo null dia ga bisa nambah elemen soalnya
    {
        // kalo ga null dia bisa nambah elemen baru
        elemen *new;
        new = (elemen *)malloc(sizeof(elemen));
        strcpy(new->kontainer.namaChar, namaChar);
        strcpy(new->kontainer.namaTeknik, namaTeknik);
        new->kontainer.power = power;
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
void addLast(char namaChar[], char namaTeknik[], int power, list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(namaChar, namaTeknik, power, L);
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
        addAfter(prev, namaChar, namaTeknik, power, L);
    }
}

// fungsi untuk print list
void printElement(list L, int totalPower)
{
    // int i = 0;
    // elemen *tunjukElemenFirstNextnya = L.first->next; // pointer buat nunjuk elemen next dari first (ya elemen ke 2 kali ya)
    // if (L.first->next != NULL)
    // {
    // }
    if (L.first != NULL && totalPower % 2 == 1)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen *tunjuk = L.first;
        while (tunjuk != NULL)
        {
            /*proses*/
            printf("%s ", tunjuk->kontainer.namaChar);
            printf("%s ", tunjuk->kontainer.namaTeknik);
            printf("%d\n", tunjuk->kontainer.power);
            /*iterasi*/
            tunjuk = tunjuk->next;
        }
        printf("WIN\n");
    }
    else
    {
        elemen *tunjuk = L.first;
        while (tunjuk != NULL)
        {
            /*proses*/
            printf("%s ", tunjuk->kontainer.namaChar);
            printf("%s ", tunjuk->kontainer.namaTeknik);
            printf("%d\n", tunjuk->kontainer.power);
            /*iterasi*/
            tunjuk = tunjuk->next;
        }
        printf("LOSE\n");
    }
}