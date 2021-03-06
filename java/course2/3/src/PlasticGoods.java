
public class PlasticGoods implements Comparable<PlasticGoods>{

	private String name;
	private double price;
	
	public PlasticGoods(String name, double price) {
		this.name = name;
		this.price = price;
	}
	
	public PlasticGoods(double price) {
		this("", price);
	}

	@Override
	public int compareTo(PlasticGoods other) {
		return (new Double(price)).compareTo(other.price);
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public String toString() {
		return "Name: " + name + ", price: " + price;
	}
}
