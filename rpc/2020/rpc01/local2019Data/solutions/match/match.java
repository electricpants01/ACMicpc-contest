import java.util.Arrays;
import java.util.Scanner;

/*
 * Bugs to test for:
 * LCP with itself: 2 012012012 0
 * 
 */
public class match {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] cnts = new int[10];
		String[] codes = new String[n];
		StringBuilder master = new StringBuilder();
		for (int i = 0; i < n; i++) {
			String s = codes[i] = in.next();
			cnts[s.charAt(s.length() - 1) - '0']++;
			master.append(s).append('$');
		}
		int m = master.length();
		char[] ms = master.toString().toCharArray();
		int[] sa = suffixArray(ms);
		int[] lcp = lcp(sa, ms);
		
		int[] saRev = new int[m];
		for (int i = 0; i < m; i++)
			saRev[sa[i]] = i;
		
		int[] source = new int[m];
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			int len = codes[i].length();
			for (int j = ptr; j <= ptr + len; j++)
				source[saRev[j]] = i;
			ptr += len + 1;
		}
		
		int[] lcpRight = new int[m];
		for (int i = m - 2; i >= 0; i--) {
			lcpRight[i] = lcp[i];
			if (source[i] == source[i + 1])
				lcpRight[i] = Math.min(lcpRight[i], lcpRight[i + 1]);
		}
		
		int[] lcpLeft = new int[m];
		for (int i = 1; i < m; i++) {
			lcpLeft[i] = lcp[i - 1];
			if (source[i] == source[i - 1])
				lcpLeft[i] = Math.min(lcpLeft[i], lcpLeft[i - 1]);
		}
		
		ptr = 0;
		for (int i = 0; i < n; i++) {
			String s = codes[i];
			if (cnts[s.charAt(s.length() - 1) - '0'] > 1) {
				System.out.println("Impossible");
			} else {
				long sum = 0;
				for (int j = ptr; j < ptr + s.length(); j++) {
					int saIndex = saRev[j];
					int longest = Math.max(lcpLeft[saIndex], lcpRight[saIndex]);
					sum += longest + 1;
				}
				System.out.printf("%.7f\n", sum / (double) s.length());
			}
			ptr += s.length() + 1;
		}
	}

	static int[] suffixArray(char[] S) {
		int n = S.length;
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++)
			order[i] = n - 1 - i;

		Arrays.sort(order, (a, b) -> Character.compare(S[a], S[b]));

		int[] sa = new int[n];
		int[] classes = new int[n];
		for (int i = 0; i < n; i++) {
			sa[i] = order[i];
			classes[i] = S[i];
		}

		for (int len = 1; len < n; len *= 2) {
			int[] c = classes.clone();
			for (int i = 0; i < n; i++) {
				classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n
						&& c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
			}
			int[] cnt = new int[n];
			for (int i = 0; i < n; i++)
				cnt[i] = i;
			int[] s = sa.clone();
			for (int i = 0; i < n; i++) {
				int s1 = s[i] - len;
				if (s1 >= 0)
					sa[cnt[classes[s1]]++] = s1;
			}
		}
		return sa;
	}

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
