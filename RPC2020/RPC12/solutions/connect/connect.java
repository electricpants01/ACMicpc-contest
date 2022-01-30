// Arup Guha
// 9/12/2020
// Solution to 2020 UCF Locals Final Round Problem: Making Connections

import java.util.*;

public class connect {

	public static void main(String[] args) {
	
		// Get basic input.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int numQ = stdin.nextInt();
		
		// Set up disjoint set.
		djset dj = new djset(n);
		
		// Process queries.
		for (int i=0; i<numQ; i++) {
		
			// Grab command.
			int cmd = stdin.nextInt();
			
			// We just do a union in the disjoint set here.
			if (cmd == 1) {
				int u = stdin.nextInt()-1;
				int v = stdin.nextInt()-1;
				dj.union(u,v);
			}
			
			// We can just use the disjoint set to answer the query.
			else {
				long div = gcd(dj.sumSq, dj.numC);
				System.out.println((dj.sumSq/div)+"/"+(dj.numC/div));
			}
		}
	}
	
	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a%b);
	}
}

class djset {

	public int n;
	public int[] height;
	public int[] par;
	public long[] size;
	public long sumSq;
	public int numC;
	
	// Constructor - start keeping track of sum of squares, number of components.
	public djset(int myn) {
		n = myn;
		par = new int[n];
		height = new int[n];
		size = new long[n];
		for (int i=0; i<n; i++) {
			par[i] = i;
			size[i] = 1;
			height[i] = 0;
		}
		sumSq = n;
		numC = n;
	}
	
	// Finds the root of the tree of u. No path compression to make size calculation easier.
	public int root(int u) {
		if (par[u] == u) return u;
		return root(par[u]);
	}
	
	public boolean union(int u, int v) {
	
		// Get roots.
		u = root(u);
		v = root(v);
	
		// No work to be done.
		if (u == v) return false;
		
		// We will make v's parent u.
		if (height[v] < height[u] ) {
			par[v] = u;
			sumSq = sumSq - size[u]*size[u] - size[v]*size[v] + (size[u]+size[v])*(size[u]+size[v]);
			size[u] += size[v];
		}
		
		// Here we make u's parent v.
		else {
			par[u] = v;
			sumSq = sumSq - size[u]*size[u] - size[v]*size[v] + (size[u]+size[v])*(size[u]+size[v]);
			size[v] += size[u];
			height[v] = Math.max(height[v], height[u]+1);
		}
			
		// This is always true.
		numC--;
		
		// Did it!
		return true;
	}
}