// Arup Guha
// 12/20/2019
// Solution to 2019 SER D1 Problem: Computer Cache

import java.util.*;
import java.io.*;

public class cache {

	public static int nCache;
	public static int numData;
	public static int numOps;
	public static int[][] initData;
	public static int[] dataLen;
	public static int[] startData;
	public static int[][] transcript;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(stdin.readLine());
		nCache = Integer.parseInt(tok.nextToken());
		numData = Integer.parseInt(tok.nextToken());
		numOps = Integer.parseInt(tok.nextToken());
		
		// Start reading in data.
		initData = new int[numData][];
		dataLen = new int[numData];
		for (int i=0; i<numData; i++) {
			tok = new StringTokenizer(stdin.readLine());
			dataLen[i] = Integer.parseInt(tok.nextToken());
			initData[i] = new int[dataLen[i]];
			for (int j=0; j<dataLen[i]; j++)
				initData[i][j] = Integer.parseInt(tok.nextToken());
		}
		
		// Just read the transcript w/o doing anything so we can pre-comp if we need.
		transcript = new int[numOps][4];
		int[] numArgs = {0,2,1,3};
		for (int i=0; i<numOps; i++) {
			tok = new StringTokenizer(stdin.readLine());
			transcript[i][0] = Integer.parseInt(tok.nextToken());
			for (int j=0; j<numArgs[transcript[i][0]]; j++)
				transcript[i][j+1] = Integer.parseInt(tok.nextToken());
		}
		
		// Essentially a cumulative frequency array, so I know where each data will
		// start in my seg tree.
		startData = new int[numData+1];
		for (int i=0; i<numData; i++)
			startData[i+1] = startData[i] + dataLen[i];
		
		// Will store which statement made the update for each print.
		int[] whichStmt = new int[numOps];
		Arrays.fill(whichStmt, -1);
		
		// if a load i affects a print j, then whoThisAffects[i] will contain j.
		ArrayList[] whoThisAffects = new ArrayList[numOps+1];
		for (int i=0; i<numOps; i++) whoThisAffects[i] = new ArrayList<Integer>();
		
		// Note: I am making the transcript numbers stored 1-based!!!
		IntTreeAbs updateTree = new IntTreeAbs(1, nCache);
		for (int i=0; i<numOps; i++) {
			
			// An update by statement i.
			if (transcript[i][0] == 1) {
				updateTree.change(transcript[i][2], transcript[i][2]+dataLen[transcript[i][1]-1]-1, i+1);
			}
			
			// Figure out who affected i, and at it's time location store i to tell
			// us to evaluate that print at that time.
			else if (transcript[i][0] == 2) {
				int stmt = updateTree.query(transcript[i][1]);
				whoThisAffects[stmt].add(i+1);
			}
			
		}
		
		// Set up our data.
		IntTree dataTree = new IntTree(0,startData[numData]-1);
		int idx = 0;
		for (int i=0; i<initData.length; i++)
			for (int j=0; j<initData[i].length; j++)
				dataTree.change(startData[i]+j, startData[i]+j, initData[i][j]);
			
		// Will store final answers here but print them at the end.
		int[] res = new int[numOps];
		
		// Now we can simulate and store our answers.
		for (int i=0; i<numOps; i++) {
			
			// Update the data!
			if (transcript[i][0] == 3) {
				int dataIdx = transcript[i][1]-1;
				int left = transcript[i][2]-1;
				int right = transcript[i][3]-1;
				dataTree.change(startData[dataIdx]+left, startData[dataIdx]+right, 1);
			}
			
			// This was a load that might affect prints.
			else if (transcript[i][0] == 1) {
				
				// See everyone this affects, and then query and store the results.
				for (Integer x: (ArrayList<Integer>)whoThisAffects[i+1]) {
					int zeroIdxData = transcript[x-1][1] - transcript[i][2];
					int whichData = transcript[i][1]-1;
					int dataLoc = startData[whichData]+zeroIdxData;
					res[x-1] = dataTree.query(dataLoc, dataLoc)%256; 
				}
			}
		}
		
		// Store answer here.
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<numOps; i++) 
			if (transcript[i][0] == 2)
				sb.append(res[i]+"\n");
			
		// Ta da!
		System.out.print(sb);
	}
}

/*** My Segment Tree for doing absolute changes...this is probably weird as I just kinda
     figured it out on my own instead of modifying a real seg tree. In fact, I can only doing
	 point queries with this.
***/
class IntTreeAbs {

	// Stores range for this node.
	public int low;
	public int high;

	// Stores aggregate data for this node.
	public boolean allSet;
	public int value;

	// Pointers to children.
	public IntTreeAbs left;
	public IntTreeAbs right;

	// Creates an interval tree from myLow to myHigh, inclusive.
	public IntTreeAbs(int myLow, int myHigh) {

		low = myLow;
		high = myHigh;
		allSet = true;
		value = 0; 

		// Lowest level.
		if (low == high) {
			left = null;
			right = null;
		}

		// Must create more nodes.
		else {
			int mid = (low+high)/2;
			left = new IntTreeAbs(low, mid);
			right = new IntTreeAbs(mid+1, high);
		}
	}
	
	// Pushes down a true value to lower nodes.
	public void prop() {

		// Recursive case, push down.
		if (left != null) {
			left.allSet = true;
			left.value = value;
			right.allSet = true;
			right.value = value;
		}
	}		
	
	// Updates - if both nodes below are the same, I update me.
	public void update() {
		if (left != null) {
			if (left.allSet && right.allSet && left.value == right.value) {
				value = left.value;
				allSet = true;
			}
		}
	}

	// Changes the values in the range [start, end] to newval.
	public void change(int start, int end, int newval) {

		// Out of range.
		if (high < start || end < low) return;

		// Whole range must be updated.
		if (start <= low && high <= end) {
			value = newval;
			allSet = true;
			return;
		}
		
		// I only prop if we are making a change in a node that's true.
		if (allSet)
			prop();

		// Portions of children have to be changed instead.
		allSet = false;
		left.change(start, end, newval);
		right.change(start, end, newval);
		
		// Just in case!
		update();
	}

	public int query(int idx) {
		if (allSet) return value;
		return idx < right.low ? left.query(idx) : right.query(idx);
	}
}

/*** My old seg tree for sum ***/
class IntTree {

	// Stores range for this node.
	public int low;
	public int high;

	// Stores aggregate data for this node.
	public int delta;
	public int value;

	// Pointers to children.
	public IntTree left;
	public IntTree right;

	// Creates an interval tree from myLow to myHigh, inclusive.
	public IntTree(int myLow, int myHigh) {

		low = myLow;
		high = myHigh;
		delta = 0;
		value = 0; 

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
		if (left != null)
			value = left.value+left.delta*(left.high-left.low+1)+right.value+right.delta*(right.high-right.low+1); /*** Can change ***/
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

	public int query(int start, int end) {

		// Out of range.
		if (high < start || end < low) return 0; 

		// Whole range must be returned;
		if (start <= low && high <= end) {
			return value + delta*(high-low+1);
		}

		// Get answers from both potions.
		prop();
		int leftSide = left.query(start, end);
		int rightSide = right.query(start, end);
		update();
		return leftSide+rightSide;
	}
}