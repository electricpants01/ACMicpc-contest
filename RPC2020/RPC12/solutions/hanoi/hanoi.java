// Arup Guha
// 9/12/2020
// Solution to 2020 UCF Locals Final Round Problem: Lots of Towers of Hanoi

import java.util.*;

public class hanoi {

	public static void main(String[] args) {
	
		// Get the input.
		Scanner stdin = new Scanner(System.in);
		int nTowers = stdin.nextInt();
		int disks = nTowers*(nTowers-1)/2;
		int s = stdin.nextInt();
		int e = stdin.nextInt();
		
		// Order in my head of the towers.
		int[] towerList = new int[nTowers];
		towerList[0] = s;
		towerList[1] = e;
		int idx = 2;
		for (int i=1; i<=nTowers; i++) {
			if (s == i || e == i) continue;
			towerList[idx++] = i;
		}
		
		// # of moves.
		System.out.println(2*(nTowers-1)*(nTowers-1)-1);
		
		// d represents the number of disks being moved to a single tower.
		for (int d=nTowers-1; d>=1; d--) {
		
			// we move d disks at a time from s to different towers.
			for (int i=1; i<=d; i++) 
				System.out.println(towerList[0]+" "+towerList[i]);
				
			// Then, move to temp tower towerList[d].
			for (int i=d-1; i>0; i--)
				System.out.println(towerList[i]+" "+towerList[d]);
		}
		
		// Easier for me!
		towerList[0] = e;
		towerList[1] = s;
		
		// Now we move everything from towerList[d] to end (towerList[0])
		for (int d=2; d<=nTowers-1; d++) {
		
			// Move from stack d to all different towers.
			for (int i=d-1; i>=0; i--)
				System.out.println(towerList[d]+" "+towerList[i]);
				
			// Move from the different towers all onto the ending tower.
			for (int i=1; i<=d-1; i++)
				System.out.println(towerList[i]+" "+towerList[0]);
		}	
	}
}