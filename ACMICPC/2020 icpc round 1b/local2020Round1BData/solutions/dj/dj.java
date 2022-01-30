// Arup Guha
// 9/9/2020
// Solution to 2020 UCF Locals Round 1B Problem: Wedding DJ

import java.util.*;

public class dj {

	public static int n;
	public static int[] vals;
	
	public static void main(String[] args) {
	
		// Read the input.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		vals = new int[n];
		for (int i=0; i<n; i++)
			vals[i] = stdin.nextInt();
			
		// Maps to store min and max index for each song level.
		TreeMap<Integer,Integer> minMap = new TreeMap<Integer,Integer>();
		TreeMap<Integer,Integer> maxMap = new TreeMap<Integer,Integer>();
		
		// Go through list once to update.
		for (int i=0; i<n; i++) {
			if (!minMap.containsKey(vals[i])) minMap.put(vals[i], i);
			maxMap.put(vals[i], i);
		}
		
		// # of unique items.
		int unique = maxMap.size();
		
		// Will store ending indexes of each group.
		ArrayList<Integer> groups = new ArrayList<Integer>();
		groups.add(-1);
		
		int curMax = 0;
		
		// Go through list.
		for (int i=0; i<n; i++) {
			
			// List must extend to max index that stores vals[i] at least.
			curMax = Math.max(curMax, maxMap.get(vals[i]));
			
			// If this is true, our group has ended.
			if (curMax == i) groups.add(i);
		}
			
		// lisMin[i] will store minimum ending value of an LIS with length i.
		int[] lisMin = new int[groups.size()];
		Arrays.fill(lisMin, 1000000001);
		lisMin[0] = 0;
		curMax = 0;
		
		// Go through each group to update LIS.
		for (int i=1; i<groups.size(); i++) {
			
			// Put all song levels for this group in here.
			TreeSet<Integer> songs = new TreeSet<Integer>();
			for (int j=groups.get(i-1)+1; j<=groups.get(i); j++)
				songs.add(vals[j]);
			
			// Go through in reverse order.
			while (songs.size() > 0) {
				
				// Get last item.
				int item = songs.pollLast();
				
				// Find largest item smaller than this that we could use
				// this to build off of.
				int idx = binsearch(lisMin, item);
				
				// See if we can make a LIS of this length (idx+1) that has a smaller
				// ending value.
				lisMin[idx+1] = Math.min(lisMin[idx+1], item);
				
				// This is a valid LIS length, so update if necessary.
				curMax = Math.max(curMax, idx+1);
			}
		}
		
		// Here is our result.
		System.out.println(unique-curMax);
	}
	
	// Returns largest index storing a number < x. vals is sorted.
	public static int binsearch(int[] vals, int x) {
		
		// Binary search location.
		int low = 0, high = vals.length-1;
		while (low < high) {
			
			int mid = (low+high+1)/2;
			
			// mid is too high a guess, so reset high.
			if (vals[mid] >= x)
				high = mid-1;
			
			// Best we can do is set low to mid.
			else
				low = mid;
		}
		
		// Max index storing value < x.
		return low;
	}

}
