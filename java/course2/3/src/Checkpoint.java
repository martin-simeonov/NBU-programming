import java.util.Comparator;
import java.util.PriorityQueue;

public class Checkpoint {

	private String name;
	private PriorityQueue<Vehicle> queue;
	
	public Checkpoint(String name) {
		this.name = name;
		queue = new PriorityQueue<Vehicle>(new Comparator<Vehicle>() {

			@Override
			public int compare(Vehicle v1, Vehicle v2) {
				if (v1.isEmergencyVehicle())
					return -1;
				if (v2.isEmergencyVehicle())
					return 1;
				return v1.getWeight() - v2.getWeight();
			}
			
		});
	}
	
	public void addVehicle(Vehicle v) {
		queue.add(v);
	}
	
	public Vehicle passVehicle() {
		return queue.poll();
	}
	
}
