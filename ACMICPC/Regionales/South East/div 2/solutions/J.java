// Arup Guha
// 11/9/2019
// Solution to 2019 SER D2 Problem: Rainbow Strings

import java.util.*;

public class rainbow {

	final public static long MOD = 11092019;

	public static void main(String[] args) {
	
		// Get input.
		Scanner stdin = new Scanner(System.in);
		char[] s = stdin.next().toCharArray();
		int len = s.length;
		
		// All we care about are frequencies.
		long[] freq = new long[26];
		for (int i=0; i<s.length; i++)
			freq[s[i]-'a']++;
		
		// For any letter, we can either not select it, or select one of its occurrences.
		long res = 1;
		for (int i=0; i<26; i++)
			res = (res*(freq[i]+1))%MOD;
		
		// Ta da!
		System.out.println(res);
	}
}