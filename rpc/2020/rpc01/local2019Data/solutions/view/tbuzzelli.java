import java.util.*;

public class tbuzzelli {
    static long[] xs, ys;
    static double[] areas;
    static long w;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        w = in.nextLong();
        xs = new long[n + 1];
        ys = new long[n + 1];
        areas = new double[n];
        double maxArea = 0;
        double area = 0;
        for (int i = 0; i < n; i++) {
            xs[i] = in.nextLong();
            ys[i] = in.nextLong();
            if (i > 0) {
                area += areas[i - 1] = (ys[i] + ys[i - 1]) * (xs[i] - xs[i - 1]) / 2.0;
            }
        }
        xs[n] = xs[n - 1];
        ys[n] = ys[n - 1];
        if (w < xs[n - 1]) {
            long lx = xs[0];
            area = 0;
            int i = 0;
            int j = 0;
            while (lx <= xs[n - 1] - w) {
                long rx = lx + w;
                while (i + 1 < n && xs[i + 1] <= lx) area -= areas[i++];
                while (j + 1 < n && xs[j + 1] <= rx) area += areas[j++];
                long nextLx = Math.min(xs[i + 1], xs[j + 1] - w);
                double min = lx;
                double max = nextLx;
                for (int iter = 0; iter < 60; iter++) {
                    double mid1 = min + (max - min) / 3;
                    double mid2 = max - (max - min) / 3;
                    double area1 = area + getArea(i, j, mid1);
                    double area2 = area + getArea(i, j, mid2);
                    if (area1 > area2) max = mid2;
                    else min = mid1;
                    maxArea = Math.max(maxArea, Math.max(area1, area2));
                }
                if (lx == nextLx) break;
                lx = nextLx;
            }
        } else {
            maxArea = area;
        }
        System.out.println(maxArea / w);
    }
    static double getArea(int i, int j, double lx) {
        double area = 0, rx = lx + w;
        double ly = getY(xs[i], ys[i], xs[i + 1], ys[i + 1], lx);
        double ry = getY(xs[j], ys[j], xs[j + 1], ys[j + 1], rx);
        area -= (ys[i] + ly) * (lx - xs[i]) / 2;
        area += (ys[j] + ry) * (rx - xs[j]) / 2;
        return area;
    }
    static double getY(long x0, long y0, long x1, long y1, double x) {
        if (x0 == x1) return y0;
        return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
    }
}
