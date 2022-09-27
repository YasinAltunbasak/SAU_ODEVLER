package rastgelekisiuret;

public class Yas {
    public long YasOlustur(){
        Rastgele rs = new Rastgele();
        long yas = rs.RastgeleSayiUret();
        long temp = rs.RastgeleSayiUret();
        if(temp <= 3){
        yas = yas*yas +10;
        }
        else if(temp <= 6){
        yas = yas*2+4;
        }
        return yas;
       
    }
    
}
