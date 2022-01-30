// Arup Guha
// 8/13/2019
// Solution to 2019 UCF Practice Locals Problem: Divide

import java.util.*;

public class divide {

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int numTracks = stdin.nextInt();
		int numSongs = stdin.nextInt();
		int[][] choices = new int[numSongs][];
		long[][] dp = new long[numSongs][];
		
		// Read in the choices for each song.
		for (int i=0; i<numSongs; i++) {
			int numChoices = stdin.nextInt();
			choices[i] = new int[numChoices];
			dp[i] = new long[numChoices];
			for (int j=0; j<numChoices; j++)
				choices[i][j] = stdin.nextInt()-1;
			Arrays.fill(dp[i], Long.MAX_VALUE);
		}
		
		// Just do minimum number of moves to get to the first song here.
		for (int i=0; i<choices[0].length; i++)
			dp[0][i] = numMoves(numTracks-1, choices[0][i], numTracks);
		
		// Now run the DP.
		for (int i=1; i<choices.length; i++) 
			for (int j=0; j<choices[i].length; j++) 
				
				// Trying to build answer from any previously played song.
				for (int prev=0; prev<choices[i-1].length; prev++) 
					dp[i][j] = Math.min(dp[i][j], dp[i-1][prev] + numMoves(choices[i-1][prev], choices[i][j], numTracks));
					
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
