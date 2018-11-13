import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Gallery {

	private String address;
	private double area;
	private List<Art> artList;
	
	public Gallery(String address, double area, List<Art> artList) {
		this.address = address;
		this.area = area;
		this.artList = artList;
	}
	
	public Gallery(String address, double area) {
		this(address, area, new ArrayList<Art>());
	}
	
	public Gallery() {
		this("", 0.0, new ArrayList<Art>());
	}
	
	public void addArt(Art art) {
		artList.add(art);
	}
	
	public void removeArt(Art art) {
		artList.remove(art);
	}
	
	public void printArtList() {
		for (Art art: artList)
			art.print();
	}
	
	public Art mostExpensive() {
		artList.sort(Art.PriceComparator);
		return artList.get(artList.size() - 1);
	}
	
	public void sortByProductionDate() {
		artList.sort(Art.ProductionDateComparator);
	}
	
	public void sortByTypeAndPrice() {
		artList.sort(Art.TypePriceComparator);
	}
	
	public double artByArea() {
		if (area > 0)
			return artList.size() / area;
		return 0;
	}

	public void printEveryThird() {
		for(Iterator<Art> iterator = artList.iterator(); iterator.hasNext();) {
			iterator.next().print();
			if (iterator.hasNext()) iterator.next();
			if (iterator.hasNext()) iterator.next();
		}
	}

	public String getAddress() {
		return address;
	}
}
