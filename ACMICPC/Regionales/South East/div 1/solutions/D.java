// Arup Guha
// 11/11/2019
// Solution to 2019 SER D1 Regional Problem: Swap Free

import java.util.*;

public class swapfree {

	public static void main(String[] args) {
	
		// Read strings, form graph.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		Dinic g = new Dinic(n);
		String[] perms = new String[n];
		boolean[] even = new boolean[n];
		
		// Go thorugh strings.
		for (int i=0; i<n; i++) {
			perms[i] = stdin.next();
			
			// Which side you are on depends on the # of inversions you have.
			// One swap changes the parity of inversions.
			int numInv = countInv(perms[i]);
			
			// Evens from source.
			if (numInv%2 == 0) {
				g.add(n,i,1,0);
				even[i] = true;
			}
			
			// Odds to sink.
			else
				g.add(i,n+1,1,0);
		}
		
		// Now add edges between pairs on opposite sides, if 1 swap away.
		for (int i=0; i<n; i++) {
			if (!even[i]) continue;
			for (int j=0; j<n; j++) {
				if (even[j]) continue;
				if (numdiff(perms[i], perms[j]) == 2) 
					g.add(i,j,1,0);
			}
		}
		
		// Run flow, subtract from whole and output!
		int cnt = g.flow();
		System.out.println(n-cnt);
	}
	
	// Assumes s,t same length.
	public static int numdiff(String s, String t) {
		int cnt = 0;
		for (int i=0; i<s.length(); i++)
			if (s.charAt(i) != t.charAt(i))
				cnt++;
		return cnt;
	}
	
	// Returns the number of inversions in s.
	public static int countInv(String s) {
		int cnt = 0;
		for (int i=0; i<s.length(); i++)
			for (int j=i+1; j<s.length(); j++)
				if (s.charAt(i) > s.charAt(j))
					cnt++;
		return cnt;
	}
}

class Edge {
	int v1, v2, cap, flow;
	Edge rev;
	Edge(int V1, int V2, int Cap, int Flow) {
		v1 = V1; v2 = V2; cap = Cap; flow = Flow;
	}
}

class Dinic {

	ArrayDeque<Integer> q;
	ArrayList<Edge>[] adj;
	int n, s, t, oo = (int)1E9;
	boolean[] blocked;
	int[] dist;

	public Dinic (int N) {
		n = N; s = n++; t = n++;
		blocked = new boolean[n];
		dist = new int[n];
		q = new ArrayDeque<Integer>();
		adj = new ArrayList[n];
		for(int i = 0; i < n; ++i)
			adj[i] = new ArrayList<Edge>();
	}

	void add(int v1, int v2, int cap, int flow) {
		Edge e = new Edge(v1, v2, cap, flow);
		Edge rev = new Edge(v2, v1, 0, 0);
		adj[v1].add(rev.rev = e);
		adj[v2].add(e.rev = rev);
	}

	boolean bfs() {
		q.clear();
		Arrays.fill(dist, -1);
		dist[t] = 0;
		q.add(t);

		while(!q.isEmpty()) {
			int node = q.poll();
			if(node == s)
				return true;
			for(Edge e : adj[node]) {
				if(e.rev.cap > e.rev.flow && dist[e.v2] == -1) {
					dist[e.v2] = dist[node] + 1;
					q.add(e.v2);
				}
			}
		}
		return dist[s] != -1;
	}

	int dfs(int pos, int min) {
		if(pos == t)
			return min;
		int flow = 0;
		for(Edge e : adj[pos]) {
			int cur = 0;
			if(!blocked[e.v2] && dist[e.v2] == dist[pos]-1 && e.cap - e.flow > 0) {
				cur = dfs(e.v2, Math.min(min-flow, e.cap - e.flow));
				e.flow += cur;
				e.rev.flow = -e.flow;
				flow += cur;
			}
			if(flow == min)
				return flow;
		}
		blocked[pos] = flow != min;
		return flow;
	}

	int flow() {
		clear();
		int ret = 0;
		while(bfs()) {
			Arrays.fill(blocked, false);
			ret += dfs(s, oo);
		}
		return ret;
	}

	void clear() {
		for(ArrayList<Edge> edges : adj)
			for(Edge e : edges)
				e.flow = 0;
	}
}