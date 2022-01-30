import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


/**
 * ICPC - CTU Open Contest 2019
 * Sample Solution: K-bits
 * 
 * @author Martin Kacer
 */
public class kbitu {
	StringTokenizer st = new StringTokenizer("");
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	boolean hasNextToken() {
		try {
			while (!st.hasMoreTokens()) {
				String line = input.readLine();
				if (line == null) return false;
				st = new StringTokenizer(line);
			}
		} catch (IOException ex) { throw new RuntimeException(ex); }
		return true;
	}
	String nextToken() {
		return (!hasNextToken()) ? null : st.nextToken();
	}
	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	public static void main(String[] args) {
		System.out.println(new kbitu().run());
	}
	
	static final int MOD = 1_000_000_007;
	
	int run() {
		int a = nextInt(), b = nextInt(), k = nextInt(), c = nextInt();
		if (c != a && c != b) return 0;
		if (a == b) return k;
		BigInteger mul = BigInteger.ONE;
		for (int i = 1; i < k; ++i) mul = mul.add(mul);
		return mul.multiply(BigInteger.valueOf(k)).mod(BigInteger.valueOf(MOD)).intValue();
	}
}
