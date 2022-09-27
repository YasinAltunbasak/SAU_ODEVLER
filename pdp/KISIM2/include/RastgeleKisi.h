#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include <stdio.h>
#include "../include/Telefon.h"
#include "../include/ImeiNo.h"
#include "../include/Yas.h"
#include "../include/KimlikNo.h"
#include "../include/Rastgele.h"
#include "../include/Kisi.h"


struct RASTGELEKISI {
    char rskisi[100];    
    kimlikNo km;
    imei_ im;
    telefon tf;
    yas ys;
    kisi kisi_;
}; 
typedef struct RASTGELEKISI* rskisi;

rskisi rskisiOlustur();
char* rskisi_uret(const rskisi, int sayi);
void rskisiYoket(const rskisi);


#endif