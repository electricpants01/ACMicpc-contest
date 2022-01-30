import java.io.File;
import java.util.Scanner;

public class stopping {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);

		int m = in.nextInt();
		int g = in.nextInt();
		int f = in.nextInt();

		// loop through to the total miles, if the loop counter is divisible
		// by the gas mileage or food mileage, increment a counter
		int count = 0;
		for (int i = 1; i < m; i++) {
			if (i % g == 0 || i % f == 0) {
				count++;
			}
		}

		System.out.println(count);
	}
}
