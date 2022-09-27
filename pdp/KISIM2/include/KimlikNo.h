#ifndef KIMLIKNO_H
#define KIMLIKNO_H
#include "../include/Rastgele.h"

struct KIMLIKNO {
    char kimlik_no[11];
    Random rand;
}; 
typedef struct KIMLIKNO* kimlikNo;

kimlikNo kimlikNoOlustur();
char* kimlikno_uret(kimlikNo);
int kimliknoKontrol(kimlikNo, char* kimlik);
void kimlikNoYoket(const kimlikNo);


#endif