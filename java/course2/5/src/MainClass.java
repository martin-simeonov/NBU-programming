
public class MainClass {

	public static void main(String args[]) {
		Workshop w = new Workshop(23);
		w.addTailor(new Tailor("Tailor 1"));
		w.addTailor(new Tailor("Tailor 2"));
		w.addTailor(new Tailor("Tailor 3"));
		w.addTailor(new Tailor("Tailor 4"));
		w.startWork();
		w.printWork();
	}
	
}