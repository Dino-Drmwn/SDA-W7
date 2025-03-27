#include "kota.h"
#include <stdio.h>
#include <string.h>

void initKota(Kota kota[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        strcpy(kota[i].nama, "");
        kota[i].daftarPenduduk = NULL;
        kota[i].jumlahPenduduk = 0;
    }
}

void tambahPendudukKeKota(Kota* kota, const char* nama) {
    Penduduk* baru = buatPenduduk(nama);
    if (baru == NULL) {
        printf("Gagal menambahkan penduduk!\n");
        return;
    }

    if (kota->daftarPenduduk == NULL) {
        kota->daftarPenduduk = baru;
    } else {
        Penduduk* current = kota->daftarPenduduk;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = baru;
    }
    kota->jumlahPenduduk++;
}

void hapusKota(Kota kota[], int* jumlahKota, int index) {
    int i;
    if (index < 0 || index >= *jumlahKota) return;
    
    hapusSemuaPenduduk(&kota[index].daftarPenduduk);
    
    for (i = index; i < *jumlahKota - 1; i++) {
        kota[i] = kota[i + 1];
    }
    
    strcpy(kota[*jumlahKota - 1].nama, "");
    kota[*jumlahKota - 1].daftarPenduduk = NULL;
    kota[*jumlahKota - 1].jumlahPenduduk = 0;
    
    (*jumlahKota)--;
}

void tampilkanKota(const Kota* kota) {
    Penduduk* current = kota->daftarPenduduk;
    printf("Kota: %s (%d penduduk)\n", kota->nama, kota->jumlahPenduduk);
    while (current != NULL) {
        printf("- %s\n", current->nama);
        current = current->next;
    }
    printf("\n");
}

void tampilkanSemuaKota(Kota kota[], int jumlahKota) {
    int i, totalPenduduk = 0;
    printf("\n=== DAFTAR KOTA ===\n");
    for (i = 0; i < jumlahKota; i++) {
        tampilkanKota(&kota[i]);
        totalPenduduk += kota[i].jumlahPenduduk;
    }
    printf("Total Kota: %d\n", jumlahKota);
    printf("Total Penduduk: %d\n\n", totalPenduduk);
}

void cariKota(Kota kota[], int jumlahKota, const char* cari) {
    int i, ditemukan = 0;
    char kotaLower[50], cariLower[50];
    
    strcpy(cariLower, cari);
    for (i = 0; cariLower[i]; i++) {
        cariLower[i] = tolower(cariLower[i]);
    }
    
    printf("\n=== HASIL PENCARIAN ===\n");
    for (i = 0; i < jumlahKota; i++) {
        strcpy(kotaLower, kota[i].nama);
        int j;
        for (j = 0; kotaLower[j]; j++) {
            kotaLower[j] = tolower(kotaLower[j]);
        }
        
        if (strstr(kotaLower, cariLower) != NULL) {
            tampilkanKota(&kota[i]);
            ditemukan = 1;
        }
    }
    
    if (!ditemukan) {
        printf("Kota '%s' tidak ditemukan!\n\n", cari);
    }
}
