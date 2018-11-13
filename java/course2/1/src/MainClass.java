
public class MainClass {

	public static void main(String args[]) {
		Truck dumpTruck = new Truck(Truck.TruckType.Dump, 1000);
		Truck tankerTruck = new Truck(Truck.TruckType.Tanker, 5000);
		Truck refrigeratorTruck = new Truck(Truck.TruckType.Refrigerator, 100);

		dumpTruck.load(new Meat(), 100);
		dumpTruck.load(new Computer(), 800);
		dumpTruck.load(new Computer(), 300);
		System.out.println(dumpTruck.getCurrentWeight());
		
		tankerTruck.load(new Fuel(), 4000);
		tankerTruck.load(new Meat(), 1000);
		
		refrigeratorTruck.load(new Meat(), 90);
	}
	
}
