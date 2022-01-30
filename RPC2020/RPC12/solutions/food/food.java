// Arup Guha
// 9/9/2020
// Solution to 2020 UCF Locals Final Round Problem: Food Display Arrangement

import java.util.*;

public class food {

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
		
		// Make each interval for each unique # in the list.
		int idx = 0;
		gap[] list = new gap[minMap.size()];
		for (Integer x: minMap.keySet())
			list[idx++] = new gap(minMap.get(x), maxMap.get(x));
		
		// Sort it for sweep, by end time of each gap.
		Arrays.sort(list, (gap g1, gap g2)->g1.end-g2.end);		
		int noMove = 0, end = -1;
		
		// Go through each item.
		for (int i=0; i<list.length; i++) {
			
			// We can add this interval to our answer since it starts after the last one ended.
			if (list[i].start > end) {
				noMove++;
				end = list[i].end;
			}
		}
		
		// We move everything but the items already in order that don't need to be moved.
		System.out.println(minMap.size()-noMove);
	}
}

class gap {
	
	public int start;
	public int end;
	
	public gap(int s, int e) {
		start = s;
		end = e;
	}
}
