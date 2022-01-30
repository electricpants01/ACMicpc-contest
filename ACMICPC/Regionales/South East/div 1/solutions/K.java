// Arup Guha
// 3/22/2020
// Solution to 2019 SER Problem: Windmill Pivot

import java.util.*;

public class windmill {

	public static int n;
	public static pt[] list;
	public static int[][] maps;
	
	public static void main(String[] args) {
	
		// Read in the points.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		list = new pt[n];
		for (int i=0; i<n; i++) {
			long x = stdin.nextLong();
			long y = stdin.nextLong();
			list[i] = new pt(x, y, i);
		}
		
		// These will be used for quick reference into our sorted lists of points.
		maps = new int[n][n];
		for (int i=0; i<n; i++) Arrays.fill(maps[i], -1);
		
		// Store all lists here. allLists[i] uses reference point i as pivot.
		pt[][] allLists = new pt[n][n-1];
		for (int i=0; i<n; i++) {
		
			// Set reference point.
			pt.refX = list[i].x;
			pt.refY = list[i].y;
			
			// Copies in each item except for list[i].
			int idx = 0;
			for (int j=0; j<n; j++) {
				if (j == i) continue;
				allLists[i][idx] = new pt(list[j]);
				allLists[i][idx].setAngle();
				idx++;
			}
			
			// Now we sort this list using list[i] as the reference point!
			Arrays.sort(allLists[i]);
			
			// Mapping the original index of this point to j, its sorted index.
			for (int j=0; j<n-1; j++)
				maps[i][allLists[i][j].id] = j;
		}
		
		// Possible states are (i, j). i is reference pt, j is nearest pt, clockwise.
		boolean[][] used = new boolean[n][n];
		int res = 0;
		
		// Try my search from all states.
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				
				// Either an invalid state or we've searched this state before.
				if (i == j || used[i][j]) continue;
				
				// We'll use these to keep track of where we are.
				int curI = i, curJ = j;
				
				// Calculate how much I've rotated so far.
				double rotate = 0;
				
				// Store promotions here for this cycle.
				HashMap<Integer,Integer> promotions = new HashMap<Integer,Integer>();
				
				// Now, we simulate the windmill process from state (i, j).
				while (true) {
					
					// Mark it!
					used[curI][curJ] = true;
					
					// Where I am.
					int where = maps[curI][curJ];
					
					// Closest pt before me, ie clockwise.
					int prev = (where-1+n-1)%(n-1);
					
					// Add the rotated angle.
					pt nextPt = allLists[curI][prev];
					pt curPt = allLists[curI][where];
					double angle = curPt.angle - nextPt.angle;

					// This isn't supposed to happen, so this means that we've wrapped 
					// around by pi because of my adjusted  angle scheme.
					if (angle < 0) angle += Math.PI;
					
					// Add in this angle.
					rotate += Math.abs(angle);
					
					// Promoted point. 
					int next = allLists[curI][prev].id;
					
					// Update map for new point.
					if (!promotions.containsKey(next)) {
						promotions.put(next, 1);
						res = Math.max(res, 1);
					}
					
					// Or for previously promoted point.
					else {
						int tmp = promotions.get(next) + 1;
						promotions.put(next, tmp);
						res = Math.max(res, tmp);
					}
					
					// Update these two.
					int saveCurI = curI;
					curI = next;
					curJ = saveCurI;
					
					// Here is how we get out.
					if (used[curI][curJ]) break;
				}
				
				// Trick case where we only went half way around.
				if (Math.abs(rotate - Math.PI) < 1e-9) {
					for (Integer x: promotions.keySet())
						res = Math.max(res, 2*promotions.get(x));
				}
				
			} // end j
		} // end i
		
		// Ta da!
		System.out.println(res);
	}	
}

class pt implements Comparable<pt> {

	public int id;
	public long x;
	public long y;
	public double angle;
	public double realAngle;
	
	public static long refX;
	public static long refY;
	
	public pt(long myx, long myy, int myid) {
		id = myid;
		x = myx;
		y = myy;
		angle = 0;
	}
	
	public pt(pt other) {
		id = other.id;
		x = other.x;
		y = other.y;
		angle = 0;
	}
	
	// Sets both the real angle and the adjusted angle.
	public void setAngle() {
		realAngle = regAtan2();
		angle = realAngle < 0 ? realAngle + Math.PI : realAngle;
	}
	
	// Returns the atan2 angle formed from the reference pt to this pt.
	public double regAtan2() {
		return Math.atan2(y-refY, x-refX);
	}
	
	// Just do it based on atan2 angle, adjusted. I think this is precise enough...we'll find out =)
	public int compareTo(pt other) {
		if (angle < other.angle) return -1;
		if (other.angle < angle) return 1;
		return 0;
	}
}