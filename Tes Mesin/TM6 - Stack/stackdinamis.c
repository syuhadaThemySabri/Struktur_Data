/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 6 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "stackdinamis.h"

int main()
{

    hargaBuku data;
    stack S;
    stack T;
    createEmptyStack(&S);
    createEmptyStack(&T);

    printf("==========================\n");
    printStack(S);
    printf("\n");
    printStack2(T);
    printf("==========================\n");
    scanf("%s %d", &data.buku, &data.harga);
    pushToStack(data.buku, data.harga, &S);
    scanf("%s %d", &data.buku, &data.harga);
    pushToStack(data.buku, data.harga, &T);
    scanf("%s %d", &data.buku, &data.harga);
    pushToStack(data.buku, data.harga, &T);
    printStack(S);
    printf("\n");
    printStack2(T);
    printf("==========================\n");
    popOutStack(&S);
    popStackAndReturn(&T, &S);
    scanf("%s %d", &data.buku, &data.harga);
    pushToStack(data.buku, data.harga, &S);
    scanf("%s %d", &data.buku, &data.harga);
    pushToStack(data.buku, data.harga, &T);
    scanf("%s %d", &data.buku, &data.harga);
    pushToStack(data.buku, data.harga, &S);
    popOutStack(&T);
    popStackAndReturn(&S, &T);
    printStack(S);
    printf("\n");
    printStack2(T);
    printf("==========================\n");
    return 0;
}
