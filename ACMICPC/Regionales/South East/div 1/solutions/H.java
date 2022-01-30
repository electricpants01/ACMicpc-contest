// Arup Guha
// 11/9/2019
// Solution to 2019 SER D1/D2 Problem: Levenshtein Distance

import java.util.*;

public class levenshtein {

	public static void main(String[] args) {
	
		// Get input.
		Scanner stdin = new Scanner(System.in);
		char[] alpha = stdin.next().toCharArray();
		String word = stdin.next();
		
		// Add all possibilities to the treeset.
		TreeSet<String> set = new TreeSet<String>();
		addLet(word, alpha, set);
		delLet(word, set);
		deltaLet(word,alpha,set);
		
		// Ta da!
		while (set.size() > 0) 
			System.out.println(set.pollFirst());
		
	}
	
	// Just loop over all insertion positions and all letters to insert.
	public static void addLet(String word, char[] alpha, TreeSet<String> set) {
		for (int i=0; i<=word.length(); i++) 
			for (int j=0; j<alpha.length; j++)
				set.add(word.substring(0,i)+alpha[j]+word.substring(i));
	}
	
	// Loop over all positions to delete...
	public static void delLet(String word, TreeSet<String> set) {
		for (int i=0; i<word.length(); i++)
			set.add(word.substring(0,i)+word.substring(i+1));
	}
	
	// Just go through each letter and each 
	public static void deltaLet(String word, char[] alpha, TreeSet<String> set) {
		for (int i=0; i<word.length(); i++) {
			for (int j=0; j<alpha.length; j++) {
				if (alpha[j] == word.charAt(i)) continue;
				set.add(word.substring(0,i)+alpha[j]+word.substring(i+1));		
			}
		}
	}
	
}