#include <stdio.h>

int main()
{
    int a = 22;

    printf("Nilai variabel a    : %d\n", a);
    printf("Alamat variabel a   : %p\n", &a); // &a digunakan untuk mendapatkan alamat variabel a
    printf("Ukuran variabel a   : %d byte\n", sizeof(a));

    return 0;
}
