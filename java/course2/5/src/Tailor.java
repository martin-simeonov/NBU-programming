
public class Tailor extends Thread {

	private static final int CLOTH_WORK_TIME = 10;
	
	private String name;
	private Workshop workshop;
	private int clothCount;
	
	public Tailor(String name) {
		this.name = name;
		this.clothCount = 0;
	}
	
	public void setWorkshop(Workshop workshop) {
		this.workshop = workshop;
	}

	@Override
	public void run() {
		while (workshop.getOrder()) {
			try {
				Thread.sleep(CLOTH_WORK_TIME);
				++clothCount;
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	public String toString() {
		return name + ", clothes: " + clothCount; 
	}
}
