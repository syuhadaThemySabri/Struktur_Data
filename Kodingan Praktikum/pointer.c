#include <stdio.h>

int main()
{
    float c = 3.141;
    float *ptrC = &c; // &c digunakan untuk mendapatkan alamat dari variabel c

    printf("Nilai c     : %f\n", c);
    printf("Alamat c    : %p\n", &c);

    printf("Nilai ptrC  : %p\n", ptrC);
    printf("Alamat ptrC : %p\n", &ptrC);

    return 0;
}
