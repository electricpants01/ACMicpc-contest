
import java.util.*;
public class brute {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<Integer>();
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            adj[a].add(b);
            adj[b].add(a);
        }
        int q = sc.nextInt();
        int[] map = new int[q];
        int noGo = 0;
        int alsoNoGo = (1<<n)-1;
        for (int i = 0; i < q; i++) {
            int x = sc.nextInt() - 1;
            noGo |= (1<<x);
            for (Integer y : adj[x]) {
                map[i] |= (1<<y);
                alsoNoGo &= -(1<<y)-1;
                //System.out.println(Integer.toBinaryString(-(1<<y)-1));
            }
        }
        int ans = 0;
        noGo |= alsoNoGo;
        for (int i = 0; i < (1<<n); i++) {
            boolean good = (0 == (noGo & i));
            for (int j = 0; good && j < q; j++) {
                if (Integer.bitCount(map[j]&i) != 1) good = false;
            }
            if (good) ans++;
        }
        System.out.println(ans);
    }
}