/*
Saya Themy Sabri Syuhada dengan NIM 2203903
mengerjakan Tugas Praktikum 1 dengan jujur
dan tidak melakukan kecurangan seperti yang telah
dispesifikasikan demi keberkahan-Nya
Aamiin
*/

#include "header.h"

int main()
{
    list L;
    createList(&L);
    char sortBy[20], sort[20];
    char namaChar[50];
    char namaTeknik[50];
    int power;
    int flag = 0;
    int i = 0, totalPower = 0;

    while (flag == 0)
    {
        scanf("%s", &namaChar);
        if (strcmp(namaChar, "DOMAIN_EXPANSION") != 0)
        {
            scanf("%s %d", &namaTeknik, &power);
            addLast(namaChar, namaTeknik, power, &L);
            totalPower += power;
        }
        else
        {
            flag = 1;
            scanf("%s", &sortBy);
            scanf("%s", &sort);
        }
    }

    // dataPenyihir jujutsuKaisen[100];
    // dataPenyihir *jujutsuKaisen = malloc(sizeof(dataPenyihir));

    // while (flag == 0)
    // {
    //     scanf("%s", &jujutsuKaisen[i].namaChar);
    //     if (strcmp(jujutsuKaisen[i].namaChar, "DOMAIN_EXPANSION") != 0)
    //     {
    //         scanf("%s %d", &jujutsuKaisen[i].namaTeknik, &jujutsuKaisen[i].power);
    //         addLast(jujutsuKaisen[i].namaChar, jujutsuKaisen[i].namaTeknik, jujutsuKaisen[i].power, &L);
    //         totalPower += jujutsuKaisen[i].power;
    //         i++;
    //     }
    //     else
    //     {
    //         flag = 1;
    //         scanf("%s", &sortBy);
    //         scanf("%s", &sort);
    //     }
    // }

    printElement(L, totalPower);
    return 0;
}