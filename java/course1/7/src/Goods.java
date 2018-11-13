import java.io.Serializable;

public class Goods implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 4448585088855831816L;
	
	private String name;
	private double deliveryPrice;
	private double overprice;
	
	public Goods(String name, double price, double overprice) {
		this.setName(name);
		this.setDeliveryPrice(price);
		this.setOverprice(overprice);
	}

	public Goods() {
		this("", 0, 0);
	}
	
	public double getPrice() {
		return deliveryPrice + ((deliveryPrice / 100) * overprice);
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getDeliveryPrice() {
		return deliveryPrice;
	}

	public void setDeliveryPrice(double price) {
		this.deliveryPrice = price;
	}

	public double getOverprice() {
		return overprice;
	}

	public void setOverprice(double overprice) {
		this.overprice = overprice;
	}
}
