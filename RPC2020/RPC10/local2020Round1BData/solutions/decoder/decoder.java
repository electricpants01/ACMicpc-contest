// Arup Guha
// 9/5/2020
// Alternate Solution to 2020 UCF Locals Problem: Decoder Ring

import java.util.*;

public class decoder {

	final public static long MOD = 1000000007L;

	// Store memo table.
	public static HashMap<String,Long> memo;
	
	// Input.
	public static char[] inp;
	public static long reps;
	public static char[] msg;
	
	// Frequencies of input.
	public static int[] freq;
	
	// stores # ways to do msg[i][j] in a single repetition of input.
	public static long[][] dp;
	
	public static void main(String[] args) {
	
		// Read stuff.
		Scanner stdin = new Scanner(System.in);
		inp = stdin.next().toCharArray();
		reps = stdin.nextLong();
		msg = stdin.next().toCharArray();
		
		// Fill up frequencies of the input string.
		freq = new int[26];
		for (int i=0; i<inp.length; i++)
			freq[inp[i]-'a']++;
			
		// Set up memo.
		memo = new HashMap<String,Long>();
		
		// Store all answers for one repetition of inp.
		dp = new long[msg.length][msg.length];
		for (int i=0; i<msg.length; i++) 
			for (int j=i+1; j<msg.length; j++) 
				dp[i][j] = solve(i,j);
				
		// Ta da!
		System.out.println(f(0,msg.length-1,reps));
	}

	// Returns the number of ways to form msg[s..e] form rep repetitions of message.
	public static long f(int s, int e, long rep) {
		
		// We can always do the empty string in 1 way.
		if (s > e) return 1;
		
		// If are picking from nothing and there is something to pick, there is no way to do it.
		if (rep == 0) return 0;
		
		// Find how man times msg[s] occurs in rep repetitions of input.
		if (s == e) return ((rep%MOD)*freq[msg[s]-'a'])%MOD;
		
		// Another base case...how many ways to form msg[s..e] from one repetition of inp.
		if (rep == 1) return dp[s][e];
		
		// Did this case before.
		String code = s+","+e+","+rep;
		if (memo.containsKey(code)) return memo.get(code);
		
		// Try each split of the msg on both halves.
		long res = 0;
		for (int i=s; i<=e+1; i++) {
			long left = f(s,i-1,rep/2);
			long right = f(i,e, rep-rep/2);
			res = (res + left*right)%MOD;
		}
	
		// Store and return.
		memo.put(code,res);
		return res;
	}
	
	// Finds # of times msg[s,e] is in inp via DP.
	public static long solve(int s, int e) {
		
		// Set up dp table. dp[i][j] is # of ways to form the first j letters of msg[s..e]
		// from the first i letters of inp.
		long[][] res = new long[inp.length+1][e-s+2];
		for (int i=0; i<=inp.length; i++) res[i][0] = 1;
		
		for (int i=1; i<=inp.length; i++) {
			for (int j=1; j<e-s+2; j++) {
				
				// We don't match.
				res[i][j] = res[i-1][j];
				
				// Take the match.
				if (inp[i-1] == msg[s+j-1])
					res[i][j] = (res[i][j] + res[i-1][j-1])%MOD;
			}
		}
		
		// Ta da!
		return res[inp.length][e-s+1];
	}
}
