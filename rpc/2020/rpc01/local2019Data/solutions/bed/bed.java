// Arup Guha
// 7/31/2019
// Solution to 2019 UCF Locals Problem: Fitting on the Bed

import java.util.*;

public class bed {
	
	// Different than a normal epsilon, but gives us plenty of tolerance as the data spec allows.
	final public static double EPS = 0.001;

	public static void main(String[] args) {
	
		// Get bed and Anya sizes.
		Scanner stdin = new Scanner(System.in);
		int bedLength = stdin.nextInt();
		int bedWidth = stdin.nextInt();
		int anyaHeight = stdin.nextInt();
		
		// Get Anya's location and orientation.
		int x = stdin.nextInt();
		int y = stdin.nextInt();
		int angle = stdin.nextInt();
		double angleRad = angle*Math.PI/180;
		
		// This is where Anya's feet are.
		double feetX = x + anyaHeight*Math.cos(angleRad);
		double feetY = y + anyaHeight*Math.sin(angleRad);
		
		// Since our confining shape is a rectangle, we just need to check Anya's feet!
		if (feetX > -EPS && feetX < bedWidth+EPS && feetY > -EPS && feetY < bedLength+EPS)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}