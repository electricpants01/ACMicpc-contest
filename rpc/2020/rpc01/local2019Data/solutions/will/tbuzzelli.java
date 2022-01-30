import java.util.*;

public class tbuzzelli {

  static int n, m;
  static double[][] amts;
  static double[] pops;
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    n = in.nextInt();
    m = in.nextInt();
    amts = new double[n][m];
    pops = new double[m];
    for (int i = 0; i < n; i++) {
      pops[i] = in.nextInt();
      int k = in.nextInt();
      for (int j = 0; j < k; j++) {
        amts[i][in.nextInt() - 1] = in.nextDouble();
      }
    }
    for (int i = 0; i < n; i++) {
      distribute(i);
      double sum = 0;
      for (int j = i + 1; j < n; j++) sum += amts[i][j];
      for (int j = i + 1; j < n; j++) {
        double amt = amts[j][i];
        double given = 0;
        amts[j][i] = 0;
        for (int k = i; k < n; k++) {
          double give = amts[i][k] * amt;
          given += give;
          amts[j][k] += give;
        }
        amts[j][i] = amt - given;
      }
      for (int j = i + 1; j < n; j++) amts[i][j] = 0;
    }
    for (int i = n - 1; i >= 0; i--) distribute(i);
    for (double x : pops)
      System.out.printf("%.12f\n", x);
  }
  static void distribute(int i) {
      double sum = 0;
      amts[i][i] = 0;
      for (int j = 0; j < m; j++) sum += amts[i][j];
      if (sum < 1e-12) {
        pops[i] = 0;
        return;
      }
      for (int j = 0; j < m; j++) amts[i][j] *= 1 / sum;
      for (int j = 0; j < m; j++) pops[j] += pops[i] * amts[i][j];
      pops[i] = 0;
  }

}
