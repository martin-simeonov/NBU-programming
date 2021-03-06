import java.util.Set;
import java.util.TreeSet;

public class PlasticGoodsManufacturer {

	private String name;
	private TreeSet<PlasticGoods> set;
	
	public PlasticGoodsManufacturer(String name){
		this.name = name;
		set = new TreeSet<PlasticGoods>();
	}
	
	public void addGoods(PlasticGoods goods) {
		set.add(goods);
	}
	
	private double average() {
		if (set.size() == 0) return 0.0;
		
		double sum = 0.0;
		for (PlasticGoods pg : set) {
			sum += pg.getPrice();
		}
		return sum /  set.size() - 1;
	}
	
	public PlasticGoods closestToAverage() {
		double average = average();
		PlasticGoods t = new PlasticGoods(average);
		PlasticGoods floor = set.floor(t);
		PlasticGoods ceiling = set.ceiling(t);
		
		if (average - floor.getPrice() > ceiling.getPrice() - average) {
			return ceiling;
		} else {
			return floor;
		}
	}
	
	public void aboveAverage() {
		double average = average();
		PlasticGoods t = new PlasticGoods(average);
		for (PlasticGoods p : set.tailSet(t))
			System.out.println(p);
	}
	
	public void belowAverage() {
		double average = average();
		PlasticGoods t = new PlasticGoods(average);
		for (PlasticGoods p : set.headSet(t))
			System.out.println(p);
	}
}
