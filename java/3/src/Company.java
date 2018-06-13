
public class Company {
	
	private String name;
	private int maxEmployees;
	private Employee employeeList[];
	private int listSize;
	
	public Company(String name, int maxEmployees) {
		this.name = name;
		this.maxEmployees = maxEmployees;
		employeeList = new Employee[maxEmployees];
		listSize = 0;
	}

	public void hireEmployee(Employee employee, double salary) {
		employee.setSalary(salary);
		if (listSize < maxEmployees)
			employeeList[listSize++] = employee;
		else
			System.out.println("Full");
	}
	
	public void fireEmployee(Employee employee) {
		Employee[] newEmployees = new Employee[maxEmployees];
		int i = 0;
		int limit = listSize;
		for (int k = 0; k < limit; ++k) {
			if (employeeList[k].getId() != employee.getId())
				newEmployees[i++] = employeeList[k];
			else
				--listSize;
		}
		employeeList = newEmployees;
	}
	
	public void showEmployees() {
		for (int i = 0; i < listSize; ++i)
			employeeList[i].print();
	}
	
	public double salarySum() {
		double sum = 0;
		for (int i = 0; i < listSize; ++i)
			sum += employeeList[i].getSalary();
		return sum;
	}
	
	public void increaseSalaries(double percent) {
		for (int i = 0; i < listSize; ++i)
			employeeList[i].increaseSalary(percent);
	}
	
	public void increaseSalary(Employee employee, double percent) {
		for (int i = 0; i < listSize; ++i)
			if (employeeList[i].getId() == employee.getId())
				employeeList[i].increaseSalary(percent);
	}
	
	public void printCompany() {
		System.out.println("name: " + name);
		System.out.println("max employees: " + maxEmployees);
		System.out.println("hired employees: " + listSize);
	}
	
}
