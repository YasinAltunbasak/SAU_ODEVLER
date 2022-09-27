#ifndef IMEINO_H
#define IMEINO_H
#include "../include/Rastgele.h"

struct IMEI {
    char imei_no[15];
    Random rand;
}; 
typedef struct IMEI* imei_;

imei_ imeiOlustur();
char* imeino_uret(const imei_);
int imeikontrol(const imei_, char* imei);
void imeiYoket(const imei_);


#endif