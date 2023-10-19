#include "header.h"

int main()
{
    int n;
    scanf("%d", &n);

    struct Node *chromosome1 = NULL;
    struct Node *chromosome2 = NULL;

    for (int i = 0; i < n * 2; i++)
    {
        char data[50];
        scanf("%s", &data);

        struct Node *newNode1 = createNode(i + 1, data);
        struct Node *newNode2 = createNode(n - i, data);

        if (chromosome1 == NULL)
        {
            chromosome1 = newNode1;
            chromosome2 = newNode2;
        }
        else
        {
            newNode1->next = chromosome1;
            chromosome1->prev = newNode1;
            chromosome1 = newNode1;

            newNode2->prev = chromosome2;
            chromosome2->next = newNode2;
            chromosome2 = newNode2;
        }
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int order1, order2;
        scanf("%d %d", &order1, &order2);
        exchangeGen(chromosome1, chromosome2, order1, order2);
    }

    printf("kromosom 1: ");
    displayChromosome(chromosome1, 1);
    printf("\nkromosom 2: ");
    displayChromosome(chromosome2, 0);
    printf("\n");

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
