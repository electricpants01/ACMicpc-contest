import java.util.*;
import java.io.*;

public class sum
{
    public static void main(String[] args) throws Exception
    {
        new sum(new Scanner(System.in));
    }
    
    int S;
    int ptr;
    Pair[] q;
    long delta;
    int pops = 0;
    
    void reset()
    {
        ptr = 0;
        delta = 0;
    }
    
    void addValue(Pair newPair)
    {
        // System.out.format("add pair %d %d\n", newPair.i, newPair.v);
        delta += newPair.v;
        newPair.v -= delta;
        // System.out.format("delta is now %d\n", delta);
        while (ptr > 0 && q[ptr-1].v <= newPair.v) { 
            pops++;
            ptr--;
            // System.out.format("pop %d %d\n", q[ptr].i, q[ptr].v);
        }
        // System.out.format("new pair is now %d %d\n", newPair.i, newPair.v);
        q[ptr++] = newPair;
        // for (int i = 0; i < ptr; i++) {
            // System.out.format("  %d %d\n", q[i].i, q[i].v);
        // }
    }
    
    Pair getValue()
    {
        if (ptr == 0) return null;
        if (q[0].v+delta < S) return null;
        
        int lo = 0, hi = ptr-1;
        while ((hi-lo)>3)
        {
            int m = (lo+hi)/2;
            if (q[m].v+delta < S)
            hi = m;
            else
            lo = m;
        }
        
        while (hi > lo && q[hi].v+delta < S)
        hi--;
        return q[hi];
    }
    
    public sum(Scanner in)
    {
        q = new Pair[1000000];
        int H = in.nextInt();
        int W = in.nextInt();
        S = in.nextInt();
        
        int[][] mat;
        if (W > H)
        {
            mat = new int[H][W];
            for (int j=0; j<H; j++)
            for (int i=0; i<W; i++)
            mat[j][i] = in.nextInt();
            int tmp = W; W = H; H = tmp;
        }
        else
        {
            mat = new int[W][H];
            for (int j=0; j<H; j++)
            for (int i=0; i<W; i++)
            mat[i][j] = in.nextInt();
        }
        
        long[][] sum = new long[W+1][H];
        for (int j=0; j<H; j++)
        for (int i=0; i<W; i++)
        sum[i+1][j] = mat[i][j]+sum[i][j];
        
        int res = Integer.MAX_VALUE;
        for (int tw=1; tw<=W; tw++)
        {
            for (int i=0; (i+tw)<=W; i++)
            {
                reset();
                // System.out.format("%d %d\n", i, tw);
                for (int j=0; j<H; j++)
                {
                    addValue(new Pair(sum[i+tw][j]-sum[i][j], j));
                    Pair p = getValue();
                    if (p != null)
                    res = Math.min(res, tw * (j-p.i+1));
                }
            }
        }
        //System.out.format("pops %d\n", pops);
        System.out.println(res==Integer.MAX_VALUE?-1:res);
    }
}

class Pair
{
    long v;
    int i;
    
    public Pair(long vv, int ii)
    {
        v=vv; i=ii;
    }
}
