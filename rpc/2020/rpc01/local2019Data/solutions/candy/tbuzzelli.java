import java.util.*;

public class tbuzzelli {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        String[] names = new String[n];
        names[n - 1] = "";
        for (int i = 0; i < n - 1; i++) {
            names[i] = in.next();
        }
        int c = in.nextInt();
        int[] nums = new int[c];
        String[] cards = new String[c];
        for (int i = 0; i < c; i++) {
            nums[i] = in.nextInt();
            cards[i] = in.next();
        }
        int[] pos = new int[p];
        Arrays.fill(pos, -1);
        for (int turn = 0, ci = 0; ; turn = (turn + 1) % p, ci = (ci + 1) % c) {
            if (cards[ci].startsWith("SPECIAL")) {
                for (int i = 0; i < n; i++) {
                    if (names[i].equals(cards[ci])) {
                        pos[turn] = i;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < nums[ci]; i++) {
                    pos[turn]++;
                    while (pos[turn] < n - 1 && !names[pos[turn]].equals(cards[ci])) pos[turn]++;
                }
            }
            if (pos[turn] >= n - 1) {
                System.out.println(turn + 1);
                break;
            }
        }
    }
}
