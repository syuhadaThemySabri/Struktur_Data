
/*
Saya Themy Sabri Syuhada dengan NIM 2203903
mengerjakan Tugas Praktikum 2 dengan jujur
dan tidak melakukan kecurangan seperti yang telah
dispesifikasikan demi keberkahan-Nya
Aamiin
*/

#include "header.h"

int main()
{
    struct Food *head = NULL;
    char nama[50];
    float rating;
    int harga;

    // Membaca input makanan
    while (1)
    {
        scanf("%s", nama);
        if (strcmp(nama, "udah") == 0)
        {
            break;
        }
        scanf("%d %d", &rating, &harga);
        addFood(&head, nama, rating, harga);
    }

    // Mencetak list makanan sebelum difilter
    printf("List makanan sebelum difilter:\n");
    printFoodList(head);

    // Menghapus makanan dengan nama yang panjang ganjil
    removeOddLengthFood(&head);

    // Mengurutkan list berdasarkan rating secara descending
    sortFoodList(&head);

    // Mencetak list makanan setelah difilter
    printf("List makanan setelah difilter:\n");
    printFoodList(head);

    // Mengurutkan list berdasarkan harga secara ascending
    sortFoodListByPrice(&head);

    // Mencetak list makanan setelah diurutkan berdasarkan harga
    printf("List makanan setelah diurutkan berdasarkan harga:\n");
    printFoodList(head);

    return 0;
}
