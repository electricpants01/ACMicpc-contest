import java.io.File;
import java.util.Scanner;

public class spell {
	public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        int dwc = in.nextInt();
        String[] dict = new String[dwc];
        for (int k = 0; k < dwc; k++) {
            dict[k] = in.next();
        }

        int iwc = in.nextInt();
        for (int k = 0; k < iwc; k++) {
            String word = in.next();
            System.out.println(word);
            check(dict, word);            
            System.out.println();
        }
    }
    
    private static void check(String[] dict, String word) {
        for (int i = 0; i < dict.length; i++) {
            if (dict[i].equals(word)) {
                System.out.println("CORRECT");
                return;
            }
        }

        boolean foundMapping = false;
        for (String dictWord : dict) {
            if (
                oneRemoved(dictWord, word) ||
                oneAdded(dictWord, word) ||
                oneWrong(dictWord, word) ||
                transposed(dictWord, word)                
            ) {
                foundMapping = true;
            }
        }

        if (!foundMapping) {
            System.out.println("UNKNOWN");
        }
    }

    private static boolean oneRemoved(String orig, String test) {
        if (hasOmitted(orig, test)) {
            System.out.println("ONE LETTER OMITTED FROM " + orig);
            return true;
        }
        return false;
    }

    private static boolean oneAdded(String orig, String test) {
        if (hasOmitted(test, orig)) {
            System.out.println("ONE LETTER ADDED TO " + orig);
            return true;
        }
        return false;
    }

    // true if 'test' can be made by omitting any one char from
    // 'orig'
    private static boolean hasOmitted(String orig, String test) {
        if (orig.length() != test.length() + 1) {
            return false;        
        }

        int oi = 0;
        int ti = 0;

        for (oi = 0; oi < orig.length(); oi++) {
            if (ti < test.length() && orig.charAt(oi) == test.charAt(ti)) {
                ti++;
            }
        }

        return ti == oi - 1;
    }

    // true if 'test' can be made from 'orig' by changing any one
    // char.
    private static boolean oneWrong(String orig, String test) {
        if (orig.length() != test.length()) {
            return false;
        }

        int wrong = 0;
        for (int i = 0; i < orig.length(); i++) {
            if (orig.charAt(i) != test.charAt(i)) {
                wrong++;
            }
        }

        if (wrong == 1) {
            System.out.println("ONE LETTER DIFFERENT FROM " + orig);
            return true;
        }
        return false;
    }

    // true if 'test' can be made by transposing any two chars in
    // 'orig'
    private static boolean transposed(String orig, String test) {
        if (orig.length() != test.length()) {
            return false;
        }

        int wrong = 0;

        for (int i = 0; i < orig.length() - 1; i++) {
            if (orig.charAt(i) == test.charAt(i)) {
                continue;
            }

            if (
                orig.charAt(i) == test.charAt(i+1) &&
                test.charAt(i) == orig.charAt(i+1)
            ) {
                i++;
                wrong++;
                continue;
            }

            return false;
        }

        if (wrong == 1) {
            System.out.println("TWO LETTERS TRANSPOSED IN " + orig);
            return true;
        }

        return false;
    }
}
