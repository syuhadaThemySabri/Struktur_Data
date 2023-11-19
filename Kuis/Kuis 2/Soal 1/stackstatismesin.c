#include "stackstatis.h"

void createEmptyStack(stack *S)
{
    (*S).top = -1;
}

int isEmpty(stack S)
{
    int result = 0;
    if (S.top == -1)
    {
        result = 1;
    }
    return result;
}

int isFull(stack S)
{
    int result = 0;
    if (S.top == 9)
    {
        result = 1;
    }
    return result;
}

void pushToStack(char warna[], int panjang, int lebar, char nama[], stack *S)
{
    if (isEmpty(*S) == 1)
    {
        (*S).top = 0;
        strcpy((*S).data[(*S).top].warna, warna);
        (*S).data[(*S).top].panjang = panjang;
        (*S).data[(*S).top].lebar = lebar;
        strcpy((*S).data[(*S).top].nama, nama);
    }
    else
    {
        (*S).top = (*S).top + 1;
        strcpy((*S).data[(*S).top].warna, warna);
        (*S).data[(*S).top].panjang = panjang;
        (*S).data[(*S).top].lebar = lebar;
        strcpy((*S).data[(*S).top].nama, nama);
    }
}

void popOutStack(stack *S)
{
    if ((*S).top == 0)
    {
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S)
{
    if (S.top != -1)
    {
        printf("isi stack:\n");
        int i;
        for (i = S.top; i >= 0; i--)
        {
            printf("%s ", S.data[i].warna);
            printf("%d ", S.data[i].panjang);
            printf("%d ", S.data[i].lebar);
            printf("%s\n", S.data[i].nama);
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("Stack Kosong\n");
    }
}