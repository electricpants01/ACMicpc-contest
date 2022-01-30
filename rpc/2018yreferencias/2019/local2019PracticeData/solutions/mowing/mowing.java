// Jim Geist
// 8/7/2019
// Solution to 2019 UCF Practice Local Contest Problem: Mowing
//
// Based on
// http://usaco.org/current/data/sol_mowing_platinum_feb19.html
//
import java.io.*;
import java.util.*;

public class mowing {
  static class xpair {
    public int x;
    public int index;

    xpair(int x, int index) {
      this.x = x;
      this.index = index;
    }    
  }

  static int MAXN = 300001;  
  static int N, L;
  static int[] x = new int[MAXN];  
  static int[] y = new int[MAXN];
  static xpair[] xid = new xpair[MAXN];  
  static int[] lis = new int[MAXN];
  static long[] dp = new long[MAXN];
  static long[] dpPlus = new long[MAXN];

  static List<List<Integer>> levels = new ArrayList<List<Integer>>();

  static void computeLIS() {
    levels.get(0).add(xid[0].index);
    lis[xid[0].index] = 0;
    int mx = 0;

    for(int i = 1; i < N; i++) {
      int cur = xid[i].index;
      int low = -1;
      int high = mx;
      
      while (low != high) {
        int mid = (low + high + 1) / 2;
        List<Integer> level = levels.get(mid);
        int last = level.get(level.size() - 1);
        if (y[last] < y[cur]) {
          low = mid;
        } else {
          high = mid-1;
        }
      }

      levels.get(low+1).add(cur);
      mx = Math.max(mx, low+1);
      lis[cur] = low+1;
    }
  }

  static long cost(int i, int j) {
    return 
      dp[i] +
      x[i] * (long)y[i] -
      x[i] * (long)y[j] -
      y[i] * (long)x[j] +
      x[j] * (long)y[j];
  }

  // x[i] < x[j]; when will i overtake j on level l
  static int findLocOvertake(int l, int i, int j) {
    int low = 0;
    int high = levels.get(l).size();

    while (low != high) {
      int mid = (low + high) / 2;
      if (cost(i, levels.get(l).get(mid)) < cost(j, levels.get(l).get(mid))) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }

  static int[] firstDom = new int[MAXN];
  static int[] lastDom = new int[MAXN];

  // for i in level l-1, first point in level l dominating i, or -1 if none
  static int findFirst(int l, int i) {
    int low = 0;
    int high = levels.get(l).size() - 1;

    while (low != high) {
      int mid = (low + high) / 2;
      if (x[levels.get(l).get(mid)] > x[i]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    if (x[levels.get(l).get(low)] > x[i] && y[levels.get(l).get(low)] > y[i]) {
      return low;
    }
 
    return -1;
  }

  // for i in level l-1, last point in level l dominating i, or -1 if none
  static int findLast(int l, int i) {
    int low = 0;
    int high = levels.get(l).size() - 1;

    while (low != high) {
      int mid = (low + high + 1) / 2;
      if (y[levels.get(l).get(mid)] > y[i]) {
        low = mid;        
      } else {
        high = mid - 1;
      }
    }

    if (x[levels.get(l).get(low)] > x[i] && y[levels.get(l).get(low)] > y[i]) {
      return low;
    }

    return -1;    
  }

  static int[] que = new int[MAXN];
  static int[] overtake = new int[MAXN];
  static List<Integer> level = new ArrayList<Integer>();

  // intervals all start in [qStart, qEnd] and end at qEnd or later
  static void solveStartingRegion(int l, int iStart, int iEnd, int qStart, int qEnd) {
    int len = 0;
    int i = iStart;
    for (int j=qStart; j<=qEnd; j++) {
      int q = levels.get(l+1).get(j);
      while (i <= iEnd && firstDom[i] <= j) {
        while (len >= 2 && overtake[len-2] <= findLocOvertake(l+1, que[len-1], level.get(i))) {
          len--;
        }
        que[len] = level.get(i);
        if (len >= 1) {
          overtake[len-1] = findLocOvertake(l+1, que[len-1], level.get(i));
        }
        len++;
        i++;
      }
      while (len >= 2 && overtake[len-2] <= j) {
        len--;
      }
      dp[q] = Math.min(dp[q], cost(que[len-1], q));
    }
  }

  //intervals all start at qStart or before, and end in [qStart, qEnd]
  static void solveEndingRegion(int l, int iStart, int iEnd, int qStart, int qEnd) {
    int len = 0;
    int i = iEnd;
    for (int j=qEnd; j>=qStart; j--) {
      int q = levels.get(l+1).get(j);
      while(i >= iStart && lastDom[i] >= j) {
        while (len >= 2 && overtake[len-2] >= findLocOvertake(l+1, level.get(i), que[len-1])) {
          len--;
        }
        
        que[len] = level.get(i);
        if (len >= 1) {
          overtake[len-1] = findLocOvertake(l+1, level.get(i), que[len-1]);
        }
        
        len++;
        i--;
      }
      
      while(len >= 2 && overtake[len-2] > j) {
        len--;
      }
      dp[q] = Math.min(dp[q], cost(que[len-1], q));
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);

    N = in.nextInt();
    L = in.nextInt();

    for (int i = 0; i < N; i++) {
      x[i] = in.nextInt();
      y[i] = in.nextInt();
    }

    x[N] = L;
    y[N] = L;

    N++;
    for (int i = 0; i < N; i++) {
      dp[i] = Long.MAX_VALUE;
      xid[i] = new xpair(x[i], i);
    }

    for (int i = 0; i <= N; i++) {
      levels.add(new ArrayList<Integer>());
    }

    Arrays.sort(xid, 0, N, (xpair left, xpair right)->left.x - right.x);

    computeLIS();

    for (int i = 0; i < levels.get(0).size(); i++) {
      int cur = levels.get(0).get(i);
      dp[cur] = x[cur] * (long)y[cur];
    }

    for (int l = 0; levels.get(l+1).size() > 0; l++) {
      level.clear();
      for(int i=0; i<levels.get(l).size(); i++) {
        int cur = levels.get(l).get(i);
        int fd = findFirst(l+1, cur);
        int ld = findLast(l+1, cur);
        if(fd != -1) {    //must eliminate points in levels[l] not dominated by any points in levels[l+1]
          firstDom[level.size()] = fd;
          lastDom[level.size()] = ld;
          level.add(levels.get(l).get(i));
        }
      }
      
      for (int i=0; i<level.size();) {
        int iEnd = i;
        while (iEnd + 1 < level.size() && firstDom[iEnd + 1] <= lastDom[i]) {
          iEnd++;
        }
        solveStartingRegion(l, i, iEnd, firstDom[i], lastDom[i]);
        if(lastDom[iEnd] >= lastDom[i] + 1) {
          solveEndingRegion(l, i+1, iEnd, lastDom[i] + 1, lastDom[iEnd]);
        }
        i = iEnd + 1;
      }
    }
    System.out.println(dp[N-1]);
  }
}