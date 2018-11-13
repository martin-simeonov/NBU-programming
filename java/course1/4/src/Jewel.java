
public class Jewel extends Goods {

	private boolean isGold;

	public Jewel(String name, double priceWithoutOvercharge, double overchargePercentage, boolean isGold) {
		super(name, priceWithoutOvercharge, overchargePercentage);
		this.isGold = isGold;
	}

	public double price() {
		if (isGold)
			return super.price() + (super.price() / 100) * 5;
		else
			return super.price();
	}

	public void print() {
		super.print();
		String message = isGold == true ? "Is" : "Isn't";
		message += " golden";
		System.out.println(message);
	}

}
