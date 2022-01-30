
import java.util.*;

public class incoming {
    public static double oo = 1e18;
    public static double FUDGE = 1e-6;
    public static double EPS = 1e-9;
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double r = sc.nextDouble();
        double zl = sc.nextDouble();
        double zu = sc.nextDouble();
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            String name = sc.next();
            double px = sc.nextDouble();
            double py = sc.nextDouble();
            double deg = sc.nextDouble();
            double altitude = sc.nextDouble();
            double speed = sc.nextDouble();
            double decent = sc.nextDouble();
            double start = 0;
            double end = oo;
            if (!eq(decent,0)) {
                end = Math.min(end, (altitude - zl + FUDGE) / decent);
                start = Math.max(start, (altitude - zu - FUDGE) / decent);
            } else if (eq(decent,0) && (!leq(zl, altitude) || !leq(altitude, zu))) {
                start = oo;
                end = -oo;
            }

            if (!eq(decent, speed)) {
                double hSpeed = Math.sqrt(speed * speed - decent * decent);
                double hx = hSpeed * Math.cos(deg * Math.PI / 180);
                double hy = hSpeed * Math.sin(deg * Math.PI / 180);
                double dx = px - x;
                double dy = py - y;
                double xs = hx;
                double ys = hy;
                double a = xs * xs + ys * ys;
                double b = 2 * (xs * dx + ys * dy);
                double c = dx * dx + dy * dy - (r+FUDGE) * (r+FUDGE);
                if (!leq(4 * a * c, b * b)) {
                    start = oo;
                    end = -oo;
                } else {
                    if (!leq(b * b, 4 * a * c)) {
                        double diff = Math.sqrt(b * b - 4 * a * c);
                        start = Math.max(start,  (- diff - b) / (2 * a));
                        end = Math.min(end,  (diff - b) / (2 * a));
                    } else {
                        start = Math.max(start,  - b / (2 * a));
                        end = Math.min(end, - b / (2 * a));
                    }
                }

            } else if (eq(decent, speed) && !leq(d2(x-px,y-py), r * r)) {
                start = oo;
                end = -oo;
            }

            if (leq(start, end)) {
                // Intersection
                System.out.printf("Incoming! Flight %s enters at %.02f and exits at %.02f.%n", name,
                    start, end);
            } else {
                // No bueno
                System.out.printf("Flight %s is safe.%n", name);
            }
        }
    }

    public static boolean leq(double a, double b) {
        if (a < b) return true;
        return eq(a, b);
    }

    public static boolean eq(double a, double b) {
        double diff = Math.abs(a - b);
        if (diff < EPS) return true;
        double max= Math.max(Math.abs(a), Math.abs(b));
        return (diff < EPS * max);
    }

    public static double d2(double dx, double dy) {
        return dx * dx + dy * dy;
    }
}