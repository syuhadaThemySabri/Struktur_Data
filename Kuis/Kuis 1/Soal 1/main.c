/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 1
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include "header.h"

int main()
{
    int input;
    int harga;
    char namaMenu[51];
    char statusMenu[51];

    list promo, reguler, tampung;
    createList(&promo);
    createList(&reguler);
    createList(&tampung);

    scanf("%d", &input);

    for (int i = 0; i < input; i++)
    {
        scanf("%d %s %s", &harga, &namaMenu, &statusMenu);
        if (strcmp(statusMenu, "promo") == 0)
        {
            addLast(namaMenu, harga, statusMenu, &promo);
        }
        else
        {
            addLast(namaMenu, harga, statusMenu, &reguler);
        }
    }

    printf("list promo:\n");
    printElement(promo);
    printf("\n");
    printf("list reguler:\n");
    printElement(reguler);

    return 0;
}