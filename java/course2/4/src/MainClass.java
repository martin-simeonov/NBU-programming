import java.util.Date;
import java.util.Random;

public class MainClass {

	public static void main(String args[]) {
		Team foot1 = new Team("Football team 1", 1000, new Coach("CoachFoot1", 20, Sport.FOOTBALL), Sport.FOOTBALL);
		Team foot2 = new Team("Football team 2", 500, new Coach("CoachFoot2", 15, Sport.FOOTBALL), Sport.FOOTBALL);
		Team foot3 = new Team("Football team 3", 2000, new Coach("CoachFoot3", 22, Sport.FOOTBALL), Sport.FOOTBALL);
		Team bask1 = new Team("Basketball team 1", 2050, new Coach("CoachBask1", 10, Sport.BASKETBALL), Sport.BASKETBALL);
		Team bask2 = new Team("Basketball team 2", 1200, new Coach("CoachBask2", 12, Sport.BASKETBALL), Sport.BASKETBALL);
		Team vol1 = new Team("Voleyball team 1", 1250, new Coach("CoachVol1" , 5, Sport.VOLEYBALL), Sport.VOLEYBALL);
		Team vol2 = new Team("Voleyball team 2", 1000, new Coach("CoachVol2", 9, Sport.VOLEYBALL), Sport.VOLEYBALL);
		
		Olympics o = new Olympics(new Date(), "Sofia");
		o.addTeam(foot1);
		o.addTeam(foot2);
		o.addTeam(foot3);
		o.addTeam(bask1);
		o.addTeam(bask2);
		o.addTeam(vol1);
		o.addTeam(vol2);

		populateTeam(o, foot1, 1, Sport.FOOTBALL, "Foot");
		populateTeam(o, foot2, 2, Sport.FOOTBALL, "Foot");
		populateTeam(o, foot3, 3, Sport.FOOTBALL, "Foot");
		populateTeam(o, bask1, 1, Sport.BASKETBALL, "Bask");
		populateTeam(o, bask2, 2, Sport.BASKETBALL, "Bask");
		populateTeam(o, vol1, 1, Sport.VOLEYBALL, "Vol");
		populateTeam(o, vol2, 2, Sport.VOLEYBALL, "Vol");
	
		o.printAll();
		o.showMostExperiencedCoach();
		
		// Test insertion over max
		Player p = new Player("Foottest", Sport.FOOTBALL);
		foot1.addPlayer(p, 1000);
		o.addTeamMember(foot1, p, true);
		
		// Test removal from main team
		o.removePlayer(foot1.getPlayers().keySet().iterator().next());
		
		o.removeTeam(vol1);
		
		o.printAll();
	}
	
	public static void populateTeam(Olympics o, Team team, int num, Sport sport, String name) {
		Player p;
		for (int i = 1; i <= sport.getTeamCount(); ++i) {
			p = new Player(name + "" + num + "-" + i, sport);
			team.addPlayer(p, new Random().nextDouble());
			if (i <= sport.getMainTeamCount())
				o.addTeamMember(team, p, true);
			else
				o.addTeamMember(team, p, false);
		}
	}
	
}
