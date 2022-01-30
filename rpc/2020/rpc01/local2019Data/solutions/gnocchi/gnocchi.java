import java.util.*;

public class gnocchi
{
    public static int BIGGEST = 4000000;
    public static void main(String[] Args)
    {
        Scanner sc = new Scanner(System.in);
        int t = 1;
        int[] isPrime = new int[BIGGEST];
        for (int i = 1; i < BIGGEST; i++)
            isPrime[i] = 1;
        for (int i = 2; i * i < BIGGEST; i++)
            if (isPrime[i] == 1)
                for (int j = i * i; j < BIGGEST; j += i)
                    if (isPrime[j] == 1)
                        isPrime[j] = i;
        while (t-->0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int ans = 1;
            while (k != 0)
            {
                ans++;
                int prime = isPrime[ans];
                if (prime > n)
                    k--;
            }
            System.out.println(ans);
        }
    }
    
    public static int getSmallestDiv(int val)
    {
        int ret = 2;
        while (ret * ret <= val)
        {
            if (val % ret == 0)
                return ret;
            ret++;
        }
        return val;
    }
}
