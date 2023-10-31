#include "stackdinamis.h"

int main()
{
    stack S;
    createEmpty(&S);
    printStack(S);
    printf("=================\n");
    pushToStack("13507701", "Nana", 64.75, &S);
    pushToStack("13507702", "Rudi", 75.11, &S);
    pushToStack("13507703", "Dea", 84.63, &S);
    printStack(S);
    printf("=================\n");
    popOutStack(&S);
    popOutStack(&S);
    printStack(S);
    printf("=================\n");
    return 0;
}
