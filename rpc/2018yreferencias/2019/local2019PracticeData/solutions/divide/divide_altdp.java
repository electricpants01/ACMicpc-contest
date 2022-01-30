// Arup Guha
// 8/13/2019
// Alternate Solution to 2019 UCF Practice Locals Problem: Divide
// This solution would work for extended bounds where there are
// more choices per song.

import java.util.*;

public class divide_altdp {

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int numTracks = stdin.nextInt();
		int numSongs = stdin.nextInt();
		int[][] choices = new int[numSongs][];
		long[][] dp = new long[numSongs][];
		TreeMap[] treeChoices = new TreeMap[numSongs];
		
		// Read in the choices for each song.
		for (int i=0; i<numSongs; i++) {
			
			// We will store song choices in two ways.
			treeChoices[i] = new TreeMap<Integer,Integer>();
			int numChoices = stdin.nextInt();
			choices[i] = new int[numChoices];
			dp[i] = new long[numChoices];
			
			// One way is a sorted array.
			for (int j=0; j<numChoices; j++)
				choices[i][j] = stdin.nextInt()-1;
			Arrays.sort(choices[i]);
			
			// The other is a tree map that maps song choice to index in the array.
			for (int j=0; j<numChoices; j++) treeChoices[i].put(choices[i][j], j);
			Arrays.fill(dp[i], Long.MAX_VALUE);
		}
		
		// Just do minimum number of moves to get to the first song here.
		for (int i=0; i<choices[0].length; i++) 
			dp[0][i] = numMoves(numTracks-1, choices[0][i], numTracks);
		
		// Now run the DP - solve for min answer to get to song i with choice j.
		for (int i=1; i<choices.length; i++) {
			for (int j=0; j<choices[i].length; j++) {
				
				// Find the largest track less than mine.
				Integer left = (Integer)treeChoices[i-1].lowerKey(choices[i][j]);
				if (left == null) left = (Integer)treeChoices[i-1].lastKey();
				
				// And the smallest track after mine.
				Integer right = (Integer)treeChoices[i-1].higherKey(choices[i][j]-1);
				if (right == null) right = (Integer)treeChoices[i-1].firstKey();
				
				// The best answer must build off one of those two.
				dp[i][j] = dp[i-1][(Integer)treeChoices[i-1].get(left)] + numMoves(left, choices[i][j], numTracks);
				dp[i][j] = Math.min(dp[i][j], dp[i-1][(Integer)treeChoices[i-1].get(right)] + numMoves(right, choices[i][j], numTracks));
			}
		}
		
		// Best answer is the minimum of the last row.
		long res = dp[numSongs-1][0];
		for (int i=1; i<dp[numSongs-1].length; i++)
			res = Math.min(res, dp[numSongs-1][i]);
		
		// Ta da!
		System.out.println(res);
	}
	
	// Returns the minimum number of moves needed after completing song cur
	// and going to song next.
	public static int numMoves(int cur, int next, int numTracks) {
		int forward = (next - cur - 1 + numTracks)%numTracks;
		return Math.min(forward, numTracks-forward);
	}

}