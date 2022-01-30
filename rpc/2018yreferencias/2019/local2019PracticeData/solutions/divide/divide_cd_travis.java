import java.util.*;
import java.io.*;
public class divide_cd_travis
{
    public static Scanner sc;
    public static void main(String[] Args) throws Exception
    {
        sc = new Scanner(System.in);
        String line = getLine();
        String[] tokes = line.split(" ");
        if (tokes.length != 2)
        {
            throw new Exception("Bad number of tokens");
        }
        int tracks = Integer.parseInt(tokes[0]);
        int times = Integer.parseInt(tokes[1]);
        if (tracks < 1 || tracks > 1000000000)
        {
            throw new Exception("Bad track count");
        }
        if (times < 1 || times > 1000)
        {
            throw new Exception("Bad track count");
        }
        HashMap<Integer, Long> memo = new HashMap<Integer, Long>();
        memo.put(tracks, 0l);
        long ans = -1;
        for (int i = 0; i < times; i++)
        {
            ans = -1;
            line = getLine();
            tokes = line.split(" ");
            int count = Integer.parseInt(tokes[0]);
            if (count + 1 != tokes.length || count < 1 || count > 10)
            {
                throw new Exception("Bad line \"" + line + "\"");
            }
            HashSet<Integer> hs = new HashSet<Integer>();
            HashMap<Integer, Long> newMemo = new HashMap<Integer, Long>();
            
            for (int j = 0; j < count; j++)
            {
                int cur = Integer.parseInt(tokes[j + 1]);
                if (cur < 1 || cur > tracks)
                {
                    throw new Exception("Bad line \"" + line + "\"");
                }
                long res = -1;
                for (Integer x : memo.keySet())
                {
                    long tres = comp(x, cur, tracks) + memo.get(x);
                    if (res == -1 || tres < res)
                        res = tres;
                }
                newMemo.put(cur, res);
                hs.add(cur);
                if (ans == -1 || ans > res)
                    ans = res;
            }
            
            if (hs.size() != count)
            {
                throw new Exception("Bad line \"" + line + "\"");
            }
            memo = newMemo;
        }
        System.out.println(ans);
    }
    
    public static int comp(int st, int en, int tks)
    {
        st = (st+1)%tks;
        en = en%tks;
        int r = st-en;
        if (r < 0)
            r = -r;
        int ar = tks - r;
        if (r < ar)
            return r;
        return ar;
    }
    
    public static String getLine() throws Exception
    {
        String ret = sc.nextLine();
        if (!ret.equals(ret.trim()))
        {
            throw new Exception("Extra white space");
        }
        return ret;
    }
}