
public enum Sport {
	FOOTBALL(16, 11), VOLEYBALL(9, 6), BASKETBALL(12, 5);
	
	private int teamCount;
	private int mainTeamCount;
	
	private Sport(int teamCount, int mainTeamCount) {
		this.teamCount = teamCount;
		this.mainTeamCount = mainTeamCount;
	}
	
	public int getTeamCount() {
		return teamCount;
	}
	
	public int getMainTeamCount() {
		return mainTeamCount;
	}
}
