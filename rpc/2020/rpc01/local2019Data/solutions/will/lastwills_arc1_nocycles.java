import java.util.*;

public class lastwills_arc1 {
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
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++)
				tls[j] += tls[i] * txs[i][j];
			tls[i] = 0;
			for (int j = i + 1; j < n; j++) {
				double sum = 0;
				for (int k = i + 1; k < 2 * n; k++) {
					if (j == k)
						continue;
					txs[j][k] += txs[j][i] * txs[i][k];
					sum += txs[j][k];
				}
				txs[j][i] = 0;
				if (sum > 0)
					for (int k = 0; k < 2 * n; k++) {
						txs[j][k] /= sum;
					}
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
			System.out.println(ls[i]);
		}
	}
}
