import java.util.ArrayList;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Olympics {

	private Date date;
	private String address;
	private Map<Team, Set<Player>> teamMain;
	private Map<Team, Set<Player>> teamReserve;

	public Olympics(Date date, String address) {
		this.date = date;
		this.address = address;
		teamMain = new TreeMap<Team, Set<Player>>();
		teamReserve = new TreeMap<Team, Set<Player>>();
	}

	public void addTeam(Team t) {
		teamMain.put(t, new TreeSet<Player>());
		teamReserve.put(t, new TreeSet<Player>());
	}

	private boolean checkTeam(Team t, Player p) {
		if (!t.getPlayers().containsKey(p)) {
			System.out.println(p + "is not part of team " + t.getName());
			return false;
		}
		return true;
	}

	public void addTeamMemberToReserve(Team t, Player p) {
		if (!teamReserve.containsKey(t))
			addTeam(t);
		if (!checkTeam(t, p))
			return;

		if (t.getSport().getTeamCount() > teamMain.get(t).size() + teamReserve.get(t).size()) {
			teamReserve.get(t).add(p);
		} else {
			System.out.println("Team quota is full");
		}
	}

	public void addTeamMemberToReserve(Team t, Set<Player> players) {
		for (Player p : players)
			addTeamMemberToReserve(t, p);
	}

	public void addTeamMemberToMain(Team t, Player p) {
		if (!teamMain.containsKey(t))
			addTeam(t);
		if (!checkTeam(t, p))
			return;

		if (t.getSport().getMainTeamCount() > teamMain.get(t).size()) {
			teamMain.get(t).add(p);
		} else {
			System.out.println("Main team quota is full");
		}
	}

	public void addTeamMemberToMain(Team t, Set<Player> players) {
		for (Player p : players)
			addTeamMemberToMain(t, p);
	}

	public void addTeamMember(Team t, Player p, boolean isMain) {
		if (isMain)
			addTeamMemberToMain(t, p);
		else
			addTeamMemberToReserve(t, p);
	}

	public void addTeamMembers(Team t, Map<Player, Boolean> players) {
		for (Map.Entry<Player, Boolean> me : players.entrySet()) {
			if (me.getValue())
				addTeamMemberToMain(t, me.getKey());
			else
				addTeamMemberToReserve(t, me.getKey());
		}
	}

	public void removeTeam(Team t) {
		teamMain.remove(t);
		teamReserve.remove(t);
	}

	private void shiftFromReserve(Team t) {
		Player p = teamReserve.get(t).iterator().next();
		teamReserve.get(t).remove(p);
		teamMain.get(t).add(p);
	}

	public void removePlayer(Player p) {
		for (Map.Entry<Team, Set<Player>> me : teamMain.entrySet()) {
			if (me.getValue().remove(p)) {
				shiftFromReserve(me.getKey());
			}
		}
		for (Set<Player> players : teamReserve.values()) {
			players.remove(p);
		}
	}

	public void printAll() {
		for (Team team : teamMain.keySet()) {
			System.out.println(team);
			System.out.println("Main team:");
			for (Player p : teamMain.get(team))
				System.out.println(p);
			System.out.println("####\nReserves:");
			for (Player p : teamReserve.get(team))
				System.out.println(p);
			System.out.println("\n");
		}
	}
	
	public void showMostExperiencedCoach() {
		List<Team> list = new ArrayList<Team>(teamMain.keySet());
		list.sort(new Comparator<Team>() {

			@Override
			public int compare(Team t1, Team t2) {
				return t2.getCoach().getExperience() - t1.getCoach().getExperience();
			}
			
		});
		System.out.println(list.get(0).getCoach().getName() + " " + 
		list.get(0).getCoach().getExperience() + " years");
	}
	
}
