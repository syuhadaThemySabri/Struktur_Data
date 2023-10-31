/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 6 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
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

void pushToStack(char buku[], int harga, stack *S)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));
    strcpy(new->kontainer.buku, buku);
    new->kontainer.harga = harga;
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

void popStackAndReturn(stack *S, stack *T)
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
        if ((*T).top == NULL)
        {
            // jika stack kosong
            remove->next = NULL;
        }
        else
        {
            // jika stack tidak kosong
            remove->next = (*T).top;
        }
        (*T).top = remove;
    }
}

void printStack(stack S)
{

    printf("Buku di S1:\n");
    if (S.top != NULL)
    {

        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {
            printf("%d. %s Rp.%d\n", i, bantu->kontainer.buku, bantu->kontainer.harga);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Kosong\n");
    }
}

void printStack2(stack T)
{

    printf("Buku di S2:\n");
    if (T.top != NULL)
    {

        elemen *bantu = T.top;

        int i = 1;

        while (bantu != NULL)
        {
            printf("%d. %s Rp.%d\n", i, bantu->kontainer.buku, bantu->kontainer.harga);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Kosong\n");
    }
}