import java.util.*;

public class digit {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        int startingNumber = in.nextInt();
        int endingNumber = in.nextInt();
        // convert int to character
        char digitChar = Character.forDigit(in.nextInt(), 10);
        long count = 0;

        for (int i = startingNumber; i <= endingNumber; i++) {
            // Java stream to count the character occurences
            count += String.valueOf(i).chars().filter(ch -> ch == digitChar).count();
        }

        System.out.println(count);
    }    
}