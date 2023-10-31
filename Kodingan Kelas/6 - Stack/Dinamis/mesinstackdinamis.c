#include "stackdinamis.h"

void createEmptyStack(stack *S)
{
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int result = 0;
    if (S.top == NULL)
    {
        result = 1;
    }
    return result;
}

int countElement(stack S)
{
    int result = 0;
    if (S.top != NULL)
    {
        /* stack tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = S.top;
        while (bantu != NULL)
        {
            /* proses */
            result++;
            /* iterasi */
            bantu = bantu->next;
        }
    }
    return result;
}

void pushToStack(char nim[], char nama[], float nilai, stack *S)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));
    strcpy(new->kontainer.nim, nim);
    strcpy(new->kontainer.nama, nama);
    new->kontainer.nilai = nilai;
    if ((*S).top == NULL)
    {
        // jika stack kosong
        new->next = NULL;
    }
    else
    {
        // jika stack tidak kosong
        new->next = (*S).top;
    }
    (*S).top = new;
    new = NULL;
}

void popOutStack(stack *S)
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *remove = (*S).top;
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        remove->next = NULL;
        free(remove);
    }
    else
    {
        printf("Stack Kosong");
    }
}

void printStack(stack S)
{

    if (S.top != NULL)
    {
        printf("------isi stack------\n");

        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", bantu->kontainer.nim);
            printf("nama : %s\n", bantu->kontainer.nama);
            printf("nilai : %f\n", bantu->kontainer.nilai);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
        printf("---------------------\n");
    }
    else
    {
        /* proses jika stack kosong */
        printf("Stack Kosong\n");
    }
}