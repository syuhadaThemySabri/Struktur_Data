#include "soal1header.h"

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
        char nama[51];
        char jenis[51];
        scanf("%d %s %s", &harga, &nama, &jenis);
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
    printf("\n");
    tampilkanMenu(regulerHead, "reguler");

    return 0;
}