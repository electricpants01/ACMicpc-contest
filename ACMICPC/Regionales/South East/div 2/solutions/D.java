// Arup Guha
// 11/9/2019
// Solution to 2019 SER D2 Problem: From A to B

import java.util.*;

public class fromatob {

	public static void main(String[] args) {
	
		// Get input.
		Scanner stdin = new Scanner(System.in);
		int a = stdin.nextInt();
		int b = stdin.nextInt();
			
		int cnt = 0;
			
		// Be greedy.
		while (a != b) {
				
			// We can divide by 2, do it.
			if (a > b && a%2 == 0) { 
				a /= 2;
				cnt++;
			}
				
			// We are forced to add 1.
			else if (a > b && a%2 == 1) {
				a++;
				cnt++;
			}
				
			// This is our final step.
			else {
				cnt += (b-a);
				a = b;
			}
		}
			
		// Ta da!
		System.out.println(cnt);
	}
}