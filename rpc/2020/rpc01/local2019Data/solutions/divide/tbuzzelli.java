import java.util.*;

public class tbuzzelli {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        int total = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) total += a[i] = in.nextInt();
        for (int i : a) System.out.println(i * d / total);
    }
}
