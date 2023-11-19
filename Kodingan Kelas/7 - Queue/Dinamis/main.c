#include "header.h"

int main()
{
    queue Q;
    queue R;
    createEmpty(&Q);
    createEmpty(&R);
    nilaiMatKul aot;

    scanf("%s %d", aot.nama, aot.nim);
    add(aot.nim, aot.nama, &Q);
    scanf("%s %d", aot.nama, aot.nim);
    add(aot.nim, aot.nama, &Q);
    printQueue(Q);
    printf("=================\n");
    del(&Q, &R);
    del(&Q, &R);
    printQueue(R);
    printf("=================\n");
    return 0;
}