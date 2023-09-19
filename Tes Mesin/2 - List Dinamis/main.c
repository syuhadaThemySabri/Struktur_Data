/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 2 dengan jujur
demi keberkahan-Nya.
Aamiin
*/

#include "header.h"

int main()
{
    char namaIdol[50];
    char namaGrup[50];
    int tahunLahir;
    int tahun = 2023;

    list L;
    createList(&L);

    scanf("%s %s %d", &namaIdol, &namaGrup, &tahunLahir);
    addFirst(namaIdol, namaGrup, tahunLahir, &L);
    scanf("%s %s %d", &namaIdol, &namaGrup, &tahunLahir);
    addLast(namaIdol, namaGrup, tahunLahir, &L);
    scanf("%s %s %d", &namaIdol, &namaGrup, &tahunLahir);
    addAfter(L.first->next, namaIdol, namaGrup, tahunLahir, &L);
    printElement(L, tahun);

    delAfter(L.first->next, &L);
    delLast(&L);
    printElement(L, tahun);

    delAll(&L);
    printElement(L, tahun);

    scanf("%s %s %d", &namaIdol, &namaGrup, &tahunLahir);
    addLast(namaIdol, namaGrup, tahunLahir, &L);
    scanf("%s %s %d", &namaIdol, &namaGrup, &tahunLahir);
    addFirst(namaIdol, namaGrup, tahunLahir, &L);
    delFirst(&L);
    printElement(L, tahun);

    scanf("%s %s %d", &namaIdol, &namaGrup, &tahunLahir);
    addFirst(namaIdol, namaGrup, tahunLahir, &L);
    printElement(L, tahun);

    return 0;
}