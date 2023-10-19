#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Struktur untuk menu makanan
struct Menu
{
    int harga;
    char nama[50];
    char jenis[10];
    struct Menu *next;
};

// Fungsi untuk menambahkan menu ke dalam list
void tambahMenu(struct Menu *head, int harga, const char *nama, const char *jenis)
{
    struct Menu *newNode = (struct Menu *)malloc(sizeof(struct Menu));
    newNode->harga = harga;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jenis, jenis);
    newNode->next = NULL;

    struct Menu *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

// Fungsi untuk memisahkan menu promo dan reguler
void pisahkanMenu(struct Menu *head, struct Menu **promoHead, struct Menu **regulerHead)
{
    struct Menu *current = head->next;

    while (current != NULL)
    {
        if (strcmp(current->jenis, "promo") == 0)
        {
            tambahMenu(*promoHead, current->harga, current->nama, current->jenis);
        }
        else
        {
            tambahMenu(*regulerHead, current->harga, current->nama, current->jenis);
        }
        current = current->next;
    }
}

// Fungsi untuk menampilkan isi list menu
void tampilkanMenu(struct Menu *head, const char *jenis)
{
    printf("list %s:\n", jenis);
    struct Menu *current = head->next;

    while (current != NULL)
    {
        printf("%d %s\n", current->harga, current->nama);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    // Inisialisasi list menu
    struct Menu *menuHead = (struct Menu *)malloc(sizeof(struct Menu));
    menuHead->next = NULL;

    for (int i = 0; i < n; i++)
    {
        int harga;
        char nama[50];
        char jenis[10];
        scanf("%d %s %s", &harga, nama, jenis);
        tambahMenu(menuHead, harga, nama, jenis);
    }

    // Inisialisasi list promo dan list reguler
    struct Menu *promoHead = (struct Menu *)malloc(sizeof(struct Menu));
    promoHead->next = NULL;
    struct Menu *regulerHead = (struct Menu *)malloc(sizeof(struct Menu));
    regulerHead->next = NULL;

    // Pisahkan menu menjadi promo dan reguler
    pisahkanMenu(menuHead, &promoHead, &regulerHead);

    // Tampilkan list promo dan list reguler
    tampilkanMenu(promoHead, "promo");
    tampilkanMenu(regulerHead, "reguler");

    // Membebaskan memori
    free(menuHead);
    free(promoHead);
    free(regulerHead);

    return 0;
}
