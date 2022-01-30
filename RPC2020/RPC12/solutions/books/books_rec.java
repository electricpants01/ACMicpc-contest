// Arup Guha
// 8/28/2020
// Alternate Solution to UCF 2020 Locals Final Round Problem: Boxing Books
// Uses recursion and memoization

import java.util.*;

public class books_rec {

	public static long[][] precomp;
	public static long[][] memo;
	public static int n;

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		int k = stdin.nextInt();
		
		// Read in the dimensions.
		long[] width = new long[n];
		long[] height = new long[n];
		for (int i=0; i<n; i++) {
			width[i] = stdin.nextInt();
			height[i]= stdin.nextInt();
		}
		
		// Precomp for all ranges.
		precomp = new long[n][n];
		for (int s=0; s<n; s++) {
			long h = 0, w = 0;
			for (int i=s; i<n; i++) {
				h = Math.max(h, height[i]);
				w += width[i];
				precomp[s][i] = h*w;
			}
		}
		
		// Set up memo and go.
		memo = new long[n+1][k+1];
		for (int i=0; i<n; i++) Arrays.fill(memo[i], -1);
		System.out.println(go(0, k));
	}
	
	// returns best answer for [s..n-1] using numBoxes.
	public static long go(int s, int numBoxes) {
		
		// Bunch of base cases.
		if (s >= n) return 0;
		if (numBoxes == 1) return precomp[s][n-1];
		if (numBoxes > n-s) return 100000000000000000L;
		if (memo[s][numBoxes] != -1) return memo[s][numBoxes];
		
		// Try each split point and return the best.
		long res = 1000000000000000000L;
		for (int e=s; e<n; e++) {
			if (numBoxes > n-e) break;
			long cur = precomp[s][e] + go(e+1,numBoxes-1);
			res = Math.min(res, cur);
		}
		return memo[s][numBoxes] = res;
	}
}