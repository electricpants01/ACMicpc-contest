// Arup Guha
// 8/28/2020
// Solution to UCF 2020 Locals Final Round Problem: Boxing Books

import java.util.*;

public class books {

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int k = stdin.nextInt();
		
		// Read in the dimensions.
		long[] width = new long[n];
		long[] height = new long[n];
		for (int i=0; i<n; i++) {
			width[i] = stdin.nextInt();
			height[i]= stdin.nextInt();
		}
		
		// Do for one box.
		long[] dp = new long[n];
		long h = 0, w = 0;
		for (int i=0; i<n; i++) {
			h = Math.max(h, height[i]);
			w += width[i];
			dp[i] = h*w;
		}
		
		// Now store for i boxes, based on previous.		
		for (int i=2; i<=k; i++) {
		
			long[] tmp = new long[n];
			
			// What I am trying to maximize.
			for (int j=i-1; j<n; j++) {
				
				// This is if I make a box to store the last book.
				tmp[j] = width[j]*height[j] + dp[j-1];
				
				// Dimensions of last box.
				h = height[j];
				w = width[j];
				
				// Extend last box as far back as possible.
				for (int prev=j-2; prev>=i-2; prev--) {
					
					// Update this last box and the answer.
					h = Math.max(h, height[prev+1]);
					w += width[prev+1];
					long ans = h*w + dp[prev];
					
					// Update if this box makes a better answer.
					tmp[j] = Math.min(tmp[j], ans);
				}
			}
			
			// Update for next round.
			dp = tmp;
		}
		
		// Ta da!
		System.out.println(dp[n-1]);
	}
}