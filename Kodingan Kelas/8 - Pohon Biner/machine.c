#include "header.h"

void makeTree(char c, tree *T)
{
    simpul *baru;                            // bikin simpul baru
    baru = (simpul *)malloc(sizeof(simpul)); // alokasi simpul baru
    baru->kontainer = c;                     // isi simpul dnegan char c
    baru->right = NULL;                      // null-kan anak kanan
    baru->left = NULL;                       // null-kan anak kiri
    (*T).root = baru;                        // jadikan si baru itu jadi root dari pohon T
    baru = NULL;                             // barunya jadiin null
}

void addLeft(char c, simpul *root)
{
    if (root->left == NULL) // jika sub pohon kiri kosong
    {
        simpul *baru;                            // bikin simpul baru
        baru = (simpul *)malloc(sizeof(simpul)); // alokasi simpul
        baru->kontainer = c;                     // isi si simpul tersebut dengan char c
        baru->right = NULL;                      // null-kan anak kanan
        baru->left = NULL;                       // null kan anak kiri
        root->left = baru;                       // jadikan si simpul tsb. sebagai anak kiri dari root (parents)
    }
    else
    {
        printf("sub pohon kiri telah terisi \n"); // kasih error message kalo emang udah ada isinya
    }
}

void addRight(char c, simpul *root)
{
    if (root->right == NULL) // jika sub pohon kanan kosong
    {
        /*jika sub pohon kanan kosong*/
        simpul *baru;                            // bikin simpul baru
        baru = (simpul *)malloc(sizeof(simpul)); // alokasi simpul
        baru->kontainer = c;                     // isi si simpul tersebut dengan char c
        baru->right = NULL;                      // null-kan anak kanan
        baru->left = NULL;                       // null kan anak kiri
        root->right = baru;                      // jadikan si simpul tsb. sebagai anak kiri dari root (parents)
    }
    else
    {
        printf("sub pohon kanan telah terisi \n"); // kasih error message kalo emang udah ada isinya
    }
}

void delAll(simpul *root)
{
    if (root != NULL) // cek apakah root-nya kosong apa nggak
    {
        delAll(root->left);  // kalo ga kosong, bakal ngehapus mulai dari anak sebelah kiri
        delAll(root->right); // lanjut ke anak sebelah kanan dihapus
        free(root);          // hapus alokasi memori si root
        // prosesnya rekursif dan terus-terusan mulai dari daun sampe akar
    }
}

void delLeft(simpul *root)
{
    if (root != NULL) // cek apakah root-nya kosong apa nggak
    {
        if (root->left != NULL) // jika anak kiri dari root ga kosong
        {
            delAll(root->left); // hapus anak sebelah kiri
            root->left = NULL;  // null kan simpul anak kiri
        }
    }
}

void delRight(simpul *root)
{
    if (root != NULL) // cek apakah root-nya kosong apa nggak
    {
        if (root->right != NULL) // jika anak kanan dari root ga kosong
        {
            delAll(root->right); // hapus anak sebelah kanan
            root->right = NULL;  // null kan simpul anak kanan
        }
    }
}

void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        printf(" %c ", root->kontainer);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(simpul *root)
{

    if (root != NULL)
    {
        printTreeInOrder(root->left);
        printf(" %c ", root->kontainer);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root)
{

    if (root != NULL)
    {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf(" %c ", root->kontainer);
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        (*root2)->left = NULL;
        (*root2)->right = NULL;
        if (root1->left != NULL)
        {
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL)
        {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEqual(simpul *root1, simpul *root2)
{

    int hasil = 1;

    if ((root1 != NULL) && (root2 != NULL))
    {
        /* jika simpul pohon 1 dan pohon 2 sama sama
        tidak NULL */
        if (root1->kontainer != root2->kontainer)
        {
            /* jika isi kontainer simpul pohon 1 dan pohon
            2 tidak sama */
            hasil = 0;
        }
        else
        {
            /* jika isi kontainer simpul pohon 1 dan simpul
            pohon 2 sama, maka telusuri simpul selanjutnya */
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL))
        {
            /* jika salah satu simpul ada yang NULL */
            hasil = 0;
        }
    }
    return hasil;
}
