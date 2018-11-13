
public class Truck {
	private TruckType type;
	private long capacity;
	private long currentWeight;
	
	public Truck(TruckType type, long capacity) {
		this.type = type;
		this.capacity = capacity;
	}
	
	public Truck() {
		this(TruckType.Dump, 1000);
	}

	public long getCapacity() {
		return capacity;
	}
	
	public long getCurrentWeight() {
		return currentWeight;
	}
	
	public GoodsType getCargoType() {
		return type.getCargoType();
	}
	
	public <T extends Goods> void load(T cargo, long weight) {
		if (cargo.getType() != type.getCargoType()) {
			System.out.println("Truck can't carry this type of cargo");
			return;
		}
		if (currentWeight + weight > capacity) {
			System.out.println("Not enough cargo capacity");
			return;
		}
		currentWeight += weight;
	}
	
	enum TruckType {
		Dump(GoodsType.Standard), Tanker(GoodsType.Dangerous), Refrigerator(GoodsType.Refrigerated);

		private GoodsType cargo;

		private TruckType(GoodsType cargo) {
			this.cargo = cargo;
		}

		public GoodsType getCargoType() {
			return cargo;
		}
	}
}
