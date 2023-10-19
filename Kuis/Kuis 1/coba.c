#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node untuk list ganda
struct Node
{
    int order;
    char data[50];
    struct Node *next;
    struct Node *prev;
};

// Fungsi untuk membuat node baru
struct Node *createNode(int order, const char *data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->order = order;
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node ke akhir list ganda
void appendNode(struct Node **head, struct Node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Fungsi untuk menukar gen antara dua kromosom
void exchangeGen(struct Node **chromosome1, struct Node **chromosome2, int order1, int order2)
{
    struct Node *node1 = *chromosome1;
    struct Node *node2 = *chromosome2;

    while (node1 != NULL && node1->order != order1)
    {
        node1 = node1->next;
    }

    while (node2 != NULL && node2->order != order2)
    {
        node2 = node2->prev;
    }

    if (node1 != NULL && node2 != NULL)
    {
        char temp[50];
        strcpy(temp, node1->data);
        strcpy(node1->data, node2->data);
        strcpy(node2->data, temp);
    }
}

// Fungsi untuk menampilkan kromosom dengan aturan yang sesuai
void displayChromosome(struct Node *head, int reverse)
{
    struct Node *current = reverse ? head : NULL;

    while (current != NULL)
    {
        printf("%s ", current->data);
        current = reverse ? current->prev : current->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node *chromosome1 = NULL;
    struct Node *chromosome2 = NULL;

    for (int i = 0; i < n; i++)
    {
        char data[50];
        scanf("%s", data);

        struct Node *newNode1 = createNode(i + 1, data);
        struct Node *newNode2 = createNode(n - i, data);

        appendNode(&chromosome1, newNode1);
        appendNode(&chromosome2, newNode2);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int order1, order2;
        scanf("%d %d", &order1, &order2);
        exchangeGen(&chromosome1, &chromosome2, order1, order2);
    }

    printf("kromosom 1: ");
    displayChromosome(chromosome1, 1);

    printf("kromosom 2: ");
    displayChromosome(chromosome2, 0);

    // Membebaskan memori
    while (chromosome1 != NULL)
    {
        struct Node *temp = chromosome1;
        chromosome1 = chromosome1->next;
        free(temp);
    }

    while (chromosome2 != NULL)
    {
        struct Node *temp = chromosome2;
        chromosome2 = chromosome2->next;
        free(temp);
    }

    return 0;
}
