#include <stdio.h>

void swap_value(int value1, int value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void swap_reference(int *value1, int *value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int main()
{
    int a = 16;
    int b = 35;

    printf("Sebelum ditukar\n");
    printf("Nilai a     : %d\n", a);
    printf("Alamat a    : %p\n", &a);
    printf("Nilai b     : %d\n", b);
    printf("Alamat b    : %p\n\n", &b);

    swap_value(a, b);

    printf("Setelah ditukar by value\n");
    printf("Nilai a     : %d\n", a);
    printf("Alamat a    : %p\n", &a);
    printf("Nilai b     : %d\n", b);
    printf("Alamat b    : %p\n\n", &b);

    swap_reference(&a, &b);

    printf("Setelah ditukar by reference\n");
    printf("Nilai a     : %d\n", a);
    printf("Alamat a    : %p\n", &a);
    printf("Nilai b     : %d\n", b);
    printf("Alamat b    : %p\n", &b);

    return 0;
}
