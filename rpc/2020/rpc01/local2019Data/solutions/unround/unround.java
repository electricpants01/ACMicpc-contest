import java.util.*;

public class unround
{
    public static void main(String[] Args)
    {
        Scanner sc = new Scanner(System.in);
        int dec = sc.nextInt();
        
        int n = sc.nextInt();
        
        double[] lo = new double[n];
        double[] hi = new double[n];
        
        double[] lo_2 = new double[n];
        double[] hi_2 = new double[n];
        
        for (int i = 0; i < n; i++)
        {
            double val = sc.nextDouble();
            lo[i] = getBound(val, dec, true);
            hi[i] = getBound(val, dec, false);
            
            lo_2[i] = Math.log(lo[i]);
            hi_2[i] = Math.log(hi[i]);
            
            //System.out.println(lo[i] + " " + hi[i]);
        }
        
        double lowest_st = hi[0] * 2;
        double highest_st = lo[0] / 2;
        
        //System.out.println(lowest_st +" " +highest_st);
        double lowest_rate = hi[1]/lo[0];
        double highest_rate = lo[1]/hi[0];
        boolean good = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // hi to lo bounding
                double rate_log = (hi_2[i] - lo_2[j]) / (i - j);
                double start_log = hi_2[i] - rate_log * i;
                if (valid(rate_log, start_log, lo_2, hi_2))
                {
                    double rate = Math.exp(rate_log);
                    //System.out.println(rate+" 1 " +i +" "+j);
                    if (rate < lowest_rate)
                        lowest_rate = rate;
                    if (highest_rate < rate)
                        highest_rate = rate;
                    double start = Math.exp(start_log);
                    if (start < lowest_st)
                        lowest_st = start;
                    if (highest_st < start)
                        highest_st = start;
                     good = true;
                }
                // hi to hi bounding
                rate_log = (hi_2[i] - hi_2[j]) / (i - j);
                start_log = hi_2[i] - rate_log * i;
                if (valid(rate_log, start_log, lo_2, hi_2))
                {
                    double rate = Math.exp(rate_log);
                    //System.out.println(rate +" 2 " +i +" "+j);
                    if (rate < lowest_rate)
                        lowest_rate = rate;
                    if (highest_rate < rate)
                        highest_rate = rate;
                    double start = Math.exp(start_log);
                    if (start < lowest_st)
                        lowest_st = start;
                    if (highest_st < start)
                        highest_st = start;
                     good = true;
                }
                // lo to lo bounding
                rate_log = (lo_2[i] - lo_2[j]) / (i - j);
                start_log = lo_2[i] - rate_log * i;
                if (valid(rate_log, start_log, lo_2, hi_2))
                {
                    double rate = Math.exp(rate_log);
                    //System.out.println(rate+" 3 " +i +" "+j);
                    if (rate < lowest_rate)
                        lowest_rate = rate;
                    if (highest_rate < rate)
                        highest_rate = rate;
                    double start = Math.exp(start_log);
                    if (start < lowest_st)
                        lowest_st = start;
                    if (highest_st < start)
                        highest_st = start;
                     good = true;
                }
                // lo to hi bounding
                rate_log = (lo_2[i] - hi_2[j]) / (i - j);
                start_log = lo_2[i] - rate_log * i;
                if (valid(rate_log, start_log, lo_2, hi_2))
                {
                    double rate = Math.exp(rate_log);
                    //System.out.println(rate+" 4 " +i +" "+j);
                    if (rate < lowest_rate)
                        lowest_rate = rate;
                    if (highest_rate < rate)
                        highest_rate = rate;
                    double start = Math.exp(start_log);
                    if (start < lowest_st)
                        lowest_st = start;
                    if (highest_st < start)
                        highest_st = start;
                     good = true;
                }
            }
        }
        //System.out.println(lowest_st + " " + highest_st + " " + lowest_rate + " " + highest_rate);
        //        System.out.println("Here");
        if (good)
        System.out.println(roundStr(lowest_st, dec + 3) + " " + roundStr(highest_st, dec + 3) + " " + roundStr(lowest_rate, dec + 5) + " " + roundStr(highest_rate, dec + 5));
         else
            System.out.println("NO SOLUTION FOUND!");
    }
    
    public static boolean valid(double r, double st, double[] lo, double[] hi)
    {
        int n = lo.length;
        for (int i = 0; i < n; i++)
        {
            double cur = st + i * r;
            if (!eq(cur, lo[i]) && cur < lo[i]){
                //System.out.println(i);
                return false;
            }
            if (!eq(cur, hi[i]) && cur > hi[i]){
                //System.out.println(i);
                return false;
            }
        }
        return true;
    }
    
    public static double getBound(double target, int pre, boolean isLow)
    {
        double lo = 0;
        double hi = 1;
        while (round(hi, pre) < target * (1 + (isLow ? -EPS : EPS)))
            hi *= 2;
        
        while (!eq(hi, lo))
        {
            double mid = (lo + hi) / 2;
            //System.out.println(round(mid, pre));
            if (round(mid, pre) < target * (1 + (isLow ? -EPS : EPS)))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        return isLow ? lo : hi;
    }
    
    public static double EPS = 2e-13;
    
    public static boolean eq(double a, double b) 
    {
        double d = Math.abs(a - b);
        if (d < EPS)
            return true;
        double max = Math.max(Math.abs(a), Math.abs(b));
        return (d < max * EPS);
    }

    public static double round(double value, int pre)
    {
        int count = pre;
        long max = 1;
        while (count-->0)
            max *= 10;
        if (value > max)
            return round(value / 10, pre) * 10;
        if (value < max / 10)
            return round(value * 10, pre) / 10;
        long value2 = (long)(value * 10);
        value2 += 5;
        value2 /= 10;
        return value2 * 1.0;
    }

    public static String roundStr(double value, int pre)
    {
        value *= (1 + EPS);
        int count = pre;
        long max = 1;
        boolean needDec = true;
        while (count-->0)
            max *= 10;
        int fudge = 0;
        while (value > max){
            fudge++;
            value /= 10;
        }
        while (value < max / 10){
            fudge--;
            value *= 10;
        }
        long value2 = (long)(value * 10);
        value2 += 5;
        value2 /= 10;
        String ret = value2+"";
        
        fudge++;
        while (fudge--> 0)
            ret = ret +"0";
        //System.out.println(fudge +" " +ret);
        if (fudge < 0)
        {
            while (fudge + ret.length() <= 0)
            {
                ret = "0"+ret;
            }
            ret = ret.substring(0, ret.length() + fudge) + "." + ret.substring(ret.length() + fudge);
        }
        if (ret.endsWith(".0") && ret.length() - 2 >= pre)
           ret = ret.substring(0, ret.length() - 2);
        return ret;
    }
}
