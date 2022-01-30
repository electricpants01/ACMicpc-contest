// Arup Guha
// 3/12/2020
// Solution to 2019 SER D2 Problem: Glow Pixel Glow!

import java.util.*;
import java.io.*;

public class glow {
	
	final public static int ADD = 200010;
	
	public static void main(String[] args) throws Exception {
	
		// Read input.
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int lines = Integer.parseInt(stdin.readLine());
		
		// Stores on off events horizontally and vertically.
		int[] startF = new int[1000000];
		int[] endF = new int[1000000];
		int[][] vert = new int[200000][2];
		int numV = 0;
		
		// Read in the lines and process.
		for (int loop=0; loop<lines; loop++) {
		
			// Get line.
			StringTokenizer tok = new StringTokenizer(stdin.readLine());
			
			char dir = tok.nextToken().charAt(0);
			int t = Integer.parseInt(tok.nextToken());
			int duration = Integer.parseInt(tok.nextToken());
			int offset = Integer.parseInt(tok.nextToken());
			
			// For horizontal lines, I store when they start and when they end, so
			// These will be two cumulative frequency arrays, eventually, where
			// startF[i] stores how many pulses have started at or before adjusted time i.
			// same for endF.
			if (dir == 'h') {
				startF[-offset+t+ADD]++;
				endF[-offset+t+duration+ADD]++;
			}
			
			// I am using verticals for my queries, so I just store the same start/end data.
			else {
				
				// This is my pulse's effective starting time.
				vert[numV][0] = -offset + t + ADD;
				
				// And the starting time of the end tail of the pulse.
				vert[numV][1] = -offset + t + duration + ADD;
				
				numV++;
			}
		}
			
		// Make the horizontal data (starting and end) cumulative frequency arrays.
		for (int i=1; i<startF.length; i++) {
			startF[i] += startF[i-1];
			endF[i] += endF[i-1];
		}
			
		long res = 0;
		int numH = lines - numV;
			
		// Trick here is instead of counting all the valid intersections,
		// we will subtract all the ones that don't intersect, so no 
		// complicated range queries have to be made.
		for (int i=0; i<numV; i++) {
				
			// Pretend we hit all of them.
			res += numH;
				
			// Subtract out all of the pulses that end before my beginning gets there.
			res -= endF[vert[i][0]];
				
			// This subtracts out all of the pulses that haven't started yet when I leave.
			res -= (numH - startF[vert[i][1]-1]);
		}

		// Ta da!
		System.out.println(res);
	}	
}