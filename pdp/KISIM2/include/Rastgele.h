#ifndef RASTGELE_H
#define RASTGELE_H
#include "stdio.h"
#include "stdlib.h"
#include <time.h>

struct RANDOM {
    int random;
}; 

typedef struct RANDOM* Random;
Random RandomOlustur();
int RandomUret(const Random);
void RandomYoket(const Random);

#endif