import java.io.File;
import java.util.Scanner;

public class bulk {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);

		int c = in.nextInt();
		int p = in.nextInt();

		// tally up the first item
		int total = p;

		// for each item beyond the first, add 2 less than the price
		for (int i = 1; i < c; i++) {
			total += p - 2;
		}
		System.out.println(total);
	}
}
