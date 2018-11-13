
public enum ArtType {
	Painting(1, "Painting"), Sculpture(2, "Sculpture"), Ceramics(3, "Ceramics"), WoodCarving(4, "Wood carving");
	
	private int id;
	private String typeString;
	
	private ArtType(int id, String typeString) {
		this.id = id;
		this.typeString = typeString;
	}
	
	public String toString() {
		return typeString;
	}
	
	public int getId() {
		return id;
	}
}
