// Arup Guha
// 11/11/2019
// Solution to 2019 SER D1 Problem: Maze

import java.util.*;
import java.io.*;

public class maze {

	final public static int[] DX = {-1,-1,-1,0,0,1,1,1};
	final public static int[] DY = {-1,0,1,-1,1,-1,0,1};
	
	public static int r;
	public static int c;
	public static char[][] grid;
	
	public static void main(String[] args) throws Exception {
	
		// Read input original grid size, but add border.
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(stdin.readLine());
		r = Integer.parseInt(tok.nextToken())+2;
		c = Integer.parseInt(tok.nextToken())+2;
		
		// Create grid, filling border with '.'
		grid = new char[r][c];
		Arrays.fill(grid[0], '.');
		Arrays.fill(grid[r-1],'.');
		
		// Finish reading and copying in the grid.
		for (int i=1; i<r-1; i++) {
			grid[i][0] = '.';
			char[] tmp = stdin.readLine().toCharArray();
			for (int j=1; j<c-1; j++)
				grid[i][j] = tmp[j-1];
			grid[i][c-1] = '.';
		}
		
		// Count big regions.
		int numR = 0;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (grid[i][j] == '.') {
					floodfill(i, j);
					numR++;
				}
			}
		}
		
		// Now look for diamonds.
		for (int i=1; i<=r-2; i++) {
			for (int j=1; j<=c-2; j++) {
				if (grid[i][j] == '/' && grid[i][j+1] == '\\' &&
				    grid[i+1][j] == '\\' && grid[i+1][j+1] == '/') 
						numR++;
			}
		}
		
		// Ta da!
		System.out.println(numR-1);
	}
	
	public static void print() {
		for (int i=0; i<r; i++)
			System.out.println(new String(grid[i]));
	}
	
	public static void floodfill(int x, int y) {
		
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.offer(2000*x+y);
		
		// Run BFS.
		while (q.size() > 0) {
		
			// Dequeue and fill.
			int cur = q.poll();
			x = cur/2000;
			y = cur%2000;
			grid[x][y] = 'x';
		
			// Add neighbors to queue.
			for (int i=0; i<DX.length; i++) {
			
				// Don't go out of bounds...
				int nX = x + DX[i];
				int nY = y + DY[i];
				if (!inbounds(nX, nY)) continue;
				
				// Only fill dots.
				if (grid[nX][nY] != '.') continue;
				
				// Don't cross a diagonal wall.
				int sD = DX[i]+DY[i];
				if (sD == 0 && grid[nX][y] == '\\' && grid[x][nY] == '\\') continue;
				if ( (sD==-2 || sD==2) && grid[nX][y] == '/' && grid[x][nY] == '/') continue;
			
				// Safe if we get here.
				q.offer(nX*2000+nY);
				grid[nX][nY] = 'x';
			}
		}
	}
	
	public static boolean inbounds(int x, int y) {
		return x >= 0 && x < r && y >= 0 && y < c;
	}
}