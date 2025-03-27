#include "penduduk.h"
#include <stdlib.h>
#include <string.h>

Penduduk* buatPenduduk(const char* nama) {
    Penduduk* baru = (Penduduk*)malloc(sizeof(Penduduk));
    if (baru != NULL) {
        strcpy(baru->nama, nama);
        baru->next = NULL;
    }
    return baru;
}

void hapusSemuaPenduduk(Penduduk** head) {
    Penduduk* current = *head;
    while (current != NULL) {
        Penduduk* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
