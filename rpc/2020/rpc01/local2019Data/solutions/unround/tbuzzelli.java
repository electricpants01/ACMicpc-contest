import java.math.*;
import java.util.*;

public class tbuzzelli {
    static final boolean ALLOW_DECREASING = true;
    static final double EPS = 2e-14;
    static final int ITERS = 60;
    static int d, n;
    static double[] arr, mins, maxs, minLogs, maxLogs;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        d = in.nextInt();
        n = in.nextInt();
        arr = new double[n];
        mins = new double[n];
        maxs = new double[n];
        minLogs = new double[n];
        maxLogs = new double[n];
        for (int i = 0; i < n; i++) {
            String str = in.next();
            if (!str.contains(".")) {
                str += ".";
                for (int j = 0; j < d + 2; j++) str += "0";
            }
            double x = Double.parseDouble(str);
            double add = 0.5;
            int amt = 0;
            if (str.charAt(0) != '0' && str.charAt(0) != '.') {
                int shift = str.indexOf(".");
                for (int j = 0; j < shift; j++) add *= 10;
            }
            int count = 0;
            boolean seenDecimal = false;
            for (char c : str.toCharArray()) {
                if (c == '.') {
                    seenDecimal = true;
                    continue;
                }
                if (count == 0 && c == '0') {
                    if (seenDecimal) {
                        add /= 10;
                    }
                    continue;
                }
                count++;
                add /= 10;
                if (count == d) break;
            }
            System.err.println(count + " " + add);
            double sub = add;
            if (str.replaceAll("0|\\.", "").equals("1")) sub /= 10;
            arr[i] = x;
            mins[i] = x - sub;
            maxs[i] = x + add;
            minLogs[i] = Math.log(mins[i]);
            maxLogs[i] = Math.log(maxs[i]);
        }
        System.err.println(Arrays.toString(mins));
        System.err.println(Arrays.toString(maxs));
        System.err.println(Arrays.toString(minLogs));
        System.err.println(Arrays.toString(maxLogs));
        double[] ans = solve();
        System.err.println(Arrays.toString(ans));
        for (int i = 0; i < 4; i++)
            ans[i] = Math.exp(ans[i]);
        System.out.printf("%s %s %s %s\n", round(ans[0], d + 3), round(ans[1], d + 3), round(ans[2], d + 5), round(ans[3], d + 5));
    }
    static String round(double xd, int d) {
        System.err.println(xd + " " + d);
        BigDecimal x = BigDecimal.valueOf(xd);
        int shift = 30;
        x = x.scaleByPowerOfTen(shift);
        BigInteger num = x.toBigInteger();
        int len = num.toString().length();
        BigInteger mod = BigInteger.valueOf(10).pow(len - d);
        if (num.mod(mod).multiply(BigInteger.valueOf(2)).compareTo(mod) >= 0) {
            num = num.add(mod);
        }
        num = num.subtract(num.mod(mod));
        String str = new BigDecimal(num).scaleByPowerOfTen(-shift).stripTrailingZeros().toPlainString();
        int count = 0;
        for (char c : str.toCharArray())
            if (c != '.' && (count > 0 || c != '0')) count++;
        int need = d - count;
        if (need > 0 && !str.contains(".")) str += ".";
        for (int i = 0; i < need; i++) str += "0";
        return str;
    }
    static double[] solve() {
        double minY0 = 1e30;
        double maxY0 = -1e30;
        double minSlope = 1e30;
        double maxSlope = -1e30;
        for (int i = 0; i < n; i++) {
            double x0 = i;
            for (int ii = 0; ii < 2; ii++) {
                double y0 = ii == 0 ? minLogs[i] : maxLogs[i];
                for (int j = i + 1; j < n; j++) {
                    double x1 = j;
                    for (int jj = 0; jj < 2; jj++) {
                        double y1 = jj == 0 ? minLogs[j] : maxLogs[j];
                        double slope = getSlope(x0, y0, x1, y1);
                        double myY0 = getY0(x0, y0, x1, y1);
                        if (isValid(myY0, slope)) {
                            minY0 = Math.min(minY0, myY0);
                            maxY0 = Math.max(maxY0, myY0);
                            minSlope = Math.min(minSlope, slope);
                            maxSlope = Math.max(maxSlope, slope);
                        }
                    }
                }
            }
        }
        return new double[] {minY0, maxY0, minSlope, maxSlope};
    }
    static double getSlope(double x0, double y0, double x1, double y1) {
        return (y1 - y0) / (x1 - x0);
    }
    static double getY0(double x0, double y0, double x1, double y1) {
        return y0 - getSlope(x0, y0, x1, y1) * x0;
    }
    static boolean isValid(double y0, double slope) {
        for (int i = 0; i < n; i++) {
            double y = y0 + slope * i;
            if (y < minLogs[i] - EPS) return false;
            if (y > maxLogs[i] + EPS) return false;
        }
        return true;
    }
}
