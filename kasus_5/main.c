#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "kota.h"

void tampilkanMenu() {
    printf("\n=== MENU UTAMA ===\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Penduduk\n");
    printf("3. Hapus Kota\n");
    printf("4. Tampilkan Semua Data\n");
    printf("5. Cari Kota\n");
    printf("6. Keluar\n");
    printf("Pilihan: ");
}

int main() {
    Kota kota[MAX_KOTA];
    int jumlahKota = 0;
    int pilihan;
    char input[50];
    int i; // Deklarasi di luar untuk kompatibilitas
    
    initKota(kota, MAX_KOTA);
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        while(getchar() != '\n'); // Membersihkan buffer
        
        switch (pilihan) {
            case 1:
                if (jumlahKota >= MAX_KOTA) {
                    printf("Maaf, sudah mencapai batas maksimal kota!\n");
                    break;
                }
                
                printf("Masukkan nama kota: ");
                fgets(input, 50, stdin);
                input[strcspn(input, "\n")] = '\0';
                
                strcpy(kota[jumlahKota].nama, input);
                jumlahKota++;
                printf("Kota berhasil ditambahkan!\n");
                break;
                
            case 2:
                if (jumlahKota == 0) {
                    printf("Belum ada kota yang terdaftar!\n");
                    break;
                }
                
                printf("Daftar Kota:\n");
                for (i = 0; i < jumlahKota; i++) {
                    printf("%d. %s\n", i+1, kota[i].nama);
                }
                
                int pilihKota;
                printf("Pilih kota (1-%d): ", jumlahKota);
                scanf("%d", &pilihKota);
                while(getchar() != '\n');
                
                if (pilihKota < 1 || pilihKota > jumlahKota) {
                    printf("Pilihan tidak valid!\n");
                    break;
                }
                
                printf("Masukkan nama penduduk: ");
                fgets(input, 50, stdin);
                input[strcspn(input, "\n")] = '\0';
                
                tambahPendudukKeKota(&kota[pilihKota-1], input);
                printf("Penduduk berhasil ditambahkan!\n");
                break;
                
            case 3:
                if (jumlahKota == 0) {
                    printf("Belum ada kota yang terdaftar!\n");
                    break;
                }
                
                printf("Daftar Kota:\n");
                for (i = 0; i < jumlahKota; i++) {
                    printf("%d. %s (%d penduduk)\n", i+1, kota[i].nama, kota[i].jumlahPenduduk);
                }
                
                printf("Pilih kota yang akan dihapus (1-%d): ", jumlahKota);
                scanf("%d", &pilihKota);
                while(getchar() != '\n');
                
                if (pilihKota < 1 || pilihKota > jumlahKota) {
                    printf("Pilihan tidak valid!\n");
                    break;
                }
                
                hapusKota(kota, &jumlahKota, pilihKota-1);
                printf("Kota beserta semua penduduknya telah dihapus!\n");
                break;
                
            case 4:
                tampilkanSemuaKota(kota, jumlahKota);
                break;
                
            case 5:
                if (jumlahKota == 0) {
                    printf("Belum ada kota yang terdaftar!\n");
                    break;
                }
                
                printf("Masukkan nama kota yang dicari: ");
                fgets(input, 50, stdin);
                input[strcspn(input, "\n")] = '\0';
                
                cariKota(kota, jumlahKota, input);
                break;
                
            case 6:
                printf("Program selesai.\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);
    
    // Bersihkan memori
    for (i = 0; i < jumlahKota; i++) {
        hapusSemuaPenduduk(&kota[i].daftarPenduduk);
    }
    
    return 0;
}
