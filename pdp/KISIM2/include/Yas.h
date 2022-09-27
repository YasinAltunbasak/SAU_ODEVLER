#ifndef YAS_H
#define YAS_H
#include "../include/Rastgele.h"

struct YAS {
    int yas;
    Random rand;
}; 
typedef struct YAS* yas;

yas YasOlustur();
int Yasuret(const yas);
void YasYoket(const yas);

#endif
