import java.util.*;

public class elect {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int numStates = in.nextInt();
        int numElectoralVotes, numVotesFirst, numVotesSecond;
        int [] majorityVotes = new int[2];
        int [] electoralVotes = new int[2];

        for (int i = 0; i < numStates; i++) {
            numElectoralVotes = in.nextInt();
            numVotesFirst = in.nextInt();
            numVotesSecond = in.nextInt();
            majorityVotes[0] += numVotesFirst;
            majorityVotes[1] += numVotesSecond;


            if (numVotesFirst >  numVotesSecond) electoralVotes[0] += numElectoralVotes;
            else  electoralVotes[1] += numElectoralVotes;
        }

        if (majorityVotes[0] > majorityVotes[1] && electoralVotes[0] > electoralVotes[1])
            System.out.println((1));
        else {
            if (majorityVotes[1] > majorityVotes[0] && electoralVotes[1] > electoralVotes[0])
                System.out.println(2);
            else
                System.out.println(0);
        }
    
    }    
}
