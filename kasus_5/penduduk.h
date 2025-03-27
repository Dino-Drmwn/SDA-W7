#ifndef PENDUDUK_H
#define PENDUDUK_H

typedef struct Penduduk {
    char nama[50];
    struct Penduduk* next;
} Penduduk;

Penduduk* buatPenduduk(const char* nama);
void hapusSemuaPenduduk(Penduduk** head);

#endif
