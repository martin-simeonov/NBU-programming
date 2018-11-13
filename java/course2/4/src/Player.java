
public class Player implements Comparable<Player> {

	private String name;
	private Sport sport;
	
	public Player(String name, Sport sport) {
		this.name = name;
		this.sport = sport;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Sport getSport() {
		return sport;
	}
	public void setSport(Sport sport) {
		this.sport = sport;
	}

	@Override
	public int compareTo(Player o) {
		return this.name.compareTo(o.name);
	}
	
	public String toString() {
		return name;
	}
	
}
