// Arup Guha
// 8/21/2019
// Alternate Solution for 2019 UCF Locals Problem: Mountain View

// This solution uses a ternary search extending both left and right over all
// necessary intervals of segments. 

// It's fairly hacky...I am convinced there is a much cleaner way to write this same idea.

import java.util.*;

public class view_binsearch {

	public static int n;
	public static long[] x;
	public static long[] y;
	public static long w;
	
	public static void main(String[] args) {
	
		// Using slow scanning intentionally to allow this for contestants.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		w = stdin.nextInt();
		x = new long[n];
		y = new long[n];
		
		// Read in the points.
		for (int i=0; i<n; i++) {
			x[i] = stdin.nextLong();
			y[i] = stdin.nextLong();
		}
		
		// Get best answer of pictures that start at a left post.
		double area = solveFromLeft();
		
		// Flip order of the segments, so that we "reverse" the skyline.
		long maxx = x[n-1];
		for (int i=0; i<n; i++)
			x[i] = maxx-x[i];
		rev(x);
		rev(y);
		
		// After flipping, we're now really solving the problem for all pictures that
		// end at a right post.
		area = Math.max(area, solveFromLeft());
		
		// Ta da!
		System.out.println(area/w);
	}
	
	// Reverses the array a.
	public static void rev(long[] a) {
		for (int i=0; i<a.length/2; i++) {
			long tmp = a[i];
			a[i] = a[a.length-1-i];
			a[a.length-1-i] = tmp;
		}		
	}
	
	public static double solveFromLeft() {
		
		double res = 0;
		
		// Stores cumulative double area from beginning segment to current one.
		long[] dCumArea = new long[n];
		for (int i=1; i<n; i++)
			dCumArea[i] = (x[i]-x[i-1])*(y[i]+y[i-1]);
		for (int i=1; i<n; i++)
			dCumArea[i] += dCumArea[i-1];
		
		// Sweep here.
		int lowI = 0, highI = 0;
		while (lowI < n) {
			
			// Update highI so that the interval is the largest we can extend to the right.
			while (highI < n && x[highI]-x[lowI] <= w) highI++;
			highI--;
			
			// Area & width of all the complete trapezoids.
			double curArea = dCumArea[highI] - dCumArea[lowI];
			long curWidth = x[highI] - x[lowI];
			long leftover = w-curWidth;
			
			// Case 1: Whole thing fits!
			if (lowI == 0 && highI == n-1) {
				res = dCumArea[highI] - dCumArea[lowI];
			}
			
			// Case 2: Extend to right only. 
			if (highI < n-1) {
				double goRight = curArea + partialDoubleAreaRight(leftover, highI);
				res = Math.max(res, goRight);
			}
			
			// Case 3: Extend to left only.
			if (lowI > 0)  {			
				double goLeft = curArea + partialDoubleAreaLeft(Math.min(leftover, x[lowI]-x[lowI-1]), lowI);
				res = Math.max(res, goLeft);
			}
			
			// Case 4 & 5: We can seek both left and right, for both [lowI, highI] and [lowI+1, highI].
			if (highI < n-1) {
				
				// This is the offset from our current lowI.
				for (int delta=0; delta<2; delta++) {
					int tmpI = lowI + delta;
					if (tmpI == 0) continue;
					double maxAdd = 0;
					
					// Got to redo all this stuff, since it might not be with lowI.
					curArea = dCumArea[highI] - dCumArea[tmpI];
					curWidth = x[highI] - x[tmpI];
					leftover = w-curWidth;
					long maxRight = x[highI+1]-x[highI];
					
					// Bound highLeft is obvious - can't do more thanthe segment extends or leftover.
					// Bound lowLeft is more tricky, we get it by using the maximum on the right.
					double lowLeft = Math.max(0, leftover - maxRight), highLeft = Math.min(leftover, x[tmpI]-x[tmpI-1]);
					
					// Trying 100 iterations.
					for (int i=0; i<100; i++) {
						
						// Find extra area for lower cut.
						double cut1 = (2*lowLeft+highLeft)/3;
						double addThirdArea = partialDoubleAreaLeft(cut1, tmpI) + partialDoubleAreaRight(Math.min(leftover-cut1,x[highI+1]-x[highI]), highI);
						
						// And upper cut.
						double cut2 = (lowLeft+2*highLeft)/3;
						double addTwoThirdArea = partialDoubleAreaLeft(cut2, tmpI) + partialDoubleAreaRight(Math.min(leftover-cut2,x[highI+1]-x[highI]), highI);
						
						// Safe to move low pointer.
						if (addThirdArea > addTwoThirdArea) {
							highLeft = cut2;
							maxAdd = Math.max(maxAdd, addThirdArea);
						}
						
						// Safe to move high pointer.
						else {
							lowLeft = cut1;
							maxAdd = Math.max(maxAdd, addTwoThirdArea);
						}
					}
					
					// Update if this is better.
					res = Math.max(res, curArea+maxAdd);
				}
			}
			
			// No point in continuing.
			if (highI >= n-1) break;
			
			// Go to next starting segment.
			lowI++;
		}
		
		// Ta da - don't forget to divide by 2!!!
		return res/2.0;
	}
	
	// Returns the area of the trapezoid starting on segment idx, but with the given
	// width, width, which is shorter than the complete trapezoid originally given.
	public static double partialDoubleAreaRight(double width, int idx) {
		long dy = y[idx+1]-y[idx];
		double cury = y[idx] + dy*width/(x[idx+1]-x[idx]);
		return width*(y[idx]+cury);
	}
	
	// Returns the area to the left of segment idx with the specified width.
	public static double partialDoubleAreaLeft(double width, int idx) {
		long dy = y[idx-1] - y[idx];
		double cury = y[idx] + dy*width/(x[idx]-x[idx-1]);
		return width*(y[idx]+cury);
	}
}