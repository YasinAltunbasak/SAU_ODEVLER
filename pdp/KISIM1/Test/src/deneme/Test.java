package deneme;
import rastgelekisiuret.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Test {
    private static final Scanner Giris = new Scanner(System.in);
    private static final RastgeleKisi _Kisi = new RastgeleKisi();
    private static int secim = 0;
    private static int UretilecekKisiSayisi;
    
    public static void main(String[] args) {
  
         while (secim != 3) {
            Secim();
            switch (secim) {

                case 1:
                   RastgeleKisiUret(UretilecekKisiSayisi);
                    break;

                case 2:
                    KontrolEt();
                    break;
                default:
                    System.out.println("Çıkış Yapıldı...");
                    break;
            }

        }
    }
    public static void Secim() {

        System.out.println("1 - Rastgele Kişi Üret\n2 - Üretilmiş Dosya Kontrol Et\n3 - Çıkış");
        System.out.print("Seçiminiz :");
        secim = Giris.nextInt();

        while (secim < 1 || secim > 3) {
            System.out.println("Lütfen Geçerli Değerler Giriniz!\n1 - Rastgele Kişi Üret\n2 - Üretilmiş Dosya Kontrol Et\n3 - Çıkış");
            System.out.print("Seçiminiz :");
            secim = Giris.nextInt();
        }
        if (secim == 1) {
            System.out.print("Üretilecek Kişi Sayısı :");
            UretilecekKisiSayisi = Giris.nextInt();
        }

    }
    public static void RastgeleKisiUret(int in) {
try{
        for (int i = 0; i < in; i++) {

            String Kayıt = _Kisi.KisiOlustur();
            File file = new File("Kisiler.txt");
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fileWriter = new FileWriter(file, true);
            BufferedWriter bWriter = new BufferedWriter(fileWriter);

            bWriter.write(Kayıt);
            bWriter.newLine();
            bWriter.close();
        }}catch (final IOException e){}
        System.out.println("Kayıt Eklendi...");

    }
     public static void KontrolEt(){
try{
        FileReader fileReader = new FileReader("Kisiler.txt");
        String line;
        
        try (BufferedReader okuma = new BufferedReader(fileReader)) {
            int GecerliTc = 0, GecersizTc = 0, GecerliImei = 0, GecersizImei = 0;
            while ((line = okuma.readLine()) != null) {

                String[] Bilgiler = line.split(" ");

                if ("GeçerliTc".equals(_Kisi.KimlikKontrol(Bilgiler[0]))) {
                    GecerliTc++;
                } else if ("GeçersizTc".equals(_Kisi.KimlikKontrol(Bilgiler[0]))) {
                    GecersizTc++;
                }

                if ("GecerliImei".equals(_Kisi.ImeiKontrol(Bilgiler[5].substring(1, Bilgiler[5].length() - 1)))) {
                    GecerliImei++;
                } else if ("GecersizImei".equals(_Kisi.ImeiKontrol(Bilgiler[5].substring(1, Bilgiler[5].length() - 1)))) {
                    GecersizImei++;
                }
            }
            System.out.println("\nT.C Kimlik Kontrol\n" + GecerliTc + " Geçerli\n" + GecersizTc + " Geçersiz");
            System.out.println("\nIMEI Kontrol\n" + GecerliImei + " Geçerli\n" + GecersizImei + " Geçersiz\n");
        }
}catch (final IOException e){}

    }

}
