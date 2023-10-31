#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Struktur untuk merepresentasikan power bank
struct PowerBank
{
    char merk[51];
    char seri[51];
    int kapasitas_awal;
    int ketahanan_tahun;
    int kapasitas_saat_ini;
    int tahun_beli;
};

// Fungsi untuk memeriksa apakah power bank memerlukan pemeriksaan
int perluPemeriksaan(struct PowerBank *pb, int tahun_pemeriksaan, int batas_penurunan)
{
    int tahun_pemakaian = tahun_pemeriksaan - pb->tahun_beli;
    int penurunan_kapasitas = pb->kapasitas_awal - pb->kapasitas_saat_ini;

    if (tahun_pemakaian > pb->ketahanan_tahun || penurunan_kapasitas > batas_penurunan)
    {
        return 1; // Memerlukan pemeriksaan
    }

    return 0; // Tidak perlu pemeriksaan
}

int main()
{
    int n;
    scanf("%d", &n);

    // Membaca data power bank dan mengelompokkannya berdasarkan merk
    struct PowerBank powerBanks[n];
    char merk_sebelumnya[51] = "";

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d %d %d", powerBanks[i].merk, powerBanks[i].seri, &powerBanks[i].kapasitas_awal, &powerBanks[i].ketahanan_tahun, &powerBanks[i].kapasitas_saat_ini, &powerBanks[i].tahun_beli);

        if (strcmp(merk_sebelumnya, powerBanks[i].merk) != 0)
        {
            if (i > 0)
            {
                // printf("\n");
            }
            // printf("%s:\n", powerBanks[i].merk);
            strcpy(merk_sebelumnya, powerBanks[i].merk);
        }

        // printf("%s %s %d %d %d %d\n", powerBanks[i].merk, powerBanks[i].seri, powerBanks[i].kapasitas_awal, powerBanks[i].ketahanan_tahun, powerBanks[i].kapasitas_saat_ini, powerBanks[i].tahun_beli);
    }

    int tahun_pemeriksaan, batas_penurunan;
    scanf("%d %d", &tahun_pemeriksaan, &batas_penurunan);

    int ada_pemeriksaan = 0;
    // printf("\nmelebihi ketahanan:\n");

    for (int i = 0; i < n; i++)
    {
        if (perluPemeriksaan(&powerBanks[i], tahun_pemeriksaan, batas_penurunan) == 1)
        {
            // printf("%s %s %d %d %d %d\n", powerBanks[i].merk, powerBanks[i].seri, powerBanks[i].kapasitas_awal, powerBanks[i].ketahanan_tahun, powerBanks[i].kapasitas_saat_ini, powerBanks[i].tahun_beli);
            ada_pemeriksaan = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (perluPemeriksaan(&powerBanks[i], tahun_pemeriksaan, batas_penurunan) == 0)
        {
            continue;
        }

        if (powerBanks[i].kapasitas_awal - powerBanks[i].kapasitas_saat_ini > batas_penurunan)
        {
            // printf("%s %s %d %d %d %d\n", powerBanks[i].merk, powerBanks[i].seri, powerBanks[i].kapasitas_awal, powerBanks[i].ketahanan_tahun, powerBanks[i].kapasitas_saat_ini, powerBanks[i].tahun_beli);
            ada_pemeriksaan = 1;
        }
    }

    if (!ada_pemeriksaan)
    {
        // printf("Tidak ada power bank yang perlu diperiksa.\n");
    }

    return 0;
}