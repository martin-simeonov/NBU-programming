
public class Vehicle {

	private int weight;
	private boolean emergencyVehicle;

	public Vehicle() {
		this(0, false);
	}
	
	public Vehicle(int weight, boolean emergencyVehicle) {
		this.weight = weight;
		this.emergencyVehicle = emergencyVehicle;
	}
	
	public boolean isEmergencyVehicle() {
		return emergencyVehicle;
	}
	
	public int getWeight() {
		return weight;
	}
	
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	public String toString() {
		return "Weight:" + weight + ", emergency:" + emergencyVehicle;
	}
}
