#include "header.h"

int main()
{
    int n;           // number of elements
    scanf("%d", &n); // input

    list L;
    createList(&L);

    for (int i = 0; i < n; i++)
    {
        float inputValue;
        scanf("%f", &inputValue);
        addFirst(inputValue, &L);
    }

    printElement(L);

    return 0;
}