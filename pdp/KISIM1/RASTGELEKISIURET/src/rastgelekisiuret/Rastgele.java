package rastgelekisiuret;
public class Rastgele {
    public Rastgele() {
		
	}
	public long RastgeleSayiUret() {
		
		long start = (System.currentTimeMillis()*11) % 10;
        try {
			Thread.sleep(11);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		return start;

	}
    
}
