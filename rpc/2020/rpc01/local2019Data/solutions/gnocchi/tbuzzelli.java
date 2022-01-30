import java.util.*;

public class tbuzzelli {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int max = 10000000;
        int[] div = new int[max + 1];
        Arrays.fill(div, max);
        div[1] = 1;
        for (int i = 2; i <= max; i++) {
            if (div[i] != max) continue;
            div[i] = 0;
            for (long j = i * 1L * i; j <= max; j += i) {
                div[(int) j] = Math.min(div[(int) j], i);
            }
        }
        int t = in.nextInt();
        for (int ci = 0; ci < t; ci++) {
            int n = in.nextInt();
            int k = in.nextInt();
            for (int i = k + 1; ; i++) {
                if (div[i] > n) k--;
                if (k == 0) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}
