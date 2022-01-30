// Arup Guha
// 8/20/2019
// Solution to 2019 UCF Locals Problem: Mountain View

import java.util.*;

public class view {
	
	final public static double EPS = 1e-9;

	public static int n;
	public static long[] x;
	public static long[] y;
	public static long[] dx;
	public static long[] dy;
	public static double[] slopes;
	public static long w;
	public static long[] dCumArea;
	
	public static void main(String[] args) {
	
		// Using slow scanning intentionally to allow this for contestants.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		w = stdin.nextInt();
		x = new long[n];
		y = new long[n];
		dx = new long[n-1];
		dy = new long[n-1];
		slopes = new double[n-1];
		// Read in the points, also store differences.
		for (int i=0; i<n; i++) {
			x[i] = stdin.nextLong();
			y[i] = stdin.nextLong();
			if (i > 0) {
				dx[i-1] = x[i]-x[i-1];
				dy[i-1] = y[i]-y[i-1];
				slopes[i-1] = 1.0*dy[i-1]/dx[i-1];
			}
		}
		
		// Get best answer of pictures that start at a left post.
		double area = solveArea();
		System.out.printf("%.9f\n",area/w);
	}
	
	public static double solveArea() {
		
		// Stores cumulative double area from beginning segment to current one.
		dCumArea = new long[n];
		for (int i=1; i<n; i++)
			dCumArea[i] = (x[i]-x[i-1])*(y[i]+y[i-1]);
		for (int i=1; i<n; i++)
			dCumArea[i] += dCumArea[i-1];
		
		// Sweep here.
		int lowI = 0, highI = 0;
		double dLow = 0, dHigh = 0;
		double curX = x[0];
		
		// move so highI is max such that x[lowI..highI] fits in the picture.
		while (highI < n && x[highI]-x[lowI] <= w) highI++;
		highI--;
		
		// Update what's leftover.
		if (highI < n-1) dHigh = w - (x[highI]-x[lowI]);
		double res = getDoubleArea(lowI, dLow, highI, dHigh);
			
		// Sweep starts.
		while (lowI < n-1 && highI < n-1) {
			
			// Next endpoint.
			double nextLow = x[lowI+1] - x[lowI] - dLow;
			double nextHigh = x[highI+1] - x[highI] - dHigh;
			
			// Most we can move.
			double move = Math.min(nextLow, nextHigh);

			// Find out where these two lines would meet.
			Double meet = getPt(curX, lowI, dLow, highI, dHigh);
			
			// True if we have an equality point before reaching either endpoint.
			if (meet != null && meet < move) {
				dLow += meet;
				dHigh += meet;
				curX += meet;
			}
			
			// Move low ptr up.
			else if (nextLow < nextHigh) {
				lowI++;
				dLow = 0;
				curX = x[lowI];
				dHigh += nextLow;
			}
			
			// Move high ptr up.
			else {
				highI++;
				dHigh = 0;
				curX += nextHigh;
				dLow += nextHigh;
			}
			
			// Get this area and update answer, if necessary.
			double tmpDoubleArea = getDoubleArea(lowI, dLow, highI, dHigh);
			res = Math.max(res, tmpDoubleArea);
		}
		
		// Ta da - don't forget to divide by 2!!!
		return res/2.0;
	}
	
	public static Double getPt(double curX, int lowI, double dLow, int highI, double dHigh) {
		
		// Y values of our window left and right.
		double leftY = y[lowI] + dy[lowI]*(dLow/dx[lowI]);
		double rightY = y[highI] + dy[highI]*(dHigh/dx[highI]);
		
		// Parallel lines, will not help us...also we avoid div by 0.
		if (dy[highI]*dx[lowI] - dx[highI]*dy[lowI] == 0) return null;
		
		// Where they would meet.
		double tmp = (leftY-rightY)/(slopes[highI]-slopes[lowI]);
		if (tmp < EPS) return null;
		
		// This is viable.
		return new Double(tmp);
	}
	
	// Returns twice the area from index lowI (starting over dLow) to index highI going past it by dHigh.
	public static double getDoubleArea(int lowI, double dLow, int highI, double dHigh) {
		
		// Baseline estimate.
		double res = dCumArea[highI] - dCumArea[lowI];
		
		// Area added to the right of highI.
		if (dHigh > EPS) res += partialDoubleArea(dHigh, highI);
		
		// And this gets subtracted out.
		if (dLow > EPS) res -= partialDoubleArea(dLow, lowI);
		
		// Ta da!
		return res;
	}
	
	// Returns the area of the trapezoid starting on segment idx, but with the given
	// width, width, which is shorter than the complete trapezoid originally given.
	public static double partialDoubleArea(double width, int idx) {
		long dy = y[idx+1]-y[idx];
		double cury = y[idx] + dy*width/(x[idx+1]-x[idx]);
		return width*(y[idx]+cury);
	}
}
