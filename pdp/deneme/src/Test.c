#include "../include/RastgeleKisi.h"
#include "stdio.h"
#include "stdlib.h"

void Kontrol(){
  imei_ im = imeiOlustur();
  kimlikNo km = kimlikNoOlustur();
  FILE *f = fopen("Kisiler.txt","r");
  if (f){
    
  size_t pos = ftell(f);
  fseek(f, 0, SEEK_END);
  size_t length = ftell(f);
  fseek(f, pos, SEEK_SET); 
  int dosyauzunlugu = length/57+1;
  int gecerliIMEI = 0;
  int gecersizIMEI = 0;
  int gecerliKimlik = 0;
  int gecersizKimlik = 0;
  char line[70];
  int sayi = 0;
  char *liste[dosyauzunlugu];
	while (fgets(line, sizeof(line), f)) {
		if(line != NULL){
		char *pch;
		char str[50];

		strcpy(str,line);
		pch = strtok(str," ");
		int bilgi = 0;
		while (pch != NULL){
			bilgi++;
			if(bilgi == 1){
       // printf("%s\n",pch);
				if(kimliknoKontrol(km,pch) == 1){
          gecerliKimlik++;
        }
				else{
          gecersizKimlik++;
        }
			}

			else if(bilgi == 7) { 
       // printf("%s\n",pch);
   			for(int i = 0; i < 18 - 1; i++) pch[i] = pch[i + 1];
        
				pch[15] = '\0';
				if(imeikontrol(im,pch) == 1 ) gecerliIMEI++;
				else gecersizIMEI++;
			}
			else{
				pch = strtok (NULL, " ");
			}
		}
			sayi++;
	}
	 }
   sayi = 0;
   printf("T.C. Kimlik Kontrol\n");
        printf("%5d Gecerli\n", gecerliKimlik);
        printf("%5d Gecersiz\n", gecersizKimlik);
        printf("\nIMEI Kontrol\n");
        printf("%5d Gecerli\n", gecerliIMEI);
        printf("%5d Gecersiz\n", gecersizIMEI);
      }
      else{
        printf("\nDosya bulunamadi!\n");
      }
      fclose(f);
    kimlikNoYoket(km);
    imeiYoket(im);
}

int main(){

rskisi r = rskisiOlustur();
int secim;
do{

  int kisiSayisi;
  printf("1 - Rastgele Kisi Uret\n2 - Uretilmis Dosya Kontrol Et\n3 - Cikis\n");
  scanf("%d",&secim);

  while (secim < 1 || secim > 3){
    printf("Lutfen 1 ve 3 arasinda secim yapiniz. \n");
    printf("1 - Rastgele Kisi Uret\n2 - Uretilmis Dosya Kontrol Et\n3 - Cikis\n");
    scanf("%d",&secim);
  }

  if(secim == 1){
    printf("Lutfen uretilecek kisi sayisini giriniz: ");
    scanf("%d",&kisiSayisi);
    printf("%s",rskisi_uret(r,kisiSayisi));
  }
  if(secim==2){
    Kontrol();
  }

}while(secim != 3);
rskisiYoket(r);

return 0;
}
