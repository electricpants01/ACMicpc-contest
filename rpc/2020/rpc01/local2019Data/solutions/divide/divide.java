// Jim Geist
// 8/27/2019
// Solution to 2019 UCF Local Contest Problem: Divide
//

import java.util.Scanner;

public class divide
{
	public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        int n, d;

        // read n and d
        n = in.nextInt();
        d = in.nextInt();
    
        int[] solved = new int[n];
    
        // read how many problems each student solved, and also compute
        // the total number of problems solved
        //
        int total_problems = 0;
        for (int i = 0; i < n; i++) {
            solved[i] = in.nextInt();
            total_problems += solved[i];
        }
    
        // how much money to award for each problem
        //
        int award = d / total_problems;
    
        // now we can give out money!
        //
        for (int i = 0; i < n; i++) {
            System.out.println(award * solved[i]);
        }

        in.close();
    }
}