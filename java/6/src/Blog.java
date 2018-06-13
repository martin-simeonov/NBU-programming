import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Blog {

	private List<Post> postList;
	
	public Blog(List<Post> postList) {
		this.postList = postList;
	}
	
	public Blog() {
		this(new ArrayList<Post>());
	}
	
	public void searchInPost(String str) {
		List<Post> temp = new ArrayList<>(postList);
		temp.sort(new Comparator<Post>() {
			@Override
			public int compare(Post p1, Post p2) {
				int c1 = p1.countInText(str);
				int c2 = p2.countInText(str);
				
				if (c1 > c2) return -1;
				else if (c1 < c2) return 1;
				else return 0;
			}
		});
		for (Post post : temp)
			System.out.println(post.getTitle());
	}
	
}
