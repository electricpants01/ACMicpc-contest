// Arup Guha
// 11/9/2019
// Solution to 2019 SER D2 Problem: Even or Odd?

import java.util.*;

public class evenorodd {

	public static void main(String[] args) {
	
		// Get input.
		Scanner stdin = new Scanner(System.in);
		long n = stdin.nextLong();
		
		// For an odd number, it changes depending on whether we start at even or odd.
		if (n%2 == 1)
			System.out.println("0");
		
		// These triangle numbers are always even (4xa + even tri num)
		else if (n%4 == 0)
			System.out.println("2");
		
		// These are always odd because ( (4x+2)a + odd tri)
		else
			System.out.println("1");
	}
}