
public class Employee {

	private static int employeeId = 0;
	
	private String name;
	private int id;
	private double salary;
	
	public Employee(String name) {
		this.name = name;
		this.salary = 0;
		this.id = ++employeeId;
	}
	
	public int getId() {
		return id;
	}
	
	public void setSalary(double salary) {
		this.salary = salary;
	}
	
	public double getSalary() {
		return salary;
	}
	
	public void increaseSalary(double percent) {
		salary += (salary / 100.0) * percent;
	}
	
	public void print() {
		System.out.println("name: " + name);
		System.out.println("id: " + id);
		System.out.println("salary: " + salary);
	}
	
}
