// Arup Guha
// 12/1/2019
// Solution to 2019 SER D1/D2 Problem: Elven Efficiency 
// (3.77 sec on laptop for slowest case, 5 sec TL)

import java.util.*;
import java.io.*;

public class elven {

	final public static int MAX = 300300;
	
	public static void main(String[] args) throws Exception {
	
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(stdin.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int rounds = Integer.parseInt(tok.nextToken());
	
		// Read in these values, keep in groups by frequency.
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		for (int i=0; i<n; i++) {
			int x = Integer.parseInt(stdin.readLine().trim());
			if (map.containsKey(x))
				map.put(x, map.get(x)+1);
			else
				map.put(x, 1);
		}
		
		// links[i] will store links to all active items that i divides into.
		HashSet[] links = new HashSet[MAX];
		for (int i=0; i<MAX; i++)
			links[i] = new HashSet<Integer>();
		
		// A pre-comped divisor list.
		ArrayList[] divisors = new ArrayList[MAX];
		for (int i=0; i<MAX; i++)
			divisors[i] = new ArrayList<Integer>();
		for (int i=2; i<MAX; i++) {
			for (int j=1; j*j<=i; j++) {
				if (i%j != 0) continue;
				divisors[i].add(j);
				if (i/j > j) divisors[i].add(i/j);
			}
		}
			
		// Build our first set of links to be accurate to our input list.
		for (Integer x: map.keySet()) {
			
			// For each divisor of x, add x.
			for (int i=2; i*i<=x; i++) {
				if (x%i != 0) continue;
				links[i].add(x);
				if (x/i > i) links[x/i].add(x);
			}
			links[x].add(x);
		}
		
		long res = 0;
		
		// Do each round.
		for (int i=0; i<rounds; i++) {
			
			// Number called.
			int x = Integer.parseInt(stdin.readLine().trim());
			
			// All the values that must be changed.
			ArrayList<Integer> tmp = new ArrayList<Integer>();
			for (Integer y: (HashSet<Integer>)links[x]) tmp.add(y);
			for (Integer y: tmp) {
				
				// Get number to be moved, add to count.
				int freq = map.get(y);
				res += freq;
				
				// Remove from our map.
				map.remove(y);
				
				// Get rid of these for efficiency.
				// Go to y's divisors and remove all.
				for (Integer z: (ArrayList<Integer>)divisors[y])
					links[z].remove(y);
				
				// Update y+1, which is where these will be.
				if (map.containsKey(y+1)) 
					map.put(y+1, map.get(y+1) + freq);
				else 
					map.put(y+1, freq);

				// Add these in.
				for (Integer z: (ArrayList<Integer>)divisors[y+1]) 
					links[z].add(y+1);				
			}
		}
		
		// Ta da!
		System.out.println(res);
	}
}