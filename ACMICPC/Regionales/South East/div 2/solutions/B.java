// Arup Guha
// 11/10/2019
// Solution to 2019 SER D1/D2 Problem: Carryless Square Root

import java.util.*;

public class carryless {

	public static int[] sqr;
	public static int len;
	
	public static void main(String[] args) {
	
		// Read input.
		Scanner stdin = new Scanner(System.in);
		String s = stdin.next();
		sqr = new int[s.length()];
		len = sqr.length;
		for (int i=0; i<len; i++)
			sqr[i] = s.charAt(i) - '0';
		
		// Call our wrapper function.
		int[] res = wrapper();
		
		// No solution.
		if (res == null)
			System.out.println(-1);
		
		// Just go print digit by digit.
		else {
			for (int i=0; i<res.length; i++)
				System.out.print(res[i]);
			System.out.println();
		}
	}
	
	public static int[] wrapper() {
	
		// Must be odd length.
		if (len%2 == 0) return null;
		
		int[] cur = new int[(len+1)/2];
		int[] sum = new int[len];
		boolean res = go(cur, sum, 0); 
		
		// Didn't work.
		if (!res) return null;
		
		// Here is our result.
		return cur;
	}

	// Returns true iff there's a solution with the first k digits of cur fixed
	// which has currently contributed sum. Returns false otherwise.
	public static boolean go(int[] cur, int[] sum, int k) {
	
		// Base case.
		if (k == cur.length)
			return isSqr(sum);

		// first digit to try.
		int s = k == 0 ? 1 : 0;
		
		// Just try each digit in order.
		for (int d=s; d<10; d++) {
		
			// Try d in slot k.
			int[] cpy = copy(sum);
			cur[k] = d;
			
			// Update just our copy.
			int cLen = cur.length-1;
			cpy[2*k] = (cpy[2*k] + cur[k]*cur[k])%10;
			for (int z=k-1; z>=0; z--) 
				cpy[k+z] = (cpy[k+z] + 2*cur[k]*cur[z])%10;
			
			// Last update to location 2*cLen-k
			if (cpy[k] != sqr[k]) continue;
			
			// Recurse.
			boolean res = go(cur, cpy, k+1);
			
			// Woo hoo!
			if (res) return true;
		}
		
		// If we get here, it never worked.
		return false;
	}
	
	// Deep copy of a.
	public static int[] copy(int[] a) {
		int[] res = new int[a.length];
		for (int i=0; i<res.length; i++) res[i] = a[i];
		return res;
	}
	
	// Returns true iff arr is sqr (input).
	public static boolean isSqr(int[] arr) {
		for (int i=0; i<sqr.length; i++)
			if (arr[i] != sqr[i])
				return false;
		return true;
	}
}