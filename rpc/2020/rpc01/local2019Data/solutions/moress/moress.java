// Arup Guha
// 8/14/2019
// Solution to 2019 UCF Locals Problem: More or Less

import java.util.*;

public class moress {
	
	final public static boolean DEBUG = false;

	// Possible values for relational arrays.
	final public static int UNDEF = 0;
	final public static int GT = 1;
	final public static int LT = 2;
	
	// Stores the board and # of solutions.
	public static int n;
	public static int[][] board;
	
	// Stores the relationship between squares.
	public static int[][] rowsRel;
	public static int[][] colsRel;
	
	public static void main(String[] args) {
	
		// Set up all of my arrays.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		board = new int[n][n];
		rowsRel = new int[n][n-1];
		colsRel = new int[n-1][n];
		
		// Loop through number rows.
		for (int i=0; i<n; i++) {
			
			// Read line.
			char[] line = stdin.next().toCharArray();
			
			// Go through chars.
			for (int j=0; j<2*n-1; j+=2) {
				
				// Assign only if it's a number.
				if (line[j] != '-') board[i][j/2] = line[j]-'0';
				
				// No last relative char.
				if (j == 2*n-2) break;
				
				// Assign relational operator if necessary.
				if (line[j+1] == '>') rowsRel[i][j/2] = GT;
				if (line[j+1] == '<') rowsRel[i][j/2] = LT;
			}
			
			// No even row at the end.
			if (i == n-1) break;
			
			// Read line.
			line = stdin.next().toCharArray();
			
			// Go through chars, assign relational operator if necessary.
			for (int j=0; j<2*n-1; j+=2) {
				if (line[j] == 'v') colsRel[i][j/2] = GT;
				if (line[j] == '^') colsRel[i][j/2] = LT;
			}			
		}
		
		// Start it!
		int sols = go(0);
		if (DEBUG) System.out.println("Had "+sols+" number of solutions");
	}
	
	// Prints the current state of the board.
	public static void printSol() {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++)
				System.out.print(board[i][j]);
			System.out.println();
		}
	}
	
	// Returns the number of solutions given what's in board for the first k items, and prints each.
	public static int go(int k) {
		
		// We have a solution. Print and return that we have 1.
		if (k == n*n) {
			printSol();
			return 1;
		}
		
		// Square is forced, go to the next.
		if (board[k/n][k%n] != 0) return go(k+1);
		
		int numSols = 0;
		
		// Try each number in the current slot.
		for (int i=1; i<=n; i++) {
			
			// We've used this number already.
			if (inRow(k/n,i) || inCol(k%n,i)) continue;
			
			// A trick to make my checking easier.
			board[k/n][k%n] = i;
			
			// A row relationship would be invalid.
			if (invalidRow(k-1,i) || invalidRow(k,i)) { board[k/n][k%n] = 0; continue; }
			
			// A column relationship would be invalid.
			if (invalidCol(k-n,i) || invalidCol(k,i)) { board[k/n][k%n] = 0; continue; }
			
			// Try i in this slot and recurse.
			numSols += go(k+1);
			board[k/n][k%n] = 0;
		}
		
		// # of solutions we got.
		return numSols;
	}
	
	// Returns true iff placing val in slot makes slot and slot+1 an invalid row relationship.
	public static boolean invalidRow(int slot, int val) {
		
		// Nothing for right most column.
		if (slot%n == n-1 || slot < 0) return false;
		
		// No relation is given.
		if (rowsRel[slot/n][slot%n] == UNDEF) return false;
		
		// Can't count incomplete comparison.
		if (board[slot/n][slot%n] == 0 || board[slot/n][slot%n+1] == 0) return false;
		
		// greater than not respected.
		if (rowsRel[slot/n][slot%n] == GT && board[slot/n][slot%n] <= board[slot/n][slot%n+1]) return true;
		
		// less than not respected.
		if (rowsRel[slot/n][slot%n] == LT && board[slot/n][slot%n] >= board[slot/n][slot%n+1]) return true;		
		
		// If we get here this check isn't invalid.
		return false;
	}
	
	// Returns true iff placing val in slot makes slot and slot+n an invalid column relationship.
	public static boolean invalidCol(int slot, int val) {
		
		// Nothing for bottom column.
		if (slot < 0 || slot/n == n-1) return false;
		
		// No relation is given.
		if (colsRel[slot/n][slot%n] == UNDEF) return false;
		
		// Can't count incomplete comparison.
		if (board[slot/n][slot%n] == 0 || board[slot/n+1][slot%n] == 0) return false;
		
		// greater than not respected.
		if (colsRel[slot/n][slot%n] == GT && board[slot/n][slot%n] <= board[slot/n+1][slot%n]) return true;
		
		// less than not respected.
		if (colsRel[slot/n][slot%n] == LT && board[slot/n][slot%n] >= board[slot/n+1][slot%n]) return true;		
		
		// If we get here this check isn't invalid.
		return false;
	}	
	
	// Returns true iff val is in row r.
	public static boolean inRow(int r, int val) {
		for (int j=0; j<n; j++)
			if (board[r][j] == val)
				return true;
		return false;
	}
	
	// Returns true iff val is in col c.
	public static boolean inCol(int c, int val) {
		for (int i=0; i<n; i++)
			if (board[i][c] == val)
				return true;
		return false;
	}
}
