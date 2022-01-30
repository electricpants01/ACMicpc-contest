// Arup Guha
// 9/12/2020
// Checker for 2020 UCF Locals Problem: Lots of Towers of Hanoi

import java.util.*;
import java.io.*;

public class check_hanoi {

	public static void main(String[] args) throws Exception {
	
		// Set all of these up.
		Scanner input = new Scanner(new File(args[0]));
		Scanner teamOut = new Scanner(new File(args[1]));
		//Scanner judgeOut = new Scanner(args[2]);
		
		// Get input.
		int k = input.nextInt();
		int s = input.nextInt()-1;
		int e = input.nextInt()-1;
		
		// I'll just use stacks.
		Stack<Integer>[] sList = new Stack[k];
		for (int i=0; i<k; i++) sList[i] = new Stack<Integer>();
		
		// Put all the disks on stack s.
		int n = k*(k-1)/2;
		for (int i=n; i>=1; i--) sList[s].push(i);
		
		// Weird but I am checking it.
		if (!teamOut.hasNext()) {
			System.out.println("need output");
			return;
		}
		
		// Read the # of lines of output.
		int nM = 0;
		try {
			nM = Integer.parseInt(teamOut.nextLine());
		}
		catch (Exception exp) {
			System.out.println("bad line");
			return;
		}
		catch (OutOfMemoryError me) {
			System.out.println("bad mem");
			return;
		}
		
		// Store all input lines here.
		ArrayList<String> lines = new ArrayList<String>();
		
		// Read rest, look for memory error here also.
		try {
			while (teamOut.hasNext()) lines.add(teamOut.nextLine());
		} 
		catch (Exception exp) {
			System.out.println("bad reading");
			return;
		}
		catch (OutOfMemoryError me) {
			System.out.println("bad mem");
		}
		
		// Wrong # of lines.
		if (lines.size() != nM) {
			System.out.println("wrong # of lines");
			return;
		}
		
		// Do their moves.
		for (int i=0; i<nM; i++) {
		
			// Check tokens.
			int x1 = -1, x2= -1;
			StringTokenizer tok = new StringTokenizer(lines.get(i));
			if (tok.countTokens() != 2) {
				System.out.println("bad toks");
				return;
			}
			
			// Read their moves.
			try {
				x1 = Integer.parseInt(tok.nextToken())-1;
				x2 = Integer.parseInt(tok.nextToken())-1;
			}
			catch (Exception exp) {
				System.out.println("something went wrong.");
				return;
			}
			
			// Invalid stack #1
			if (x1 < 0 || x1 >= k) {
				System.out.println("bad x1");
				return;
			}
			
			// Invalid stack #2
			if (x2 < 0 || x2 >= k || x2 == x1) {
				System.out.println("bad x2");
				return;
			}
			
			// Can't move from empty stack.
			if (sList[x1].size() == 0) {
				System.out.println("can't move from empty stack");
				return;
			}
			
			// Safe to pop.
			int item = sList[x1].pop();
			
			// Too big to place on this stack.
			if (sList[x2].size() > 0 && item >= sList[x2].peek()) {
				System.out.println("can't place on this stack");
				return;
			}
			
			// Make the move.
			sList[x2].push(item);
		}
		
		// Check all stack sizes.
		for (int i=0; i<k; i++) {
			if (i != e && sList[i].size() != 0) {
				System.out.println("not empty when it should be");
				return;
			}
			if (i == e && sList[i].size() != n) {
				System.out.println("not full stack for end");
				return;
			}
		}
		
		// Redundant, but let's make sure the last stack is in order.
		for (int i=1; i<=n; i++) {
			if (sList[e].pop() != i) {
				System.out.println("bad disk");
				return;
			}
		}
		
	}
}