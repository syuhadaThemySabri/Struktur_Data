/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
dengan ini menyatakan mengerjakan kuis 2
secara jujur tanpa melakukan kecurangan seperti yang telah dispesifikasikan
demi mengharapkan keberkahan-Nya
Aamiin
*/
#include "header.h"

int main()
{
    int input, antrian;
    queue Q;
    queue R;
    createEmpty(&Q);
    createEmpty(&R);
    nilaiMatKul makanan;

    scanf("%d", &input);
    for (int i = 0; i < input; i++)
    {
        scanf("%s %s %d %d %d %d", &makanan.nama, &makanan.menu, &makanan.harga, &makanan.jam, &makanan.menit, &makanan.detik);
        if (makanan.jam > 22 || makanan.jam < 17)
        {
            addPriority(makanan.nama, makanan.menu, makanan.harga, makanan.jam, makanan.menit, makanan.detik, &R);
        }
        else
        {
            addPriority(makanan.nama, makanan.menu, makanan.harga, makanan.jam, makanan.menit, makanan.detik, &Q);
        }
    }
    scanf("%d", &antrian);

    // for (int i = 0; i < antrian; i++)
    // {
    //     del(&Q, &R);
    // }

    printQueue(Q);

    // scanf("%s %lld", &aot.nama, &aot.nim);
    // add(aot.nim, aot.nama, &Q);
    // scanf("%s %lld", &aot.nama, &aot.nim);
    // add(aot.nim, aot.nama, &Q);
    // scanf("%s %lld", &aot.nama, &aot.nim);
    // addPriority(aot.nim, aot.nama, 2, &Q);
    // printf("******************\n");
    // printf("Queue 1\n");
    // printQueue(Q);
    // printf("******************\n");
    // del(&Q, &R);
    // printf("Queue 1\n");
    // printQueue(Q);
    // printf("******************\n");
    // printf("Queue 2\n");
    // printQueue(R);
    // printf("******************\n");
    // scanf("%s %lld", &aot.nama, &aot.nim);
    // addPriority(aot.nim, aot.nama, 1, &Q);
    // scanf("%s %lld", &aot.nama, &aot.nim);
    // addPriority(aot.nim, aot.nama, 99, &Q);
    // printf("Queue 1\n");
    // printQueue(Q);
    // printf("******************\n");
    // del(&Q, &R);
    // del(&Q, &R);
    // scanf("%s %lld", &aot.nama, &aot.nim);
    // add(aot.nim, aot.nama, &Q);
    // printf("Queue 1\n");
    // printQueue(Q);
    // printf("******************\n");
    // printf("Queue 2\n");
    // printQueue(R);
    // printf("******************\n");
    return 0;
}