
public class Goods {

	private String name;
	private double priceWithoutOvercharge;
	private double overchargePercentage;

	public Goods(String name, double priceWithoutOvercharge, double overchargePercentage) {
		this.name = name;
		this.priceWithoutOvercharge = priceWithoutOvercharge;
		this.overchargePercentage = overchargePercentage;
	}

	public double price() {
		return priceWithoutOvercharge + (priceWithoutOvercharge / 100) * overchargePercentage;
	}

	public void print() {
		System.out.println(name + ", price: " + price() + ", overcharge: " + overchargePercentage
				+ "%, price without overcharge: " + priceWithoutOvercharge);
	}

}
