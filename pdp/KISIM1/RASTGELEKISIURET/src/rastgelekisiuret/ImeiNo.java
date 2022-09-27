package rastgelekisiuret;

public class ImeiNo {
    public ImeiNo() {}
	Rastgele rs = new Rastgele();
	String imei_no = "";
        int kontrol_deger = 0;
	char kontrol =' ';
	
	public String ImeiNoUret() {
		for(int i=0; i<14; i++) {
			long rs_sayi = rs.RastgeleSayiUret();
			imei_no += String.valueOf(rs_sayi);
		}
                for(int i=0; i<imei_no.length(); i++) {
			kontrol = imei_no.charAt(i);
			if(i%2 ==0) {
				kontrol_deger += Character.getNumericValue(kontrol)*1;
			}
			else {
				kontrol_deger += Character.getNumericValue(kontrol)*2;
			}
		}
		kontrol_deger = (10 - (kontrol_deger%10))%10;
                imei_no += String.valueOf(kontrol_deger);
        String im = imei_no;
        imei_no = "";
		return im;
	}
	public String ImeıKontrol(String imei_no){
		int kontrol_deger = 0;
		char kontrol =' ';
		for(int i=0; i<14; i++) {
			kontrol = imei_no.charAt(i);
			if(i%2 ==0) {
				kontrol_deger += Character.getNumericValue(kontrol)*1;
			}
			else {
				kontrol_deger += Character.getNumericValue(kontrol)*2;
			}
		}
		kontrol_deger = (10 - (kontrol_deger%10))%10;
		int on_bes = Character.getNumericValue(imei_no.charAt(14));
		if(kontrol_deger==on_bes) {
			return "GecerliImei";
		}
		else {
			return "GecersizImei";
		}
	}
}
