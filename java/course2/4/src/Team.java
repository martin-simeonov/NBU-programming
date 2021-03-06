import java.util.Map;
import java.util.TreeMap;

public class Team implements Comparable<Team> {

	private String name;
	private double budget;
	private Coach coach;
	private Map<Player, Double> players;
	private Sport sport;
	
	public Team(String name, double budget, Coach coach, Sport sport) {
		this.name = name;
		this.budget = budget;
		this.coach = coach;
		this.sport = sport;
		this.players = new TreeMap<Player, Double>();
	}

	public void addPlayer(Player p, double sum) {
		players.put(p, sum);
	}
	
	public void removePlayer(Player p) {
		players.remove(p);
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getBudget() {
		return budget;
	}

	public void setBudget(double budget) {
		this.budget = budget;
	}

	public Coach getCoach() {
		return coach;
	}

	public void setCoach(Coach coach) {
		this.coach = coach;
	}

	public Map<Player, Double> getPlayers() {
		return players;
	}

	public void setPlayers(Map<Player, Double> players) {
		this.players = players;
	}

	public Sport getSport() {
		return sport;
	}

	public void setSport(Sport sport) {
		this.sport = sport;
	}
	
	public String toString() {
		return "Team: " + name  + "\nCoach: " + coach.getName() + "\nBudget: " + budget;
	}

	// Order of team first by sport and then by budget
	@Override
	public int compareTo(Team o) {
		if (sport == o.sport)
			return Double.compare(budget, o.budget);
		return Integer.compare(sport.getMainTeamCount(), o.sport.getMainTeamCount());
	}
	
}
