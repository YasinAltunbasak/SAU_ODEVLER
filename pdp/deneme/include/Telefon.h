#ifndef TELEFON_H
#define TELEFON_H
#include "../include/Rastgele.h"
#include <string.h>

struct TELEFON {
    Random rand;
    char telefon[11];
}; 
typedef struct TELEFON* telefon;

telefon telefonOlustur();
char* telefonNo_uret(const telefon);
void telefonYoket(const telefon);
#endif