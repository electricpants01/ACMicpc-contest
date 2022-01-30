// Arup Guha
// 9/8/2020
// Solution to 2020 UCF Locals Round 1B Problem: Thirsty Professors.

import java.util.*;

public class drink {
	
	final public static double EPSILON = 1e-9;

	public static void main(String[] args) {
	
		// Read in one line.
		Scanner stdin = new Scanner(System.in);
		int x = stdin.nextInt();
		int y = stdin.nextInt();
		pt2D p1 = new pt2D(x, y);
		x = stdin.nextInt();
		y = stdin.nextInt();
		pt2D p2 = new pt2D(x, y);
		line forward = new line(p1, p2);
	
		// And the other.
		x = stdin.nextInt();
		y = stdin.nextInt();
		pt2D r1 = new pt2D(x, y);
		x = stdin.nextInt();
		y = stdin.nextInt();
		pt2D r2 = new pt2D(x, y);
		line backward = new line(r1, r2);	
		
		// Get the intersection.
		pt2D cross = forward.intersectSegs(backward);
		
		// No intersection, no water.
		if (cross == null)
			System.out.println(0.0);
			
		// At least we get something.
		else {
		
			// Get the vectors for the triangle.
			vect2D v1 = new vect2D(cross, p2);
			vect2D v2 = new vect2D(cross, r2);
			
			// Default answer which occurs if either vector is 0.
			double res = 0;
			
			// No zero vectors, safe to do math.
			if (!v1.zero() && !v2.zero()) {
			
				// This factor will be the proportion of the triangle that gets filled.
				double factor = 1;
			
				// If we look at the longer side as the base of the triangle, we see that factor
				// is just a ratio of the useable portion of the base.
				if (p2.y > r2.y)
					factor = (r2.y-cross.y)/(p2.y-cross.y);
				else if (r2.y > p2.y)
					factor = (p2.y-cross.y)/(r2.y-cross.y);
			
				// The proportional area we want.
				res = factor*v1.crossMag(v2)/2;
			}
				
			// Now we can print.
			//System.out.println(res);
			System.out.printf("%.15f%n", res);
		}
	}
}

/*** Hackpack code for 2d geometry from my COP 4516 class. ***/
class vect2D {
	
	final public static double EPSILON = 1e-9;

    public double x;
    public double y;

    public vect2D(double myx, double myy) {
        x = myx;
        y = myy;
    }

    public vect2D(pt2D start, pt2D end) {
        x = end.x - start.x;
        y = end.y - start.y;
    }

    public double dot(vect2D other) {
        return this.x*other.x + this.y*other.y;
    }

    public double mag() {
        return Math.sqrt(x*x+y*y);
    }
	
	public boolean zero() {
		return mag() < EPSILON;
	}

    // This formula comes from using the relationship between the dot product and
    // the cosine of the included angle.
    public double angle(vect2D other) {
        return Math.acos(this.dot(other)/mag()/other.mag());
    }

    public double signedCrossMag(vect2D other) {
        return this.x*other.y-other.x*this.y;
    }

    public double crossMag(vect2D other) {
        return Math.abs(signedCrossMag(other));
    }
}

class line {

    final public static double EPSILON = 1e-9;

    public pt2D p;
    public vect2D dir;

    public line(pt2D start, pt2D end) {
        p = start;
        dir = new vect2D(start, end);
    }

    public pt2D intersectSegs(line other) {

        // This is the denominator we get when setting up our system of equations for
        // our two parametric line parameters.
        double den = det(dir.x, -other.dir.x, dir.y, -other.dir.y);
        if (Math.abs(den) < EPSILON) return null;

        // Solve for both parameter's numerators.
        double numLambda = det(other.p.x-p.x, -other.dir.x, other.p.y-p.y, -other.dir.y);
		double numBeta = det(dir.x, other.p.x-p.x, dir.y, other.p.y-p.y);
		
		// Get both parameters.
		double lambda = numLambda/den;
		double beta = numBeta/den;
		
		// Segments don't intersect.
		if (lambda < -EPSILON || lambda > 1+EPSILON) return null;
		if (beta < -EPSILON || beta > 1+EPSILON) return null;
		
		// Okay.
        return eval(numLambda/den);
    }

    // Returns the shortest distance from other to this line. Sets a vector from the starting
    // point of this line to other and uses the cross product with that vector and the direction
    // vector of the line.
    public double distance(pt2D other) {
        vect2D toPt = new vect2D(p, other);
        return dir.crossMag(toPt)/dir.mag();
    }

    // Returns the point on this line corresponding to parameter lambda.
    public pt2D eval(double lambda) {
        return new pt2D(p.x+lambda*dir.x, p.y+lambda*dir.y);
    }

    public static double det(double a, double b, double c, double d) {
        return a*d - b*c;
    }
}

class pt2D {

    public double x;
    public double y;

    public pt2D(double myx, double myy) {
        x = myx;
        y = myy;
    }
}
