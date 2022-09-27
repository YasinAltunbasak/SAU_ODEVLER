#ifndef KISI_H
#define KISI_H
#include "../include/Rastgele.h"
#include <string.h>

struct KISI {
    char risim[50];
}; 
typedef struct KISI* kisi;

kisi kisiOlustur();
char* kisi_uret(const kisi);
void kisiYoket(const kisi);


#endif