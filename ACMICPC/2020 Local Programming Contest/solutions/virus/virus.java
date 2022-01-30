import java.util.*;

public class virus {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int numGroups = in.nextInt();
        int numPeoplePerGroup = in.nextInt();
        int numPostitiveGroups = in.nextInt();
        int numIndividualTests = numGroups * numPeoplePerGroup;
        int numGroupTests = numGroups + (numPostitiveGroups * numPeoplePerGroup);

        if (numIndividualTests < numGroupTests) System.out.println(1);
        else {
            if (numIndividualTests > numGroupTests) System.out.println(2);
            else System.out.println(0);
        }
    }
}
