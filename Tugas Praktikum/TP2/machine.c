/*
Saya Themy Sabri Syuhada dengan NIM 2203903
mengerjakan Tugas Praktikum 2 dengan jujur
dan tidak melakukan kecurangan seperti yang telah
dispesifikasikan demi keberkahan-Nya
Aamiin
*/

#include "header.h"

// Fungsi untuk mencetak list makanan
void printFoodList(struct Food *head)
{
    printf("===========================================\n");
    struct Food *current = head;
    while (current != NULL)
    {
        printf("%s - Rp%d - %f\n", current->nama, current->harga, current->rating);
        current = current->next;
    }
    printf("===========================================\n");
}

// Fungsi untuk menambahkan makanan ke list
void addFood(struct Food **head, char nama[], int rating, int harga)
{
    struct Food *newFood = (struct Food *)malloc(sizeof(struct Food));
    strcpy(newFood->nama, nama);
    newFood->rating = rating;
    newFood->harga = harga;
    newFood->next = NULL;
    newFood->prev = NULL;

    if (*head == NULL)
    {
        *head = newFood;
    }
    else
    {
        struct Food *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newFood;
        newFood->prev = current;
    }
}

// Fungsi untuk menghapus makanan dengan nama yang panjang ganjil
void removeOddLengthFood(struct Food **head)
{
    struct Food *current = *head;
    while (current != NULL)
    {
        if (strlen(current->nama) % 2 != 0)
        {
            struct Food *temp = current;
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            current = current->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

// Fungsi untuk mengurutkan list berdasarkan rating secara descending
void sortFoodList(struct Food **head)
{
    struct Food *current = *head;
    struct Food *temp = NULL;
    int swapped;

    do
    {
        swapped = 0;
        current = *head;
        while (current->next != temp)
        {
            if (current->rating < current->next->rating)
            {
                // Tukar node
                if (current->prev != NULL)
                {
                    current->prev->next = current->next;
                }
                if (current->next->next != NULL)
                {
                    current->next->next->prev = current;
                }
                struct Food *next = current->next;
                current->next = next->next;
                next->prev = current->prev;
                next->next = current;
                current->prev = next;
                *head = next;
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }
        temp = current;
    } while (swapped);
}

// Fungsi untuk mengurutkan list berdasarkan harga secara ascending
void sortFoodListByPrice(struct Food **head)
{
    struct Food *current = *head;
    struct Food *temp = NULL;
    int swapped;

    do
    {
        swapped = 0;
        current = *head;
        while (current->next != temp)
        {
            if (current->harga > current->next->harga)
            {
                // Tukar node
                if (current->prev != NULL)
                {
                    current->prev->next = current->next;
                }
                if (current->next->next != NULL)
                {
                    current->next->next->prev = current;
                }
                struct Food *next = current->next;
                current->next = next->next;
                next->prev = current->prev;
                next->next = current;
                current->prev = next;
                if (current == *head)
                {
                    *head = next;
                }
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }
        temp = current;
    } while (swapped);
}