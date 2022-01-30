import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class lastwills_matexpo_arc {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		double[] ls = new double[m];
		double[][] xs = new double[n][m];
		boolean[] out = new boolean[n];
		for (int i = 0; i < n; i++) {
			ls[i] = in.nextInt();
			int k = in.nextInt();
			for (int j = 0; j < k; j++) {
				int v = in.nextInt() - 1;
				xs[i][v] = in.nextDouble();
				if(v >= n) {
					out[i] = true;
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int k=0;k<n;k++) {
					if(xs[j][k] > 0) {
						out[j] |= out[k];
					}
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			if(!out[i]) {
				ls[i] = 0;
				for(int j=0;j<n;j++) {
					xs[i][j] = 0;
				}
			}
		}
		
		
		
		double[][] txs = new double[2 * n][2 * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				txs[i][j < n ? j : (i + n)] += xs[i][j];
			}
		}
		for(int i=n;i<2*n;i++)
			txs[i][i] = 1;
		
		double[] tls = new double[2 * n];
		for (int i = 0; i < n; i++) {
			tls[i] = ls[i];
		}
		
		for(int it=0;it<30;it++) {
			double[][] res = new double[2*n][2*n];
			for(int i=0;i<2*n;i++) {
				for(int j=0;j<2*n;j++) {
					for(int k=0;k<2*n;k++) {
						res[i][k] += txs[i][j] * txs[j][k];
					}
				}
			}
			txs = res;
		}
		double[] ret = new double[2*n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<2*n;j++) {
				ret[j] += tls[i] * txs[i][j];
			}
		}
		
		
		
		for (int i = 0; i < n; i++) {
			double total = 0;
			for (int j = n; j < m; j++) {
				total += xs[i][j];
			}
			if (total > 0)
				for (int j = n; j < m; j++) {
					ls[j] += ret[i + n] * xs[i][j] / total;
				}
			ls[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			System.out.println(i < n ? 0 : ls[i]);
		}
	}
}
