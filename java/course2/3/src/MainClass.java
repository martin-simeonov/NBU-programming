
public class MainClass {

	public static void main(String arsgs[]) {
		Checkpoint c = new Checkpoint("Kalotina");
		c.addVehicle(new Vehicle(3000, false));
		c.addVehicle(new Vehicle(2000, false));
		c.addVehicle(new Vehicle(2500, true));
		c.addVehicle(new Vehicle(1200, false));
		Vehicle v;
		while ((v = c.passVehicle()) != null)
			System.out.println(v);
		
		System.out.println("#########");
		
		PlasticGoodsManufacturer man = new PlasticGoodsManufacturer("manufacturer");
		man.addGoods(new PlasticGoods("cup", 10));
		man.addGoods(new PlasticGoods("vase", 50));
		man.addGoods(new PlasticGoods("table", 30));
		man.addGoods(new PlasticGoods("ball", 20));
		System.out.println(man.closestToAverage());
		System.out.println("#########");
		man.aboveAverage();
		System.out.println("#########");
		man.belowAverage();
	}

}
