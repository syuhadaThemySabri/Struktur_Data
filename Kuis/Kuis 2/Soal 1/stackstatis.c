#include "stackstatis.h"

int main()
{
    int input;
    nilaiMatkul data;
    nilaiMatkul data2;
    stack S;
    createEmptyStack(&S);
    scanf("%d", &input);
    for (int i = 0; i < input / 2; i++)
    {
        scanf("%s %d %d %s", &data.warna, &data.panjang, &data.lebar, &data.nama);
        scanf("%s %d %d %s", &data2.warna, &data2.panjang, &data2.lebar, &data2.nama);
        if (data.warna == data2.warna && data.panjang == data2.panjang && data.nama == data2.nama && data.lebar == data2.lebar)
        {
            printf("%s %d %d %s\n", data.warna, data.panjang, data.lebar, data.nama);
        }
        else
        {
            pushToStack(data.warna, data.panjang, data.lebar, data.nama, &S);
            pushToStack(data2.warna, data2.panjang, data2.lebar, data2.nama, &S);
        }

        // char tampung3[51];
        // int tampung = data.panjang;
        // int tampung2 = data.lebar;
        // scanf("%s %d %d %s", &data.warna, &data.panjang, &data.lebar, &tampung3);
        // if (data.nama == tampung3 || tampung == data.panjang && tampung2 == data.lebar)
        // {
        //     printf("%s %d %d %s\n", data.warna, data.panjang, data.lebar, tampung3);
        //     pushToStack(data.warna, data.panjang, data.lebar, tampung3, &S);
        //     popOutStack(&S);
        //     // popOutStack(&S);
        // }
    }
    printf("\n");
    printStack(S);
    return 0;
}
