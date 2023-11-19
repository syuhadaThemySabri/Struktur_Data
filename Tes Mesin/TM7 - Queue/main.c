/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 7 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

int main()
{
    queue Q;
    queue R;
    createEmpty(&Q);
    createEmpty(&R);
    nilaiMatKul aot;

    scanf("%s %lld", &aot.nama, &aot.nim);
    add(aot.nim, aot.nama, &Q);
    scanf("%s %lld", &aot.nama, &aot.nim);
    add(aot.nim, aot.nama, &Q);
    scanf("%s %lld", &aot.nama, &aot.nim);
    addPriority(aot.nim, aot.nama, 2, &Q);
    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q);
    printf("******************\n");
    del(&Q, &R);
    printf("Queue 1\n");
    printQueue(Q);
    printf("******************\n");
    printf("Queue 2\n");
    printQueue(R);
    printf("******************\n");
    scanf("%s %lld", &aot.nama, &aot.nim);
    addPriority(aot.nim, aot.nama, 1, &Q);
    scanf("%s %lld", &aot.nama, &aot.nim);
    addPriority(aot.nim, aot.nama, 99, &Q);
    printf("Queue 1\n");
    printQueue(Q);
    printf("******************\n");
    del(&Q, &R);
    del(&Q, &R);
    scanf("%s %lld", &aot.nama, &aot.nim);
    add(aot.nim, aot.nama, &Q);
    printf("Queue 1\n");
    printQueue(Q);
    printf("******************\n");
    printf("Queue 2\n");
    printQueue(R);
    printf("******************\n");
    return 0;
}