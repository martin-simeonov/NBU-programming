import java.util.Random;

public class MainClass {

	public static void main(String[] args) {
		Employee[] eArr1 = new Employee[5];
		Employee[] eArr2 = new Employee[5];
		double[] salaries1 = new double[5];
		double[] salaries2 = new double[5];
		Company company1 = new Company("Company 1", 10);
		Company company2 = new Company("Company 2", 10);
		
		Random rand = new Random();
		
		for (int i = 0; i < 5; ++i) {
			eArr1[i] = new Employee("Employee1" + (i + 1));
			eArr2[i] = new Employee("Employee2" + (i + 1));
			salaries1[i] = (int) (rand.nextDouble() * 1000);
			salaries2[i] = (int) (rand.nextDouble() * 1000);
		
			company1.hireEmployee(eArr1[i], salaries1[i]);
			company2.hireEmployee(eArr2[i], salaries2[i]);
		}
		
		company1.fireEmployee(eArr1[3]);
		company2.fireEmployee(eArr1[0]);

		company1.showEmployees();
		company1.increaseSalaries(20);
		System.out.println("##########");
		company1.showEmployees();
		System.out.println("##########");
		company1.increaseSalary(eArr1[4], 10);
		company1.showEmployees();
		System.out.println("##########");
		System.out.println("sum: " + company1.salarySum()); 
	}
	
}
