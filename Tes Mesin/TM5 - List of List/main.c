/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan tes mesin 5 dengan jujur
demi keberkahan-Nya.
Aamiin
*/
#include "header.h"

int main()
{
    list L;
    createList(&L);
    genreBuku simpanGenre;
    judulBuku simpanJudul;
    int input;
    scanf("%d", &input);
    for (int i = 0; i < input; i++)
    {
        scanf("%s %d", &simpanGenre.genre, &simpanGenre.kode);
        addLastB(simpanGenre.genre, simpanGenre.kode, &L);

        scanf("%s", &simpanJudul.judul);
        addFirstK(simpanJudul.judul, barisLast(L));

        scanf("%s", &simpanJudul.judul);
        addLastK(simpanJudul.judul, barisLast(L));

        scanf("%s", &simpanJudul.judul);
        addAfterK(barisLast(L)->col->next_kol, simpanJudul.judul);

        scanf("%s", &simpanJudul.judul);
        addFirstK(simpanJudul.judul, barisLast(L));
    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);
    return 0;
}