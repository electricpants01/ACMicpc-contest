// Jim Geist
// 8/27/2019
// Solution to 2019 UCF Local Contest Problem: Freq
//

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class freq
{
	public static void main(String[] args) throws Exception {
        // Read the line
        //
        Scanner in = new Scanner(System.in);
        String line = in.next();
        in.close();

        // count the occurances of each letter
        //
        int[] counts = new int['z' + 1];

        for (int i = 0; i < line.length(); i++) {
            counts[line.charAt(i)]++;
        }

        while (true) {
            int max = 0;
            int maxIndex = -1;

            // look through the counts array for the highest value. note that
            // we only move to a new max if there's an increase. since the array
            // indexes are alphabetical, this means we get the alphabetic sorting
            // of equal counted letters for free.
            //
            for (int i = 'a'; i <= 'z'; i++) {
                if (counts[i] > max) {
                    max = counts[i];
                    maxIndex = i;
                }
            }

            // if all the counts are zero, we're done.
            //
            if (max == 0) {
                break;
            }

            // print out some repeated letters.
            //
            for (int j = 0; j < counts[maxIndex]; j++) {
                System.out.print((char)maxIndex);
            }

            // remove the count we just consumed.
            //
            counts[maxIndex] = 0;
        }
        System.out.println();
    }
}
