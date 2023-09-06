#include <stdio.h>

typedef struct
{
    char nama[50];
    int nim;
    float ipk;
} mahasiswa;

void swap_reference(mahasiswa *value1, mahasiswa *value2)
{
    mahasiswa temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int main()
{
    mahasiswa mhs1 = {"themy", 2203903, 4.00};
    mahasiswa mhs2 = {"sabri", 2278654, 3.82};

    printf("Sebelum ditukar\n");
    printf("Data mahasiswa 1     : %s %d %.2f\n", mhs1.nama, mhs1.nim, mhs1.ipk);
    printf("Alamat data mhs1     : %p\n", &mhs1);
    printf("Data mahasiswa 1     : %s %d %.2f\n", mhs2.nama, mhs2.nim, mhs2.ipk);
    printf("Alamat data mhs1     : %p\n\n", &mhs2);

    swap_reference(&mhs1, &mhs2);

    printf("Setelah ditukar by reference\n");
    printf("Data mahasiswa 1     : %s %d %.2f\n", mhs1.nama, mhs1.nim, mhs1.ipk);
    printf("Alamat data mhs1     : %p\n", &mhs1);
    printf("Data mahasiswa 1     : %s %d %.2f\n", mhs2.nama, mhs2.nim, mhs2.ipk);
    printf("Alamat data mhs1     : %p\n", &mhs2);

    return 0;
}