// Arup Guha
// 8/20/2019
// Solution to 2019 UCF Locals Problem: Sort by Frequency

import java.util.*;

public class freq_arup {

	public static void main(String[] args) {
	
		// Read in the input, counting how many of each letter there are.
		Scanner stdin = new Scanner(System.in);
		String s = stdin.next();
		int[] freq = new int[26];
		for (int i=0; i<s.length(); i++)
			freq[s.charAt(i)-'a']++;
		
		// Create each letter object.
		ArrayList<letter> list = new ArrayList<letter>();
		for (int i=0; i<26; i++)
			if (freq[i] > 0)
				list.add(new letter((char)('a'+i),freq[i]));
		
		// Sort the objects.
		Collections.sort(list);
		
		// Print each.
		for (int i=0; i<list.size(); i++)
			System.out.print(list.get(i));
		System.out.println();
	}
}

class letter implements Comparable<letter> {

	public char c;
	public int cnt;
	
	public letter(char myc, int freq) {
		c = myc;
		cnt = freq;
	}
	
	// String representation - just the letter c cnt times.
	public String toString() {
		char[] res = new char[cnt];
		Arrays.fill(res, c);
		return new String(res);
	}
	
	// How we want to sort the letters.
	public int compareTo(letter other) {
		if (this.cnt != other.cnt) return other.cnt - this.cnt;
		return c - other.c;
	}
}