
public class Homework1 {

	public static void task1(int bottom, int top, int difference) {
		if (bottom > top)
			System.out.println("wrong interval");
		
		char first;
		String num;
		int reverse;
		
		for (int i = bottom; i <= top; ++i) {
			num = String.valueOf(i);
			first = num.charAt(0);
			reverse = Integer.parseInt(num.substring(1, num.length()) + first);

			if ((reverse - i) > difference)
				System.out.println(i);
		}
	}
	
	public static void task2(int n) {
		String line = "";
		for (int i = 1; i <= n; ++i) {

			for (int j = 1; j <= n;	++j) {
				if (j < i) line += " ";
				else line += j;
			}
			System.out.println(line + new StringBuilder(line).reverse());
			line = "";
		}
		
		for (int i = n - 1; i >= 1; --i) {
			for (int j = 1; j <= n;	++j) {
				if (j < i) line += " ";
				else line += j;
			}
			System.out.println(line + new StringBuilder(line).reverse());
			line = "";
		}
	}
	
	public static void main(String[] args) {
		task1(10, 10000, 5000);
		System.out.println();
		task2(6);
	}
	
}
