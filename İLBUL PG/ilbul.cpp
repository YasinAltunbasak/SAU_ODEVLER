/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**	
**				ÖDEV NUMARASI…...:	Ödev 1
**				ÖĞRENCİ ADI...............:Yasin Altunbaşak
**				ÖĞRENCİ NUMARASI.:g191210386
**				DERS GRUBU…………: 1B
****************************************************************************/
#include <iostream> 
#include <cstring>					// strlen() fonksiyonu için
#include <locale.h>					// Diller ve karakter setleri kütüphanesi
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{	
	srand( time(NULL) );
	
	setlocale(LC_ALL, "Turkish");// Sonuç ekranında Türkçe karakterleri kullanabilmek için

	
	const string iller[81] = {"adana", "adiyaman", "afyon", "agri", "amasya", "ankara", "antalya", "artvin", "aydin", "balikesir", "bilecik", "bingol", "bitlis", "bolu", "burdur", "bursa", "canakkale", "cankiri", "corum", "denizli", "diyarbakir", "edirne", "elazig", "erzincan", "erzurum", "eskisehir", "gaziantep", "giresun", "gumushane", "hakkari", "hatay", "isparta", "mersin", "istanbul", "izmir", "kars", "kastamonu", "kayseri", "kirklareli", "kirsehir", "kocaeli", "konya", "kutahya", "malatya", "manisa", "kahramanmaras", "mardin", "mugla", "mus", "nevsehir", "nigde", "ordu", "rize", "sakarya", "samsun", "siirt", "sinop", "sivas", "tekirdag", "tokat", "trabzon", "tunceli", "sanliurfa", "usak", "van", "yozgat", "zonguldak", "aksaray", "bayburt", "karaman", "kirikkale", "batman", "sirnak", "bartin", "ardahan", "igdir", "yalova", "karabuk", "kilis", "osmaniye", "duzce"};

	
	//van için
	//1. il
	
	int randomIndex_il1 = rand() % 81 + 1;//rastgele index seçer
	//cout << iller[randomIndex]<<endl;//rastgele indexin içindeki veriyi yazdırır.
	char rastgele_il1[81];
	char rastgele_il2[81];
	char rastgele_il3[81];

	
	
	
	strcpy(rastgele_il1, iller[randomIndex_il1].c_str());
	int i = 0;
	while(rastgele_il1[i]== ' '){
        cout<<" "<< rastgele_il1[i];
		i++;
		

    }
	randomIndex_il1 = '\0';
	cout<<endl;
	
	//2. il
	int randomIndex_il2 = rand() % 81 + 1;//rastgele index seçer
	strcpy(rastgele_il2, iller[randomIndex_il2].c_str());
	for (int i = 0; i < 15; i++){
        if(rastgele_il2[i] == ' ')
		{
			break;
		}
		else
        cout<<" "<< rastgele_il2[i];
    }
	rastgele_il2[i] = '\0';
	cout<<endl;
	
	

	int randomIndex_il3 = rand() % 81 + 1;//rastgele index seçer
	strcpy(rastgele_il3, iller[randomIndex_il3].c_str());
	for (int i = 0; i < 15; i++){
        if(rastgele_il3[i] == ' ')
		{
			break;
		}
		else
        cout<<" "<< rastgele_il3[i];
    }
	cout<<endl;
	


	
	return 0;
}
