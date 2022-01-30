// Arup Guha
// 11/18/2019
// Solution to 2019 SER D1 Problem: One of Each

import java.util.*;
import java.io.*;

public class oneofeach {

	public static int n;
	public static int k;
	public static int[] vals;
	public static ArrayList[] indexes;
	
	public static void main(String[] args) throws Exception {
	
		// Read input...
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(stdin.readLine());
		n = Integer.parseInt(tok.nextToken());
		k = Integer.parseInt(tok.nextToken());
		
		// I store each number, its max index and a lists for 1 to k of where
		// each number is.
		indexes = new ArrayList[k+1];
		for (int i=0; i<=k; i++) indexes[i] = new ArrayList<Integer>();
		vals = new int[n];
		int[] maxIdx = new int[k+1];
		Arrays.fill(maxIdx, -1);
		
		// Here is where I store the numbers, their max indexes and where each is.
		for (int i=0; i<n; i++) {
			vals[i] = Integer.parseInt(stdin.readLine());
			maxIdx[vals[i]] = i;
			indexes[vals[i]].add(i);
		}
		
		// Now sort by last index of each value.
		item[] list = new item[k];
		for (int i=0; i<k; i++)
			list[i] = new item(i+1, maxIdx[i+1]);
		Arrays.sort(list);
		
		// Our minimum segment tree.
		IntTree segTree = new IntTree(0, n-1);
		for (int i=0; i<n; i++)
			segTree.change(i,i,vals[i]);
		
		// Store result and who is used here.
		boolean[] used = new boolean[k+1];
		ArrayList<Integer> sol = new ArrayList<Integer>();
		int lowIdx = 0;
		
		// Iterate through items in order of last appearance.
		for (int i=0; i<k; i++) {
			
			// Placed this already.
			if (used[list[i].value]) continue;
			
			// Go through and grab as many mins before this value as possible.
			while (lowIdx <= list[i].highI) {
				
				// Get the min at or before me.
				int[] tmp = segTree.query(lowIdx, list[i].highI);
				
				// Add if not used.
				if (!used[tmp[0]]) {
					sol.add(tmp[0]);
					used[tmp[0]] = true;
					
					// We add n to each of these so they are non-factors for future queries.
					for (Integer x : ((ArrayList<Integer>)indexes[tmp[0]]) )
						segTree.change(x,x,n);
				}
				
				// Our new lowest index to pull from.
				lowIdx = tmp[1]+1;
				
				// We're done since we added our critical value.
				if (tmp[0] == list[i].value) break;
			}
		}
		
		// Coalesce and print.
		StringBuffer sb = new StringBuffer();
		sb.append(""+sol.get(0));
		for (int i=1; i<k; i++)
			sb.append(" "+sol.get(i));
		System.out.println(sb);
	}
}

// Just to store by last index of appearance.
class item implements Comparable<item> {
	
	public int value;
	public int highI;
	
	public item(int v, int i) {
		value = v;
		highI = i;
	}
	
	public int compareTo(item other) {
		return highI - other.highI;
	}
}

/*** Min seg tree which returns both the minimum in a segment and the earliest index
     within that segment the minimum is stored.
***/
class IntTree {

	// Stores range for this node.
	public int low;
	public int high;

	// Stores aggregate data for this node.
	public int delta;
	public int value;
	public int minIdx;

	// Pointers to children.
	public IntTree left;
	public IntTree right;

	// Creates an interval tree from myLow to myHigh, inclusive.
	public IntTree(int myLow, int myHigh) {

		low = myLow;
		high = myHigh;
		delta = 0;
		value = 0;
		minIdx = myLow;

		// Lowest level.
		if (low == high) {
			left = null;
			right = null;
		}

		// Must create more nodes.
		else {
			int mid = (low+high)/2;
			left = new IntTree(low, mid);
			right = new IntTree(mid+1, high);
		}
	}

	// Propagates a change down to child nodes.
	public void prop() {

		// Recursive case, push down.
		if (left != null) {
			left.delta += delta;	
			right.delta += delta;	
			delta = 0;
		}

		// I put this in, seems to make sense.
		else {
			value += delta; 
			delta = 0;
		}
	}

	// Pre-condition: delta is 0.
	public void update() {
		if (left != null) {
			if (left.value+left.delta <= right.value+right.delta) {
				value = left.value+left.delta;
				minIdx = left.minIdx;
			}
			else {
				value = right.value+right.delta;
				minIdx = right.minIdx;
			}
		}
	}

	// Changes the values in the range [start, end] by "adding" extra.
	public void change(int start, int end, int extra) {

		// Out of range.
		if (high < start || end < low) return;

		// Push down delta.
		prop();

		// Whole range must be updated.
		if (start <= low && high <= end) {
			delta += extra;		
			update();
			return;
		}

		// Portions of children have to be changed instead.
		left.change(start, end, extra);
		right.change(start, end, extra);
		update();
	}

	public int[] query(int start, int end) {

		// Out of range.
		if (high < start || end < low) return  new int[]{1000000,1000000}; 

		// Whole range must be returned;
		if (start <= low && high <= end) {
			return new int[]{value + delta, minIdx};
		}

		// Get answers from both potions.
		prop();
		int[] leftSide = left.query(start, end);
		int[] rightSide = right.query(start, end);
		update();
		
		// left wins the tie-breaker.
		if (leftSide[0] <= rightSide[0]) 
			return leftSide;
		else 
			return rightSide;
	}
}