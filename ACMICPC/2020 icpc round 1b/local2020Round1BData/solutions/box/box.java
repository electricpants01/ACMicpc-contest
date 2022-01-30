import java.util.*;

public class box {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int baseLength = in.nextInt();
        int numBlocks = in.nextInt();
        int [] blocks = new int[baseLength];
        int answer = 0;

        for (int i = 0; i < numBlocks; i++) {
            int horizontalLength = in.nextInt();
            int verticalLength = in.nextInt();
            int startIndex = in.nextInt() - 1;
            int endIndex =  horizontalLength + startIndex;
            
            int [] tempArray = Arrays.copyOfRange(blocks, startIndex, endIndex);
            Arrays.sort(tempArray);
            verticalLength += tempArray[horizontalLength-1];
            Arrays.fill(blocks, startIndex, endIndex, verticalLength);
            if (verticalLength > answer) answer = verticalLength;
        }

        System.out.println(answer);
    }    
}