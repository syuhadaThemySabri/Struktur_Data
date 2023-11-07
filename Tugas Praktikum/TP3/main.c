/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan Tugas Praktikum 3 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

int main()
{
    // variabel buat nampung  input jumlah buku
    int input;

    // deklarasi tiga buah stack. All buat nampung semua, fiksi buat buku fiksi, nonFiksi buat buku non-fiksi
    stack All;
    stack fiksi;
    stack nonFiksi;

    // set semua stack jadi kosong
    createEmptyStack(&All);
    createEmptyStack(&fiksi);
    createEmptyStack(&nonFiksi);

    // minta masukan user
    scanf("%d", &input);

    // bikin struct sebanyak inputan user
    hargaBuku data[input];

    // looping buat minta user masukin kode buku dan judul buku sebanyak inputan sebelumnya
    for (int i = 0; i < input; i++)
    {
        scanf("%d %s", &data[i].kode, &data[i].buku); // minta input
        pushToStack(data[i], &All);                   // masukin ke stack All dulu buat ditampung
    }

    for (int i = input - 1; i >= 0; i--) // looping awal buat nunjuk stack All dimulai dari paling atas
    {
        int counter = 0;                               // variabel buat nampung jumlah ascii setiap buku
        for (int j = 0; j < strlen(data[i].buku); j++) // looping kedua buat ngambil setiap karakter dari judul buku
        {
            if (data[i].buku[j] != '\0') // selama bukan enter/spasi
            {
                counter += data[i].buku[j]; // counter bakal nambah sesuai ascii karakternya
            }
        }
        if (counter % 2 == 0) // checking kondisi. Kalo jumlah asciinya genap, maka buku tersebut masuk ke stack nonFiksi
        {
            popStackAndReturn(&All, &nonFiksi); // oper buku dari All ke nonFiksi
        }
        else
        {
            popStackAndReturn(&All, &fiksi); // Kalo ascii ganjil, maka oper buku dari All ke fiksi
        }
    }

    // print output
    printStack(fiksi);
    printf("\n");
    printStack2(nonFiksi);

    return 0;
}
