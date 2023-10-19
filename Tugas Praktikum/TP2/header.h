/*
Saya Themy Sabri Syuhada dengan NIM 2203903
mengerjakan Tugas Praktikum 2 dengan jujur
dan tidak melakukan kecurangan seperti yang telah
dispesifikasikan demi keberkahan-Nya
Aamiin
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Definisikan struktur data untuk makanan
struct Food
{
    char nama[50];
    int rating;
    int harga;
    struct Food *next;
    struct Food *prev;
};

// Fungsi untuk mencetak list makanan
void printFoodList(struct Food *head);
// Fungsi untuk menambahkan makanan ke list
void addFood(struct Food **head, char nama[], int rating, int harga);
// Fungsi untuk menghapus makanan dengan nama yang panjang ganjil
void removeOddLengthFood(struct Food **head);
// Fungsi untuk mengurutkan list berdasarkan rating secara descending
void sortFoodList(struct Food **head);
// Fungsi untuk mengurutkan list berdasarkan harga secara ascending
void sortFoodListByPrice(struct Food **head);