/*
Bismillah
Saya Themy Sabri Syuhada dengan NIM 2203903
berjanji mengerjakan UTS dengan jujur
demi keberkahan-Nya.
Aamiin
*/
// declare library
#include "header.h"

int main()
{
    // inisialisasi list utama dan list checking (pemeriksaan)
    list L, checking;

    // bikin list utama dan list pemeriksaan
    createList(&L);
    createList(&checking);

    // deklarasi struct
    merekPB merek;
    detailPB detail;

    // variabel untuk meminta jumlah input user, tahun sekarang, dan batas penurunan kapasitas
    int input, tahun, batasTurun;
    // minta input
    scanf("%d", &input);

    // looping sebanyak masukan user
    for (int i = 0; i < input; i++)
    {
        scanf("%s", &merek.merekPowerBank);
        addLastB(merek.merekPowerBank, &L);
        scanf("%s %d %d %d %d", &detail.seriPowerBank, &detail.kapasitasAwal, &detail.ketahanan, &detail.kapasitasAkhir, &detail.tahunBeli);
        addLastK(detail.seriPowerBank, detail.kapasitasAwal, detail.ketahanan, detail.kapasitasAkhir, detail.tahunBeli, barisLast(L));
    }
    // input tahun sekarang dan batas penurunan
    scanf("%d %d", &tahun, &batasTurun);

    if (detail.ketahanan + detail.tahunBeli < tahun)
    {
    }
    else if (detail.kapasitasAkhir < batasTurun)
    {
    }
    else if (detail.ketahanan + detail.tahunBeli < tahun && detail.kapasitasAkhir < batasTurun)
    {
    }

    printf("orion:\n");
    // printElement(L);
    printf("aiko:\n");
    printf("nuro:\n");
    printf("melebihi ketahanan:\n");
    printf("melebihi batas penurunan kapasitas:\n");
    printf("keduanya:\n");

    // delAfterK(L.first->next->col->next_kol);
    // delFirstB(&L);
    // delFirstK(L.first);
    // printElement(L);
    // delAllB(&L);
    // printElement(L);
    return 0;
}