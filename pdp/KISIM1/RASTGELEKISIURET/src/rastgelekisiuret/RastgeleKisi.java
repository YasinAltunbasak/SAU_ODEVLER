package rastgelekisiuret;

public class RastgeleKisi {
    Kisi YeniKisi = new Kisi();
    Yas YeniYas = new Yas();
    Telefon YeniTelefon = new Telefon();
    ImeiNo YeniImei = new ImeiNo();
    KimlikNo YeniKimlik = new KimlikNo();

    public String KisiOlustur() {
        String Gonder = YeniKimlik.KimlikNo() + " " + YeniKisi.KisiOlustur() + " " + YeniYas.YasOlustur()+ " " + YeniTelefon.TelefonNoUret() + " (" + YeniImei.ImeiNoUret() + ")";
        return Gonder;
    }

    public String KimlikKontrol(String Kimlik) {

        KimlikNo Tckontrol = new KimlikNo();
        return Tckontrol.KimlikNoKontrol(Kimlik);
    }

    public String ImeiKontrol(String Imei) {
        ImeiNo ImeiKontrol = new ImeiNo();
        return ImeiKontrol.ImeıKontrol(Imei);
    }
    
}
