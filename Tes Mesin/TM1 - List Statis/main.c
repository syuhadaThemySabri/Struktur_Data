/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 1 dengan jujur
demi keberkahan-Nya.
Aamiin
*/

#include "header.h"

int main()
{
    char namaPulau[50];
    int populasiPulau;
    float luasPulau;

    list L;
    createList(&L);

    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addFirst(namaPulau, populasiPulau, luasPulau, &L);
    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addFirst(namaPulau, populasiPulau, luasPulau, &L);
    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addAfter(L.first, namaPulau, populasiPulau, luasPulau, &L);
    printElement(L);

    delLast(&L);
    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addAfter(L.data[L.first].next, namaPulau, populasiPulau, luasPulau, &L);
    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addLast(namaPulau, populasiPulau, luasPulau, &L);
    printElement(L);

    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);

    delLast(&L);
    printElement(L);
    return 0;
}