/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 1 dengan jujur
demi keberkahan-Nya.
Aamiin
*/

#include "header.h"

// bikin list pake pass by reference
void createList(list *L)
{
    (*L).first = -1;
    int i; // variable counter for looping

    for (i = 0; i < 10; i++)
    {
        // inisialisasi isi array
        (*L).data[i].next = -2;
    }
}

// buat count element supaya tau jumlah elemen di list
int countElement(list L)
{
    int result = 0;
    if (L.first != -1)
    {
        // kalo list ga kosong
        int count;

        // inisialisasi
        count = L.first;

        // selama counternya bukan -1
        while (count != -1)
        {
            // proses dimulai
            result += 1;

            // iterasi
            count = L.data[count].next;
        }
    }

    // mengembalikan nilai result
    return result;
}

int emptyElement(list L)
{
    int result = -1; // set nilai result

    if (countElement(L) < 10)
    {
        int find = 0;
        int varLoop = 0;

        // selama find == 0 (belom ditemukan) dan varLoop kurang dari 10
        while ((find == 0) && (varLoop < 10))
        {
            if (L.data[varLoop].next == -2)
            {
                result = varLoop;
                find = 1;
            }
            else
            {
                varLoop++;
            }
        }
    }

    // mengembalikan nilai result
    return result;
}

void addFirst(char namaPulau[], int populasiPulau, float luasPulau, list *L)
{
    if (countElement(*L) < 10)
    {
        int new = emptyElement(*L); // digunakan untuk mengembalikan nilai yang masih kosong
        strcpy((*L).data[new].kontainer.namaPulau, namaPulau);
        (*L).data[new].kontainer.populasiPulau = populasiPulau;
        (*L).data[new].kontainer.luasPulau = luasPulau;

        if ((*L).first == -1)
        {
            // cek dulu kalo listnya kosong
            (*L).data[new].next = -1;
        }
        else
        {
            // kalo listnya ga kosong nih
            (*L).data[new].next = (*L).first; // yang barunya harus nyapa dulu biar ga jadi zombie
        }

        (*L).first = new;
    }
    else
    {
        // proses dieksekusi kalo arraynya penuh
        printf("Array sudah penuh dan sudah tidak bisa ditambah lagi.\n");
    }
}

void addAfter(int previous, char namaPulau[], int populasiPulau, float luasPulau, list *L)
{
    if (countElement(*L) < 10)
    {
        int new = emptyElement(*L);

        strcpy((*L).data[new].kontainer.namaPulau, namaPulau);
        (*L).data[new].kontainer.populasiPulau = populasiPulau;
        (*L).data[new].kontainer.luasPulau = luasPulau;

        if ((*L).data[previous].next == 1)
        {
            (*L).data[new].next = -1; // kalo mau nambah di belakang
        }
        else
        {
            (*L).data[new].next = (*L).data[previous].next; // tambah elemen di tengah
        }
        (*L).data[previous].next = new;
    }
    else
    {
        // kalo arraynya udah penuh
        printf("Array sudah penuh dan sudah tidak bisa ditambah lagi.\n");
    }
}

void addLast(char namaPulau[], int populasiPulau, float luasPulau, list *L)
{
    if ((*L).first == -1)
    {
        // kalo listnya masih kosong
        addFirst(namaPulau, populasiPulau, luasPulau, L); // dijadiin elemen pertama karena listnya masih kosong
    }
    else
    {
        // proses kalo listnya sudah berisi dengan elemeen
        if (countElement(*L) < 10)
        {
            // kalo arraynya masih belum penuh
            // akan mencari elemen terakhir
            // proses inisialisasi di bawah
            int previous = (*L).first;

            while ((*L).data[previous].next != -1)
            {
                // proses iterasi
                previous = (*L).data[previous].next; // bakal maju terus ke depan
            }

            addAfter(previous, namaPulau, populasiPulau, luasPulau, L);
        }
        else
        {
            // Kalo arraynya udah penuh
            printf("Array sudah penuh dan sudah tidak bisa ditambah lagi.\n");
        }
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1) // dicek dulu jangan sampai null karena mau dihapus
    {
        int remove = (*L).first;
        if (countElement(*L) == 1) // kalo elemennya cuma 1
        {
            (*L).first = -1;
        }
        else // kalo elemennya banyak (jamak/lebih dari satu)
        {
            (*L).first = (*L).data[remove].next;
        }

        // elemen paling pertama sebelumnya dikosongkan
        (*L).data[remove].next = -2;
    }
    else
    {
        // kalo listnya masih kosong
        printf("Li$t Ko$ong\n");
    }
}

void delAfter(int previous, list *L)
{
    int remove = (*L).data[previous].next; // cek remove apakah null atau ga

    if (remove != -1) // cek kondisi
    {
        // hapus elemen terakhir
        if ((*L).data[remove].next == -1)
        {
            (*L).data[previous].next = -1;
        }
        else
        {
            // hapus elemen yang ada di tengah list
            (*L).data[previous].next = (*L).data[remove].next;
        }
        // dilakukan pengosongan elemen
        (*L).data[remove].next = -2;
    }
}

void delLast(list *L)
{
    if ((*L).first != -1) // cek kondisi apakah null atau tidak
    {
        if (countElement(*L) == 1)
        {
            // kalo listnya hanya berisi 1 elemen
            delFirst(L);
        }
        else
        {
            int remove = (*L).first;
            int previous;
            while ((*L).data[remove].next != -1)
            {
                // proses iterasi
                previous = remove;
                remove = (*L).data[remove].next;
            }
            // elemen yang asalnya -1 dari elemen terakhir akan menjadi elemen terakhir
            delAfter(previous, L);
        }
    }
    else
    {
        // kalo listnya kosong
        printf("Li$t Ko$ong\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

// print all element on the list
void printElement(list L)
{
    if (L.first != -1)
    {
        // inisialisasi
        int pointer = L.first;
        int counter = 1;

        while (pointer != -1)
        {
            // proses menampilkan elemen
            printf("%s - %d orang - %.2f km2\n", L.data[pointer].kontainer.namaPulau, L.data[pointer].kontainer.populasiPulau, L.data[pointer].kontainer.luasPulau);

            // iterasi
            pointer = L.data[pointer].next;
            counter++;
        }
    }
    else
    {
        // kalo listnya kosong
        printf("Li$t Ko$ong\n");
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// delete all element on the list
void delAll(list *L)
{
    int counter; // counter var for looping
    for (counter = countElement(*L); counter >= 1; counter--)
    {
        // proses mengahpus semua elemen di dalam list
        delLast(L);
    }
}