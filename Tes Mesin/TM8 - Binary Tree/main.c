/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 8 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

int main()
{
    char input;
    tree T;
    //
    scanf(" %c", &input);
    makeTree(input, &T);
    scanf(" %c", &input);
    addRight(input, T.root);
    scanf(" %c", &input);
    addLeft(input, T.root);
    scanf(" %c", &input);
    addLeft(input, T.root->right);
    //
    scanf(" %c", &input);
    addRight(input, T.root->left);
    scanf(" %c", &input);
    addRight(input, T.root->right);
    scanf(" %c", &input);
    addLeft(input, T.root->left->right);
    //
    scanf(" %c", &input);
    addRight(input, T.root->right->left);
    scanf(" %c", &input);
    addRight(input, T.root->left->right);
    scanf(" %c", &input);
    addRight(input, T.root->right->right);
    //
    scanf(" %c", &input);
    addLeft(input, T.root->right->right);
    scanf(" %c", &input);
    addLeft(input, T.root->left->right->left);
    scanf(" %c", &input);
    addLeft(input, T.root->right->left->right);
    //
    scanf(" %c", &input);
    addRight(input, T.root->right->left->right);
    //
    printf("Pre Order:\n");
    printTreePreOrder(T.root);
    printf("\n");
    delLeft(T.root->left->right->left);
    printf("In Order:\n");
    printTreeInOrder(T.root);
    printf("\n");
    delRight(T.root->right->right);
    printf("Post Order:\n");
    printTreePostOrder(T.root);
    printf("\n");

    return 0;
}