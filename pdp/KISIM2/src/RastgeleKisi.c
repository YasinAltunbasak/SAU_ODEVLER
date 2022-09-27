#include "../include/RastgeleKisi.h"

rskisi rskisiOlustur(){
   rskisi rs_kisi = (rskisi)malloc(sizeof(struct RASTGELEKISI));
   rs_kisi->im = imeiOlustur();
   rs_kisi->km = kimlikNoOlustur();
   rs_kisi->tf = telefonOlustur();
   rs_kisi->ys = YasOlustur(); 
   rs_kisi->kisi_ = kisiOlustur();
   return rs_kisi;

}
char* rskisi_uret(rskisi rsk, int kisiSayisi){

   FILE *fp = fopen("Kisiler.txt","w");

   for(int i = 0; i<kisiSayisi; i++){
      char* imei = imeino_uret(rsk->im);
      char* kimlik = kimlikno_uret(rsk->km);
      char* isim = kisi_uret(rsk->kisi_);
      int yas = Yasuret(rsk->ys);
      char* telefon = telefonNo_uret(rsk->tf);
	   fprintf(fp,"%s %s %d %s (%s)\n",kimlik,isim,yas,telefon,imei);
   }

	fclose(fp);
   return "";
}
void rskisiYoket(rskisi r){
   if(r == NULL) return;
	free(r);
	r = NULL;
}

