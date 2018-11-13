import java.util.Comparator;
import java.util.Date;

public class Art {

	private double price;
	private Date productionDate;
	private ArtType type;
	
	public Art(double price, Date productionDate, ArtType type) {
		this.price = price;
		this.productionDate = productionDate;
		this.type = type;
	}
	
	public Art() {
		this(0.0, new Date(), ArtType.Painting);
	}
	
	public void print() {
		System.out.println("Type: " + type + ", production date: " + productionDate + ", price: " + price);
	}
	
	public double getPrice() {
		return price;
	}
	
	public Date getProductionDate() {
		return productionDate;
	}
	
	public ArtType getType() {
		return type;
	}
	
	public static Comparator<Art> PriceComparator = new Comparator<Art>() {
		public int compare(Art a1, Art a2) {
			return Double.compare(a1.getPrice(), a2.getPrice());
		}
	};
	
	public static Comparator<Art> ProductionDateComparator = new Comparator<Art>() {
		public int compare(Art a1, Art a2) {
			return a1.getProductionDate().compareTo(a2.getProductionDate());
		}
	};
	
	public static Comparator<Art> TypePriceComparator = new Comparator<Art>() {
		public int compare(Art a1, Art a2) {
			if (a1.getType().getId() < a2.getType().getId()) return -1;
			if (a1.getType().getId() > a2.getType().getId()) return 1;
			
			if (a1.getPrice() < a2.getPrice()) return -1;
			if (a2.getPrice() > a2.getPrice()) return 1;
			return 0;
		}
	};
}
