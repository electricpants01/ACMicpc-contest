// Arup Guha
// 3/17/2002
// Solution to 2019 SER Problem: Interstellar Travel

import java.util.*;
import java.io.*;

public class interstellar {
	
	public static int n;
	public static double[][] data;
	
	public static ArrayList<event> events;
	
	public static void main(String[] args) throws Exception {
		
		// Read in all of the raw data.
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(stdin.readLine());
		data = new double[n][3];
		for (int i=0; i<n; i++) {
			StringTokenizer tok = new StringTokenizer(stdin.readLine());
			for (int j=0; j<3; j++)
				data[i][j] = Double.parseDouble(tok.nextToken());
		}
		
		// Will store all important events here.
		events = new ArrayList<event>();
		
		// Adds all important events from angle 0 to 4pi for each item i.
		for (int i=0; i<n; i++)
			add(events, i);
		
		// Sort these by angle.
		events.sort((e1,e2)->e1.angle.compareTo(e2.angle));
		
		// Set the current value and delta based on the first event.
		double curVal = events.get(0).init;
		double curDelta = events.get(0).delta;
		double curAngle = events.get(0).angle;
		double maxVal = curVal;
		
		// Now sweep!
		for (int i=1; i<events.size(); i++) {
			
			// Get the new angle and update the current value.
			double newAngle = events.get(i).angle;
			
			// I've checked every angle by the time I get here, so get out!
			if (newAngle > 2*Math.PI) break;
			
			// Update value.
			curVal += (curDelta*(newAngle-curAngle));
			
			// This might get added in.
			if (events.get(i).first) curVal += events.get(i).init;
			maxVal = Math.max(curVal, maxVal);
			
			// Update delta.
			curDelta += events.get(i).delta;
			
			// Update angle.
			curAngle = newAngle;
		}
		
		// Ta da!
		System.out.printf("%.6f\n", maxVal);
	}
	
	public static void add(ArrayList<event> events, int i) {
		
		// Use their variables.
		double t = data[i][0];
		double s = data[i][1];
		double a = data[i][2];
		
		// Never drops to 0.
		if (t/s >= Math.PI) {
			
			// First event - starts at min of function.
			double cura = a-3*Math.PI;
			events.add(new event(true, t-s*Math.PI, s, cura));
			
			// To make life easier, I am adding 2 events at a time. 
			// (Since I end on an up, my last interval is invalid, so I won't check it.)
			while (cura < 4*Math.PI) {
				events.add(new event(false, 0, -2*s, cura+Math.PI));
				events.add(new event(false, 0, 2*s, cura+2*Math.PI));
				cura += (2*Math.PI);
			}
		}
		
		// More annoying, function goes to 0.
		else {

			// First event - starts at 0.
			double cura = a - 2*Math.PI - t/s;
			
			// Here we will add 3 events at a time.
			while (cura < 4*Math.PI) {
				events.add(new event(false, 0, s, cura));
				events.add(new event(false, 0, -2*s, cura+t/s));
				events.add(new event(false, 0, s, cura+2*t/s));
				cura += (2*Math.PI);
			}
		}			
	}

}

class event {

	public boolean first;
	public double init;
	public double delta;
	public Double angle;
	
	public event(boolean isFirst, double val, double mydelta, double myangle) {
		first = isFirst;
		init = val;
		delta = mydelta;
		angle = myangle;
	}
}