#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX = 50;

enum RENKLER
{
LIGHTBLUE = 9,
LIGHTGREEN = 10,
LIGHTCYAN = 11,
LIGHTRED = 12,
LIGHTMAGENTA = 13,
YELLOW = 14,

};


    
char	DUZCIZGI = 205;	
char	SOLUSTKOSE = 201;	
char	SAGUSTKOSE = 187;	
char	DIKEYCIZGI = 186;	
char	ASAGIAYRAC = 203;	
char	SOLALTKOSE = 200;	
char	SAGALTKOSE = 188;	
char	YUKARIAYRAC = 202;	

class Karakter{
    private:
    char harfler[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    public:
        char harf;
        
        int renk;
        
        int rastgeleHarf(char harf){
            
            char harf = harfler[rand() % 26];
        }

};

class Katar{ 
    public:

    Karakter karakterler[MAX];
    char k;
    int KarakterSayisi = 0;
        Katar(){

        }
    void ElemanEkle(char k){
        
        karakterler[KarakterSayisi].rastgeleHarf(k);
        
    }
    void ElemanCikar(){

        KarakterSayisi--;
    }
    void Yazdir(){
        cout<<karakterler;
        }//Kutucuk
 
};
void Kutucuk()
{
    Karakter k1;
       cout << SOLUSTKOSE << DUZCIZGI  << SAGUSTKOSE << endl;
       cout << DIKEYCIZGI;  cout << DIKEYCIZGI << endl; 
       cout << SOLALTKOSE << DUZCIZGI << SAGALTKOSE << endl;
};

int main()
{   
    int i= 0;
    Katar dizi1[MAX];
    char k1;
    
    char islem;
    do {
    cout <<"Islem Seciniz" << endl;
    cout <<"1- Karakter Ekle" << endl;
    cout <<"2- Karakter Cikar" << endl;
    cout <<"3- Programi Sonlandir" << endl;
    
    cin >> islem;
    
    switch (islem)
    {
    case '1':
      
    //50 eleman olunca bu casein dönmesine izin verme
        //ekleme islemi

        dizi1[i].ElemanEkle(k1);
        dizi1[MAX].Yazdir();
        
        i++;
        break;

    case '2':
    //dizinin son indisli elemanini sil.
        //cikarma islemi
        
        break;

    case '3':
    cout<<"Programi sonlandirmayi sectiniz" <<endl;
        break;

    default:
        cout<<"Hatali secim tekrar deneyiniz." <<endl;
        break;
    }


    } while (islem != '3');
    
    cout<<"Program Sonlandirildi" <<endl;
    
    return 0;
}