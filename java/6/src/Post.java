
public class Post {
	
	private static int idCount = 0;
	
	private int id;
	private String title;
	private String text;
	
	public Post(String title, String  text) {
		this.title = title;
		this.text = text;
		id = ++idCount;
	}
	
	public Post() {
		this("", "");
	}
	
	public boolean titleContain(String str) {
		return title.contains(str);
	}
	
	public int countInText(String str) {
	      int count = 0;
	      int idx = 0;
	      while ((idx = text.indexOf(str, idx)) != -1) {
	          count++;
	          idx += str.length();
	      }
	      return count;
	}
	
	public String getTitle() {
		return title;
	}
	
}
