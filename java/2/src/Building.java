
public class Building {
	private String address;
	private int floors;
	private double area;
	private double areaPrice;
	private double euroExchangeRate;
	
	public static final double EURO_EXCHANGE_RATE = 0.511206011;
	
	public Building() {
		this("", 0, 0, 0);
	}
	
	public Building(String address, int floors, double area, double areaPrice) {
		this.address = address;
		this.floors = floors;
		this.area = area;
		this.areaPrice = areaPrice;
		
		euroExchangeRate = EURO_EXCHANGE_RATE;
	}
	
	// Разгърната площ
	public double getGrossArea() {
		return area * floors;
	}
	
	public double getBuildingPrice() {
		return getGrossArea() * areaPrice;
	}
	
	public double getBuildingPriceEuro() {
		return getGrossArea() * (areaPrice * euroExchangeRate);
	}
	
	public void increaseBuildingPrice(double increase) {
		areaPrice = (getBuildingPrice() + increase) / getGrossArea();
	}
	
	public double compareBuildingPrices(Building other) {
		return this.getBuildingPrice() > other.getBuildingPrice() ? 
				this.getBuildingPrice() : other.getBuildingPrice();
	}
	
	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public int getFloors() {
		return floors;
	}

	public void setFloors(int floors) {
		this.floors = floors;
	}

	public double getArea() {
		return area;
	}

	public void setArea(double area) {
		this.area = area;
	}

	public double getAreaPrice() {
		return areaPrice;
	}

	public void setAreaPrice(double areaPrice) {
		this.areaPrice = areaPrice;
	}
	
	public double getEuroExchangeRate() {
		return euroExchangeRate;
	}

	public void setEuroExchangeRate(double euroExchangeRate) {
		this.euroExchangeRate = euroExchangeRate;
	}
	
	public static void main(String[] args) {
		Building b = new Building("", 2, 2, 2);
		System.out.println(b.getBuildingPrice() + ", " + b.getBuildingPriceEuro());
	}
}
