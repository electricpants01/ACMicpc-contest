// Arup Guha
// 11/9/2019
// Solution to 2019 SER D2 Problem: Checkerboard

import java.util.*;

public class checkerboard {

	public static void main(String[] args) {
	
		// Get input.
		Scanner stdin = new Scanner(System.in);
		int r = stdin.nextInt();
		int c = stdin.nextInt();
		int v = stdin.nextInt();
		int h = stdin.nextInt();
		
		// Get Vertical splits.
		int[] vSplit = new int[v];
		for (int i=0; i<v; i++)
			vSplit[i] = stdin.nextInt();
		
		// Get horizontal splits.
		int[] hSplit = new int[h];
		for (int i=0; i<h; i++)
			hSplit[i] = stdin.nextInt();
			
		// Expand this.
		boolean[] horiz = new boolean[c];
		boolean tmp = false;
		int idx = 0;
		for (int i=0; i<h; i++) {
			for (int j=0; j<hSplit[i]; j++)
				horiz[idx++] = tmp;
			tmp = !tmp;
		}
		
		// Flip it.
		boolean[] oppHoriz = new boolean[c];
		for (int i=0; i<c; i++) oppHoriz[i] = !horiz[i];
		
		// Black = false...
		boolean[][] grid = new boolean[r][c];
		
		// Now, just copy the appropriate row from either horiz or oppHoriz.
		idx = 0;
		for (int i=0; i<v; i++) 
			for (int j=0; j<vSplit[i]; j++)
				grid[idx++] = i%2 == 0 ? horiz : oppHoriz;
				
		// Print grid.
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (grid[i][j])
					System.out.print("W");
				else
					System.out.print("B");
			}
			System.out.println();
		}
	}
}