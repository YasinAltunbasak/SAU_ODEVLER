#include "../include/Kisi.h"
#include "../include/Rastgele.h"

kisi kisiOlustur(){
     srand(time(NULL)); 
     kisi k = (kisi)malloc(sizeof(struct KISI));
     return k;
}
char* kisi_uret(kisi k){
    char line[50];
    int i = 0;
    int sayi = rand()%3000;
    FILE *file = fopen("random_isimler.txt", "r");
    if(file){
    while (fgets(line, sizeof(line), file)) { 
        if(line != NULL){
            if(i==sayi){
            line[strlen(line)-1] = '\0';
            strcpy(k->risim,line);
            return k->risim;
            }
        i++;
        }
        }  
    }
fclose(file);
}
void kisiYoket(kisi k){
    if(k == NULL) return;
	free(k);
	k = NULL;
}