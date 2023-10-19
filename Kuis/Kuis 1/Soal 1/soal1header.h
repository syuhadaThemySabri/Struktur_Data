#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Struktur untuk menu makanan
struct Menu
{
    int harga;
    char nama[51];
    char jenis[51];
    struct Menu *next;
};

// Fungsi untuk menambahkan menu ke dalam list
void tambahMenu(struct Menu *head, int harga, const char *nama, const char *jenis);

// Fungsi untuk memisahkan menu promo dan reguler
void pisahkanMenu(struct Menu *head, struct Menu **promoHead, struct Menu **regulerHead);

// Fungsi untuk menampilkan isi list menu
void tampilkanMenu(struct Menu *head, const char *jenis);