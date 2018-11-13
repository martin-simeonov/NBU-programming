import java.util.ArrayList;
import java.util.List;

public class MainClass {

	public static void main(String[] args) {
		Post p1 = new Post("Definition of OOP Concepts in Java (https://stackify.com/oops-concepts-in-java/)", 
				"OOP concepts in Java are the main ideas behind Java’s Object Oriented " + 
				"Programming. They are an abstraction, encapsulation, inheritance, and polymorphism. " +
				"Grasping them is key to understanding how Java works. Basically, Java OOP concepts let " +
				"us create working methods and variables, then reuse all or part of them without " +
				"compromising security.");
		Post p2 = new Post("What is object oriented programming (OOP)?(https://www.nextacademy.com/blog/object-oriented-programming-oop/)",
				"Object Oriented Programming (OOP) is the foundation of mastering most of the " + 
				"widely used programming languages such as Java, Python, Ruby and, of course, Swift. It " +
				"helps you in the process of designing your app because an app without any proper " +
				"planning will make you go crazy (trust me, been there, done that).");
		
		System.out.println(p1.countInText("ti"));
		
		List<Post> list = new ArrayList<Post>();
		list.add(p1);
		list.add(p2);
		Blog b = new Blog(list);
		
		b.searchInPost("OOP");
	}

}
