
public class Food extends Goods {

	public int expirationDateInDays;

	public Food(String name, double priceWithoutOvercharge, double overchargePercentage, int expirationDateInDays) {
		super(name, priceWithoutOvercharge, overchargePercentage);
		this.expirationDateInDays = expirationDateInDays;
	}

	public double price() {
		if (expirationDateInDays <= 5)
			return super.price() - (super.price() / 100) * 20;
		else
			return super.price();
	}

	public void print() {
		super.print();
		System.out.println("Expires after " + expirationDateInDays + " day(s)");
	}

}
