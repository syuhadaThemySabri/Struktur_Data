/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan Tugas Praktikum 3 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

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

void pushToStack(hargaBuku data, stack *S)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));
    // strcpy(new->kontainer.buku, buku);
    new->kontainer = data;
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
    printf("Buku Fiksi untuk Rene:\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    if (S.top != NULL)
    {
        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {
            printf("%d. %s [%d]\n", i, bantu->kontainer.buku, bantu->kontainer.kode);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("Rene mangambek.. Jakob pun menangis T-T.\n");
    }
}

void printStack2(stack S)
{
    printf("Buku Non-Fiksi untuk Alain:\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    if (S.top != NULL)
    {

        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {
            printf("%d. %s [%d]\n", i, bantu->kontainer.buku, bantu->kontainer.kode);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("Alain pergi.. Huft, Ann harus mencarinya.\n");
    }
}