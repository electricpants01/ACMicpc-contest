import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class lastwills_naive_2_arc {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		double[] ls = new double[m];
		double[][] xs = new double[n][m];
		for (int i = 0; i < n; i++) {
			ls[i] = in.nextInt();
			int k = in.nextInt();
			for (int j = 0; j < k; j++) {
				int v = in.nextInt() - 1;
				xs[i][v] = in.nextDouble();
			}
		}
		double[][] txs = new double[n][2 * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				txs[i][j < n ? j : (i + n)] += xs[i][j];
			}
		}
		double[] tls = new double[2 * n];
		for (int i = 0; i < n; i++) {
			tls[i] = ls[i];
		}
		Random r = new Random(1);
		int[] ran = new int[n];
		for (int i = 0; i < n; i++)
			ran[i] = i;
		for (int j = n - 1; j >= 0; j--) {
			int i = r.nextInt(j + 1);
			int tmp = ran[i];
			ran[i] = ran[j];
			ran[j] = tmp;
		}
		for (int iter = 0; iter < 200000000 / n / 2 / n; iter++) {
			for(int i : ran) {
				for (int j = 0; j < 2*n; j++) {
					tls[j] += tls[i] * txs[i][j];
				}
				tls[i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			double total = 0;
			for (int j = n; j < m; j++) {
				total += xs[i][j];
			}
			if (total > 0)
				for (int j = n; j < m; j++) {
					ls[j] += tls[i + n] * xs[i][j] / total;
				}
			ls[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			System.out.println(i < n ? 0 : ls[i]);
		}
	}
}
