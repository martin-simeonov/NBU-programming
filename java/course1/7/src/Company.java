import java.io.Serializable;

public class Company implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = -8000214013149712421L;
	
	private String name;
	private int id;
	
	public Company(String name, int id) {
		this.setName(name);
		this.setId(id);
	}
	
	public Company() {
		this("", 0);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
}
