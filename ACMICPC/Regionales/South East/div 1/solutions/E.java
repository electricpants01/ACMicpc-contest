// Arup Guha
// 6/29/2020
// Solution to 2019 SER Problem: Fixed Point Permutations

import java.util.*;

public class fixed {

	final static public long MAX = 1000000000000000000L;

	// Original n...
	public static int n;
	
	// Stores my precomp.
	public static long[][][] memo;

	public static void main(String[] args) {
	
		// Get input.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		int fixed = stdin.nextInt();
		long rank = stdin.nextLong()-1;
		
		// Set up "brute force" arrays.
		int[] perm = new int[n];
		boolean[] used = new boolean[n];
		
		// And memo table!
		memo = new long[n+1][n+1][fixed+1];
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				Arrays.fill(memo[i][j], -1);
		
		// Go!
		boolean res = go(perm, used, 0, rank, n, n, fixed);
	
		// Not enough perms that work...
		if (!res)
			System.out.println(-1);
		
		// Print it!
		else {
			for (int i=0; i<n-1; i++)
				System.out.print((perm[i]+1)+" ");
			System.out.println(perm[n-1]+1);
		}
	}
	
	// First four parameters are for the brute force - perm is what we're filling in, used is what's been used
	// k is the slot we're filling in, and rank is the rank of what we have remaining to fill in.
	
	// Last three are from the pre-comp, strictly speaking, I don't need them, as I could calculate them from the
	// the first four, but it would be annoying...
	public static boolean go(int[] perm, boolean[] used, int k, long rank, int valsLeft, int canM, int fixed) {
	
		// Not enough permutations - just screen out.
		if (f(valsLeft, canM, fixed) <= rank) return false;
		
		// Done!
		if (k == n) return true;
	
		// curSum is how many perms we've passed, oldSum is how many we passed before trying the last number we tried.
		long curSum = 0, oldSum = 0;
		
		// i is the number we are trying in slot k.
		for (int i=0; i<n; i++) {
			
			// We can't use i here because we used it before.
			if (used[i]) continue;
			
			// I am adding a fixed point, so use f to count how many solutions there are if I put k in slot k.
			if (i == k) curSum += f(valsLeft-1, canM-1, fixed-1);
			
			// Here we place a value less than our slot number.
			else if (i < k) {
				
				// If we haven't used k yet, we lose a potential match.
				if (!used[k])
					curSum += f(valsLeft-1, canM-1, fixed);
				
				// If we have used k already, we don't lose any potential match.
				else
					curSum += f(valsLeft-1, canM, fixed);
			}
			
			// In this case, i > k and we previously used k, so we lose 1 potential match.
			else if (used[k])
				curSum += f(valsLeft-1, canM-1, fixed);
			
			// Here i > k and k was a potential match, so we lose TWO potential matches.
			else
				curSum += f(valsLeft-1, canM-2, fixed);
			
			// Value of i is what got us past rank, so get out.
			if (curSum > rank) {
				perm[k] = i;
				used[i] = true;
				break;
			}
			
			// This is now the old sum.
			oldSum = curSum;
		}
		
		// We ended up placing a lower number in slot k.
		if (perm[k] < k) {
			
			// Since we havent' yet used k, we lost one potential match.
			if (!used[k])
				return go(perm, used, k+1, rank-oldSum, valsLeft-1, canM-1, fixed);
			
			// Here we didn't.
			else
				return go(perm, used, k+1, rank-oldSum, valsLeft-1, canM, fixed);
		}
		
		// We added a fixed point.
		else if (perm[k] == k)
			return go(perm, used, k+1, rank-oldSum, valsLeft-1, canM-1, fixed-1);
		
		// Case with larger value in slot k but k was previously used anyway, so we lose 1.
		else if (used[k])								
			return go(perm, used, k+1, rank-oldSum, valsLeft-1, canM-1, fixed);
		
		// And this is the only case where we lost 2 by doing this match.
		else
			return go(perm, used, k+1, rank-oldSum, valsLeft-1, canM-2, fixed);
	}
	
	// This returns the number of ways to fill in myn slots, when there are canM more slots we could potentially match
	// and fixed number of fixed points we must achieve. We calculate this function by not going in order with the slots
	// but by filling the ones that could be matched first.
	public static long f(int myn, int canM, int fixed) {
	
		// Impossible.
		if (canM < fixed) return 0;
		
		// Done - need no more fixed points to work.
		if (myn == 0) {
			if (fixed == 0) return 1;
			return 0;
		}
		
		// Matched too many.
		if (fixed < 0) return 0;
		
		// This means that we can permute all of the rest left over in any way.
		if (canM == 0) return safefact(myn);
		
		// We did this case before, look it up!
		if (memo[myn][canM][fixed] != -1) return memo[myn][canM][fixed];
		
		long res = 0;
		
		// We match this one (our "first" potential future fixed point)
		if (canM > 0 && fixed > 0) res += f(myn-1, canM-1, fixed-1);
		
		// In this case we place a number less than the slot number here.
		if (canM < myn) {
			
			// We lose a potential match (this one) and still need fixed points.
			long tmp = f(myn-1, canM-1, fixed);
			
			// There were myn-canM choices that were lower than this slot number.
			long add = safemult(myn-canM, tmp);
			
			// Add in the product.
			res += add;
		}
		
		// We place a future number we could have matched here, losing the opportunity
		// to match both it AND the future number. Same here.
		if (canM > fixed+1) {
			
			// By definition, this slot could be matched, but we are putting in its place a future match,
			// losint two potential matches and gaining no fixed points.
			long tmp = f(myn-1, canM-2, fixed);
			
			// If there are canM ones that could match, canM-1 are the wrong ones, so we could have any of these here.
			long add = safemult(canM-1, tmp);
			
			// Add this product.
			res += add;
		}
		
		// So we don't overflow.
		if (res > MAX) res = MAX+1;
		
		// Store and return.
		return memo[myn][canM][fixed] = res;
	}
	
	// Returns a*b if there is no overflow, or 10^18+1 otherwise.
	public static long safemult(long a, long b) {
		double maxLog = Math.log(MAX+1);
		double thisLog = Math.log(a) + Math.log(b);
		if (thisLog > maxLog) return MAX+1;
		return a*b;
	}
	
	// Same here, returns n! if there is no overflow or 10^18+1 otherwise.
	public static long safefact(int n) {
		
		if (n >= 20) return MAX+1;
		
		long res = 1;
		for (int i=1; i<=n; i++)
			res *= i;
		return res;
	}

}