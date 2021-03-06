import java.util.ArrayList;
import java.util.List;

public class Workshop {

	private int clothOrders;
	private List<Tailor> tailors;
	
	public Workshop(int clothOrders) {
		this.clothOrders = clothOrders;
		tailors = new ArrayList<Tailor>();
	}
	
	public void addTailor(Tailor t) {
		tailors.add(t);
		t.setWorkshop(this);
	}
	
	public void startWork() {
		for (Tailor t : tailors)
			t.start();
	}
	
	public void printWork() {
		for (Tailor t : tailors) {
			try {
				t.join();
				System.out.println(t);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	public synchronized boolean getOrder() {
		if (clothOrders > 0) {
			--clothOrders;
			return true;
		} else {
			return false;
		}
	}
	
}
