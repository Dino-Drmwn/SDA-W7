#ifndef KOTA_H
#define KOTA_H

#include "penduduk.h"

#define MAX_KOTA 5

typedef struct {
    char nama[50];
    Penduduk* daftarPenduduk;
    int jumlahPenduduk;
} Kota;

void initKota(Kota kota[], int size);
void tambahPendudukKeKota(Kota* kota, const char* nama);
void hapusKota(Kota kota[], int* jumlahKota, int index);
void tampilkanKota(const Kota* kota);
void tampilkanSemuaKota(Kota kota[], int jumlahKota);
void cariKota(Kota kota[], int jumlahKota, const char* cari);

#endif
