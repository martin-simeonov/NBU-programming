
public class Coach {

	private String name;
	private int experience;
	private Sport sport;
	
	public Coach(String name, int experience, Sport sport) {
		this.name = name;
		this.experience = experience;
		this.sport = sport;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getExperience() {
		return experience;
	}

	public void setExperience(int experience) {
		this.experience = experience;
	}

	public Sport getSport() {
		return sport;
	}

	public void setSport(Sport sport) {
		this.sport = sport;
	}
	
}
