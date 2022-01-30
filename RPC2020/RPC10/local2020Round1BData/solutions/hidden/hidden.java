import java.util.*;

public class hidden {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        char[] w1 = sc.next().toCharArray();
        char[] w2 = sc.next().toCharArray();
        char[] w3 = sc.next().toCharArray();
        char[] full = sc.next().toCharArray();
        int MOD = 1000000007;
        long[][][] ways = new long[w1.length + 1][w2.length + 1][w3.length + 1];
        ways[0][0][0] = 1;
        for (int i = 0; i <= w1.length; i++) {
            for (int j = 0; j <= w2.length; j++) {
                for (int k = 0; k <= w3.length; k++) {
                    ways[i][j][k] %= MOD;
                    if (i != w1.length && w1[i] == full[i + j + k])
                        ways[i + 1][j][k] += ways[i][j][k];
                    if (j != w2.length && w2[j] == full[i + j + k])
                        ways[i][j + 1][k] += ways[i][j][k];
                    if (k != w3.length && w3[k] == full[i + j + k])
                        ways[i][j][k + 1] += ways[i][j][k];
                }
            }
        }
        System.out.println(ways[w1.length][w2.length][w3.length]);
    }
}