// Arup Guha
// 9/9/2020
// Alternate Solution for 2020 UCF Locals Round 1B Problem: Autojudge

import java.util.*;

public class autojudge {
	
	// Possible extensions.
	final public static String[] EXT = {".py",".java",".c",".cpp"};

	public static void main(String[] args) {
	
		// Read File stuff.
		Scanner stdin = new Scanner(System.in);
		String fileName = stdin.nextLine();
		String submittedName = stdin.nextLine();
		
		// Read return, timing stuff.
		StringTokenizer tok = new StringTokenizer(stdin.nextLine());
		int ret = Integer.parseInt(tok.nextToken());
		int timeLimit = Integer.parseInt(tok.nextToken());
		int runTime = Integer.parseInt(tok.nextToken());
		
		// Read correct output.
		int numOutLines = Integer.parseInt(stdin.nextLine());
		String[] correct = new String[numOutLines];
		for (int i=0; i<numOutLines; i++)
			correct[i] = stdin.nextLine();
	
		// Read student output.
		int numStudOut = Integer.parseInt(stdin.nextLine());
		String[] student = new String[numStudOut];
		for (int i=0; i<numStudOut; i++)
			student[i] = stdin.nextLine();
		
		// Just go through the cases in the order mentioned.
		if (!matchName(fileName, submittedName))
			System.out.println("Compile Error");
		else if (ret != 0)
			System.out.println("Run-Time Error");
		else if (runTime > timeLimit)
			System.out.println("Time Limit Exceeded");
		else if (!match(correct, student))
			System.out.println("Wrong Answer");
		else
			System.out.println("Correct");
	}
	
	// Returns true if submit is a valid file name for file.
	public static boolean matchName(String file, String submit) {
		
		// To avoid AOOB.
		if (submit.length() < file.length()) return false;
		
		// Match names.
		for (int i=0; i<file.length(); i++)
			if (file.charAt(i) != submit.charAt(i))
				return false;
			
		// Cut off this part.
		submit = submit.substring(file.length());
		
		// Rest must match one of the valid extensions exactly.
		for (int i=0; i<EXT.length; i++)
			if (submit.equals(EXT[i]))
				return true;
			
		// If we get here we never matched a valid extension.
		return false;
	}
	
	// Returns true iff contents of a are identical to b.
	public static boolean match(String[] a, String[] b) {
		
		// Can't be equal if lengths aren't.
		if (a.length != b.length) return false;
		
		// If any line is off, it's bad.
		for (int i=0; i<a.length; i++)
			if (!a[i].equals(b[i]))
				return false;
			
		// We're good.
		return true;
	}
}
