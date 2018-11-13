import java.util.ArrayList;
import java.util.List;

public class Shop {

	private int maxStock;
	private List<Goods> stock;

	public Shop(int maxStock) {
		this.maxStock = maxStock;
		stock = new ArrayList<>();
	}

	public double totalRevenue() {
		double revenue = 0;
		for (Goods good : stock)
			revenue += good.price();

		return revenue;
	}

	public void print() {
		System.out.println("Max stock: " + maxStock + ", revenue: " + totalRevenue());
		System.out.println("Stock: ");
		for (Goods good : stock)
			good.print();
		System.out.println("##############");
	}

	public void addStock(Goods good) {
		if (stock.size() == maxStock)
			System.out.println("Shop is fulll");
		else
			stock.add(good);
	}

}
