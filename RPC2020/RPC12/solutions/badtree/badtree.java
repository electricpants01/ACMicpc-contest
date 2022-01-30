// Arup Guha
// 9/11/2020
// Solution to UCF 2020 Locals Final Round Problem: Bad Tree

import java.util.*;

public class badtree {

	public static void main(String[] args) {
	
		// Get size and rank.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		long rank = stdin.nextLong()-1;
		
		// When we can't do it.
		if (n <= 60 && rank+1 > (1L<<(n-1)) )
			System.out.println(-1);
		
		// Key idea behind the solution is that # of valid perms is 2^(n-1), at each
		// juncture except the last, you can either insert the smallest or largest value
		// that hasn't been inserted, and half of the trees are formed with the smallest
		// and the other half with the largest. So, you just see how many more ranks you
		// have to advance to decide whether or not to take the smallest or largest value
		// not yet placed and adjust the remaining rank accordingly. Last issue to watch
		// out for is an overflow if you bit shift too far...
		else {
		
			// Just need to keep pointers to the beginning
			// and end of the list of values not placed yet.
			int low = 1, high = n;
		
			// Store answer here.
			int[] res = new int[n];
		
			// Go bit by bit.
			for (int i=0; i<n; i++) {
		
				// If count is too high or rank is too low, we go with low.
				if (n-i-2 >= 60 || rank < (1L<<(n-i-2)) )
					res[i] = low++;
				
				// Otherwise, we take from the high end and subtract the bit value from rank.
				else {
					res[i] = high--;
					rank -= (1L<<(n-i-2));
				}
			}
		
			// Ta da!
			for (int i=0; i<n-1; i++)
				System.out.print(res[i]+" ");
			System.out.println(res[n-1]);
		}
	}
}