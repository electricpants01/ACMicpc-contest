import java.util.*;

public class tbuzzelli {

  public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      StringBuilder sb = new StringBuilder();
      String[] strs = new String[n];
      int[] lens = new int[n];
      int[] idxs = new int[n];
      int[] endCount = new int[256];
      for (int i = 0; i < n; i++) {
          strs[i] = in.next();
          lens[i] = strs[i].length();
          idxs[i] = sb.length();
          sb.append(strs[i]);
          sb.append('$');
          endCount[strs[i].charAt(lens[i] - 1)]++;
      }
      char[] str = sb.toString().toCharArray();
      int len = str.length;
      int[] ids = new int[len];
      int cid = 0;
      for (int i = 0; i < len; i++)
          if (str[i] == '$') {
              cid++;
              ids[i] = -1;
          } else {
              ids[i] = cid;
          }
      int[] sa = suffixArray(str);
      int[] lcp = lcp(sa, str);
      long[] sums = new long[n];
      int[] dpL = new int[len];
      int[] dpR = new int[len];
      for (int i = 1; i < len; i++) {
          dpL[i] = lcp[i - 1];
          if (ids[sa[i]] == ids[sa[i - 1]])
              dpL[i] = Math.min(dpL[i], dpL[i - 1]);
      }
      for (int i = len - 2; i >= 0; i--) {
          dpR[i] = lcp[i];
          if (ids[sa[i]] == ids[sa[i + 1]])
              dpR[i] = Math.min(dpR[i], dpR[i + 1]);
      }
      for (int i = 0; i < len; i++)
          if (ids[sa[i]] != -1)
              sums[ids[sa[i]]] += Math.max(dpL[i], dpR[i]) + 1;
      for (int i = 0; i < n; i++)
          System.out.println(endCount[strs[i].charAt(lens[i] - 1)] == 1 ? sums[i] * 1.0 / lens[i] : "Impossible");
  }
  // sort suffixes of S in O(n*log(n))
  static int[] suffixArray(char[] S) {
    int n = S.length;
    Integer[] order = new Integer[n];
    for (int i = 0; i < n; i++)
      order[i] = n - 1 - i;

    // stable sort of characters //%
    Arrays.sort(order, (a, b) -> Character.compare(S[a], S[b]));

    int[] sa = new int[n];
    int[] classes = new int[n];
    for (int i = 0; i < n; i++) {
      sa[i] = order[i];
      classes[i] = S[i];
    }
    // sa[i] - suffix on i'th position after sorting by first len characters //%
    // classes[i] - equivalence class of the i'th suffix after sorting by first len characters //%

    for (int len = 1; len < n; len *= 2) {
      int[] c = classes.clone();
      for (int i = 0; i < n; i++) {
        // condition sa[i - 1] + len < n simulates 0-symbol at the end of the string //%
        // a separate class is created for each suffix followed by simulated 0-symbol //%
        classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
      }
      // Suffixes are already sorted by first len characters //%
      // Now sort suffixes by first len * 2 characters //%
      int[] cnt = new int[n];
      for (int i = 0; i < n; i++)
        cnt[i] = i;
      int[] s = sa.clone();
      for (int i = 0; i < n; i++) {
        // s[i] - order of suffixes sorted by first len characters //%
        // (s[i] - len) - order of suffixes sorted only by second len characters //%
        int s1 = s[i] - len;
        // sort only suffixes of length > len, others are already sorted //%
        if (s1 >= 0)
          sa[cnt[classes[s1]]++] = s1;
      }
    }
    return sa;
  }
  // longest common prefixes array in O(n)
  static int[] lcp(int[] sa, char[] s) {
    int n = sa.length;
    int[] rank = new int[n];
    for (int i = 0; i < n; i++)
      rank[sa[i]] = i;
    int[] lcp = new int[n - 1];
    for (int i = 0, h = 0; i < n; i++) {
      if (rank[i] < n - 1) {
        for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < s.length && s[i + h] == s[j + h]; ++h)
          ;
        lcp[rank[i]] = h;
        if (h > 0)
          --h;
      }
    }
    return lcp;
  }
}
