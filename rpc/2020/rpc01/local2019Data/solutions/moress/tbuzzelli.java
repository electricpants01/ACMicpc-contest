import java.util.*;

public class tbuzzelli {
    static char[][] leftTypes, upTypes;
    static int[][] grid;
    static int[] rows, cols;
    static int n;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        leftTypes = new char[n][n];
        upTypes = new char[n][n];
        for (char[] a : leftTypes) Arrays.fill(a, '.');
        for (char[] a : upTypes) Arrays.fill(a, '.');
        grid = new int[n][n];
        char[][] map = new char[n * 2][];
        for (int i = 0; i < n * 2 - 1; i++) map[i] = in.next().toCharArray();
        rows = new int[n];
        cols = new int[n];
        for (int i = 0; i < n; i++) {
            int ii = i * 2;
            for (int j = 0; j < n; j++) {
                int jj = j * 2;
                if (map[ii][jj] != '-') {
                    grid[i][j] = map[ii][jj] - '0';
                    rows[i] |= 1 << grid[i][j];
                    cols[j] |= 1 << grid[i][j];
                }
                if (i > 0) upTypes[i][j] = map[ii - 1][jj];
                if (j > 0) leftTypes[i][j] = map[ii][jj - 1];
            }
        }
        solve(0, 0);
        for (int i = 0; i < n; i++) {
            for (int x : grid[i]) System.out.print(x);
            System.out.println();
        }
    }
    static boolean solve(int i, int j) {
        if (j == n) return solve(i + 1, 0);
        if (i == n) return true;
        int prev = grid[i][j];
        for (int x = (prev == 0 ? 1 : prev); x <= (prev == 0 ? n : prev); x++) {
            int bit = 1 << x;
            if (prev == 0) {
                if ((rows[i] & bit) != 0) continue;
                if ((cols[j] & bit) != 0) continue;
            }
            if (leftTypes[i][j] == '<' && grid[i][j - 1] >= x) continue;
            if (leftTypes[i][j] == '>' && grid[i][j - 1] <= x) continue;
            if (upTypes[i][j] == '^' && grid[i - 1][j] >= x) continue;
            if (upTypes[i][j] == 'v' && grid[i - 1][j] <= x) continue;
            if (prev == 0) {
                rows[i] |= bit;
                cols[j] |= bit;
            }
            grid[i][j] = x;
            if (solve(i, j + 1)) return true;
            if (prev == 0) {
                rows[i] -= bit;
                cols[j] -= bit;
            }
        }
        grid[i][j] = prev;
        return false;
    }
}
