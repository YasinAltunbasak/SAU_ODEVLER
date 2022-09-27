#include "../include/ImeiNo.h"


imei_ imeiOlustur(){
     imei_ imeino = (imei_)malloc(sizeof(struct IMEI));
     imeino->rand = RandomOlustur();
     return imeino;
}

char* imeino_uret(imei_ imei){
    int number[14];
    int temp = 0;
    for(int i = 0; i<14;i++){

        int num = RandomUret(imei->rand);
        imei->imei_no[i] = num + '0';
        if(i%2==0){
            temp += num;
        }
        else{
            temp += num*2;
        }

    }
    temp = (10 - (temp%10))%10;
    imei->imei_no[14] = temp+'0';
    return imei->imei_no;
}
int imeikontrol(imei_ imei_, char* imei){
    int control = 0;
    for(int i=0; i<14; i++){
        if(i % 2 ==0){
            control += imei[i]-'0';
        }
        else{
            control += (imei[i]-'0')*2;
        }
    }
    control = (10-(control%10))%10;
    int temp = imei[14]-'0';
    if(temp == control)
        return 1;
    else 
        return -1;

}

void imeiYoket(imei_ imei){
	if(imei == NULL) return;
	free(imei);
	imei = NULL;
} 