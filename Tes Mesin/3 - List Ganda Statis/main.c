/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 3 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

int main()
{
    char jenis[15];
    char platNomor[50];
    int tahun;
    char pemilik[50];

    list L;
    createList(&L);

    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addFirst(jenis, platNomor, tahun, pemilik, &L);
    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addLast(jenis, platNomor, tahun, pemilik, &L);
    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addAfter(L.head, jenis, platNomor, tahun, pemilik, &L);
    printf("Data Kendaraan\n");
    printElement(L);

    delAfter(L.data[L.head].next, &L);
    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addAfter(L.head, jenis, platNomor, tahun, pemilik, &L);
    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addAfter(L.data[L.tail].previous, jenis, platNomor, tahun, pemilik, &L);
    delFirst(&L);
    printElement(L);

    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addFirst(jenis, platNomor, tahun, pemilik, &L);
    scanf("%s %s %d %s", &jenis, &platNomor, &tahun, &pemilik);
    addAfter(L.data[L.head].next, jenis, platNomor, tahun, pemilik, &L);
    delLast(&L);
    printElementReverse(L);

    delAll(&L);
    printElement(L);
    return 0;
}