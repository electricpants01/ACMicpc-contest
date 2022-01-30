// Arup Guha
// 11/9/2019
// Solution to 2019 SER D2 Problem: Balanced Animals

import java.util.*;

public class animals {
	
	public static void main(String[] args) {
	
		// Read the numbers and sort.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		long sum = 0;
		int[] vals = new int[n];
		for (int i=0; i<n; i++) {
			vals[i] = 2*stdin.nextInt();
			sum += vals[i];
		}
		Arrays.sort(vals);
		
		// Go halfway.
		int idx = 0;
		int newsum = 0;
		while (newsum < sum/2) 
			newsum += vals[idx++];
		
		// Case where left half is exactly half.
		if (newsum == sum/2) {
			
			// Even divider, so it's the number.
			if (vals[idx] == vals[idx-1])
				System.out.println(vals[idx]/2);
			
			// Clean divide, so it's the number higher.
			else
				System.out.println(vals[idx-1]/2+1);
		}
		
		// Since they say it's possible, this must be the divider...
		else 
			System.out.println(vals[idx-1]/2);
	}
}