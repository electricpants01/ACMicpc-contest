import java.util.*;

public class tbuzzelli {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int l = in.nextInt();
        int w = in.nextInt();
        int h = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        double ang = in.nextDouble() * Math.PI / 180;
        double xx = x + h * Math.cos(ang);
        double yy = y + h * Math.sin(ang);
        System.out.println(xx + 1e-5 >= 0 && xx - 1e-5 <= w && yy + 1e-5 >= 0 && yy - 1e-5 <= l ? "YES" : "NO");
    }
}
