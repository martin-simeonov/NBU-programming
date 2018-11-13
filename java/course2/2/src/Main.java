import java.util.Calendar;

public class Main {

	public static void main(String[] args) {
		Calendar c = Calendar.getInstance();
		c.set(2014, 3, 12);
		Art a1 = new Art(300, c.getTime(), ArtType.Painting);
		c.set(2012, 4, 28);
		Art a2 = new Art(200, c.getTime(), ArtType.Painting);
		c.set(2002, 12, 12);
		Art a3 = new Art(150, c.getTime(), ArtType.Painting);
		c.set(1993, 3, 6);
		Art a4 = new Art(400, c.getTime(), ArtType.Sculpture);
		c.set(2015, 9, 12);
		Art a5 = new Art(500, c.getTime(), ArtType.Sculpture);
		c.set(1994, 4, 25);
		Art a6 = new Art(250, c.getTime(), ArtType.Sculpture);
		c.set(1923, 2, 26);
		Art a7 = new Art(450, c.getTime(), ArtType.Ceramics);
		c.set(2016, 7, 23);
		Art a8 = new Art(650, c.getTime(), ArtType.Ceramics);
		c.set(2001, 12, 2);
		Art a9 = new Art(250, c.getTime(), ArtType.WoodCarving);
		c.set(2018, 1, 12);
		Art a10 = new Art(250, c.getTime(), ArtType.WoodCarving);

		Gallery gallery = new Gallery("NBU", 200);
		gallery.addArt(a1);
		gallery.addArt(a2);
		gallery.addArt(a3);
		gallery.addArt(a4);
		gallery.addArt(a5);
		gallery.addArt(a6);
		gallery.addArt(a7);
		gallery.addArt(a8);
		gallery.addArt(a9);
		gallery.addArt(a10);
		
		gallery.printArtList();
		
		System.out.println("####################");
		// Test remove
		gallery.removeArt(a2);
		gallery.printArtList();
		
		//Test most expensive
		System.out.println("####################");
		gallery.mostExpensive().print();
		
		//Sort by production date
		System.out.println("####################");
		gallery.sortByProductionDate();
		gallery.printArtList();
		
		//Sort by type and price
		System.out.println("####################");
		gallery.sortByTypeAndPrice();
		gallery.printArtList();
		
		//Art by area
		System.out.println("####################");
		System.out.println(gallery.artByArea());
		
		//Every third
		System.out.println("####################");
		gallery.printEveryThird();
	}
	
}
