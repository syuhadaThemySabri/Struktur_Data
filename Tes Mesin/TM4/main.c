/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 4 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

int main()
{
    list L;
    createList(&L);
    int i = 0;
    dataOrang input[9];
    for (i = 0; i < 9; i++)
    {
        scanf("%s %lld %s", &input[i].nama, &input[i].nomor, &input[i].email);
    }

    i = 0;

    addLast(input[i].nama, input[i].nomor, input[i].email, &L), i++;
    addFirst(input[i].nama, input[i].nomor, input[i].email, &L), i++;
    addBefore(L.first->next, input[i].nama, input[i].nomor, input[i].email, &L), i++;
    printf("Data Kontak\n");
    printf("()()()()()()()()()()()()()()()()\n");
    printElement(L);

    addAfter(L.first->next, input[i].nama, input[i].nomor, input[i].email, &L), i++;
    delAfter(L.first, &L);
    addAfter(L.first, input[i].nama, input[i].nomor, input[i].email, &L), i++;
    addBefore(L.tail, input[i].nama, input[i].nomor, input[i].email, &L), i++;
    delFirst(&L);
    addAfter(L.tail, input[i].nama, input[i].nomor, input[i].email, &L), i++;
    printf("()()()()()()()()()()()()()()()()\n");
    printElement(L);

    delLast(&L);
    addBefore(L.first, input[i].nama, input[i].nomor, input[i].email, &L), i++;
    delAfter(L.first, &L);
    addLast(input[i].nama, input[i].nomor, input[i].email, &L), i++;
    printf(")()()()()()()()()()()()()()()()(\n");
    printElementReverse(L);
    printf("()()()()()()()()()()()()()()()()\n");

    delAll(&L);
    printElement(L);

    return 0;
}