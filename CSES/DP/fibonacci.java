import java.util.Scanner;

public class Fibonacci {

    //final static long MOD = 1000000007;
    public static void main(String[] args) {
        long n = new Scanner(System.in).nextLong();
        System.out.println(fib(n));
    }

    private static long fib(long n) {
        final long MOD = 1000000007;
        long prev = 0, next = 1, ans = 0;
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            for (int i = 2; i <= n; ++i) {
                ans = (prev) % MOD + (next) % MOD;
                prev = (next) % MOD;
                next = (ans) % MOD;
            }
            return next;
        }
    }
}