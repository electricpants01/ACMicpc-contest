// Arup Guha
// 11/9/2019
// Solution to 2019 SER D2 Problem: ReMorse

import java.util.*;

public class remorse {
	
	// Just brute force these cheapest costs by listing out a bunch of combos of dots and dashes.
	final public static int[] COST = {1,3,3,5,5,5,7,7,7,7,7,9,9,9,9,9,9,9,9,11,11,11,11,11,11,11};

	public static void main(String[] args) {
	
		// Just Read frequencies of each character.
		Scanner stdin = new Scanner(System.in);
		String line = stdin.nextLine().toLowerCase();
		int[] freq = new int[26];
		int cnt = 0;
		for (int i=0; i<line.length(); i++) {
			if (line.charAt(i) >= 'a' && line.charAt(i) <='z') {
				freq[line.charAt(i)-'a']++;
				cnt++;
			}
		}
		
		// We greedily assign these in order.
		Arrays.sort(freq);
		
		// So make the most frequent characters the cheapest.
		int cost = 0;
		for (int i=0,j=freq.length-1; j>=0; i++,j--)
			cost += (freq[j]*COST[i]);
			
		// Separators.
		cost += (3*(cnt-1));
				
		// Ta da!
		System.out.println(cost);
	}
}