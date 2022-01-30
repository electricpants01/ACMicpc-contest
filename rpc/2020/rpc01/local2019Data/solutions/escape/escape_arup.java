// Arup Guha
// 9/10/2019
// Alternate Solution to 2019 UCF Locals Problem: Cooperative Escape

import java.util.*;

public class escape_arup {
	
	// Directions we can move.
	final public static int[] DX = {-1,0,0,1};
	final public static int[] DY = {0,-1,1,0};
	
	// Stores the grid.
	public static int r;
	public static int c;
	public static char[][] grid;
	
	public static void main(String[] args) {
		
		// Read in the basic dimensions.
		Scanner stdin = new Scanner(System.in);
		r = stdin.nextInt();
		c = stdin.nextInt();
		grid = new char[r][];
		
		// Read in the grid.
		for (int i=0; i<r; i++)
			grid[i] = stdin.next().toCharArray();
		
		// Graph size. Source = 2*r*c, Sink = 2*r*c+1.
		int size = 2*r*c + 2;
		int s = 2*r*c;
		int t = 2*r*c+1;
		
		int[][] flows = new int[size][size];
		
		/*** We definitely don't need longs here...this is just what I had in my hackpack
		     and I was too lazy to change it to ints. As a consequence, I am sure my code
			 is quite a bit slower...
		***/
		long[][] costs = new long[size][size];
		
		// Find each location - put in appropriate flows.
		int bonnie = find('B');
		int clyde = find('C');
		int finish = find('F');
		flows[s][2*bonnie] = 1;
		flows[s][2*clyde] = 1;
		flows[2*finish+1][t] = 2;
		
		// This is a flow of one "within" a square, limiting each square to one visitor.
		for (int i=0; i<size-2; i+=2)
			if (grid[i/2/c][(i/2)%c] !='X')
				flows[i][i+1] = 1;
		
		// Last square is the exception.
		flows[2*finish][2*finish+1] = 2;
		
		// These are outflows from each square.
		for (int i=1; i<size-2; i+=2) {
			
			// Four possible directions.
			for (int dir=0; dir<DX.length; dir++) {
				
				// Extract x,y coordinates of current, next square.
				int cX = (i/2)/c;
				int cY = (i/2)%c;
				if (grid[cX][cY] == 'X') continue;
				int nX = cX+DX[dir];
				int nY = cY+DY[dir];
				
				// Can't go out of bounds.
				if (!inbounds(nX,nY)) continue;
				
				// Can't go to illegal square.
				if (grid[nX][nY] == 'x') continue;
				
				// Since this edge specifies actual movement, both flow AND cost are 1.
				flows[i][2*(nX*c+nY)] = 1;
				costs[i][2*(nX*c+nY)] = 1;
			}
		}
		
		// Now, I can set this up and get the min cost max flow.
		netflow mine = new netflow(flows, costs, s, t);
		long[] res = mine.getMaxFlowMinCost();
		
		// If they don't both escape, it's failure!
		if (res[0] < 2)
			System.out.println("-1");
		
		// If they do, we want the minimum cost of getting a flow of 2.
		else
			System.out.println(res[1]);
	}
	
	// Finds first location of c in grid.
	public static int find(char ch) {
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				if (grid[i][j] == ch) 
					return c*i+j;
		return -1;
	}
	
	public static boolean inbounds(int x, int y) {
		return x >= 0 && x < r && y >= 0 && y < c;
	}
}

/*** My super ugly min cost flow code. I used mine instead of the hackpack for a double check... ***/

class Edge {

	public int dest;
	private int capacity;
	private int flow;
	private long cost;

	public Edge(int cap, int d, long money) {
		capacity = cap;
		flow = 0;
		dest = d;
		cost = money;
	}

	public int maxPushForward() {
		return capacity - flow;
	}

	public int maxPushBackward() {
		return flow;
	}

	public boolean pushForward(int moreflow) {

		// We can't push through this much flow.
		if (flow+moreflow > capacity)
			return false;

		// Push through.
		flow += moreflow;
		return true;
	}

	public boolean pushBack(int lessflow) {

		// Not enough to push back on.
		if (flow < lessflow)
			return false;

		flow -= lessflow;
		return true;
	}


	public long getCost() {
		return cost;
	}

	public int curFlow() {
		return flow;
	}
}

class direction {

	public int prev;
	public boolean forward;

	public direction(int node, boolean dir) {
		prev = node;
		forward = dir;
	}

	public String toString() {
		if (forward)
			return "" + prev + "->";
		else
			return "" + prev + "<-";
	}
}

class netflow {

	private Edge[][] adjMat;
	private int source;
	private int dest;
	private HashMap[] lookup;
	private LinkedList[] backEdgeLookup;

	// All positive entries in flows should represent valid flows
	// between vertices. All other entries must be 0 or negative.
	public netflow(int[][] flows, long[][] costs, int start, int end) {

		source = start;
		dest = end;
		adjMat = new Edge[flows.length][];
		lookup = new HashMap[flows.length];

		backEdgeLookup = new LinkedList[flows.length];
		for (int i=0; i<flows.length; i++)
			backEdgeLookup[i] = new LinkedList<Integer>();

		for (int i=0; i<flows.length; i++) {

			lookup[i] = new HashMap<Integer,Integer>();

			int numEdges = 0;
			for (int j=0; j<flows[i].length; j++)
				if (flows[i][j] > 0)
					numEdges++;

			adjMat[i] = new Edge[numEdges];

			int cnt = 0;
			for (int j=0; j<flows[i].length; j++) {

				// Fill in this flow.
				if (flows[i][j] > 0) {
					lookup[i].put(j, cnt);
					adjMat[i][cnt++] = new Edge(flows[i][j], j, costs[i][j]);
					backEdgeLookup[j].offer(i);
				}
			}
		}
	}

	// Return an augmenting path, if found, null otherwise.
	public ArrayList<direction> findAugmentingPath() {

		// This will store the previous node visited in the BFS.
		direction[] prev = new direction[adjMat.length];
		boolean[] inQueue = new boolean[adjMat.length];
		for (int i=0; i<inQueue.length; i++)
			inQueue[i] = false;

		// The source has no previous node.
		prev[source] = new direction(-1, true);

		LinkedList<Integer> bfs_queue = new LinkedList<Integer>();
		bfs_queue.offer(new Integer(source));
		inQueue[source] = true;

		// Our BFS will go until we clear out the queue.
		while (bfs_queue.size() > 0) {

			// Add all the new neighbors of the current node.
			Integer next = bfs_queue.poll();

			if (adjMat[next] == null) continue;

			// Find all neighbors and add into the queue. These are forward edges.
			for (int i=0; i<adjMat[next].length; i++) {

				int item = adjMat[next][i].dest;
				if (!inQueue[item] && adjMat[next][i].maxPushForward() > 0) {
					bfs_queue.offer(item);
					inQueue[item] = true;
					prev[item] = new direction(next, true);
				}
			}

			// Now look for back edges.
			for (int i=0; i<backEdgeLookup[next].size(); i++) {

				int item = (Integer)backEdgeLookup[next].pollFirst();
				if (!inQueue[item] && lookup[item].containsKey(next) && adjMat[item][(Integer)(lookup[item].get(next))].maxPushBackward() > 0) {
					bfs_queue.offer(item);
					inQueue[item] = true;
					prev[item] = new direction(next, false);
				}
				backEdgeLookup[next].offer(item);
			}
		}

		// No augmenting path found.
		if (!inQueue[dest])
			return null;

		ArrayList<direction> path = new ArrayList<direction>();

		direction place = prev[dest];

		direction dummy = new direction(dest, true);
		path.add(dummy);

		// Build the path backwards.
		while (place.prev != -1) {
			path.add(place);
			place = prev[place.prev];
		}

		// Reverse it now.
		Collections.reverse(path);

		return path;
	}

	// Run the Max Flow Algorithm here.
	public long[] getMaxFlowMinCost() {

		int flow = 0;
		long cost = 0;

		ArrayList<direction> nextpath = findAugmentingPath();

		// Loop until there are no more augmenting paths.
		while (nextpath != null) {

			// Check what the best flow through this path is.
			int this_flow = Integer.MAX_VALUE;
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward)
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].maxPushForward());
				else
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].maxPushBackward());
			}

			// Now, put this flow through.
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward) {
					adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].pushForward(this_flow);
					cost += (this_flow*adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].getCost());
				}
				else {
					adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].pushBack(this_flow);
					cost -= (this_flow*adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].getCost());
				}
			}

			// Add this flow in and then get the next path.
			flow += this_flow;
			nextpath = findAugmentingPath();
		}

		// Now try to improve cost.
		nextpath = findNegWeightCycle();

		// Loop until there are no more negative weight cycles.
		while (nextpath != null) {

			// Check what the best flow through this path is.
			int this_flow = Integer.MAX_VALUE;
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward)
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].maxPushForward());
				else
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].maxPushBackward());
			}

			// Now, put this flow through.
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward) {
					adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].pushForward(this_flow);
					cost += (this_flow*adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].getCost());
				}
				else {
					adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].pushBack(this_flow);
					cost -= (this_flow*adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].getCost());
				}
			}

			// Add this flow in and then get the next path.
			flow += this_flow;
			nextpath = findNegWeightCycle();
		}

		// Return full answer.
		long[] ans = new long[2];
		ans[0] = flow; ans[1] = cost;
		return ans;
	}

	// Use Bellman-Fords to detect a negative weight cycle and return one of them, if present, null otherwise.
	public ArrayList<direction> findNegWeightCycle() {

		// For Bellman-Ford
		int n = adjMat.length;
		long[] distances = new long[n];
		direction[] prev = new direction[n];
		Arrays.fill(distances, 1000000000);
		distances[source] = 0L;
		Arrays.fill(prev, null);
		prev[source] = new direction(-1, true);

		// Run n-1 times.
		for (int i=0; i<n-1; i++) {

			boolean change = false;

			// Relax each edge, looking for shorter distance, noting if a change is made.
			for (int j=0; j<n; j++) {
				for (int k=0; k<adjMat[j].length; k++) {

					int to = adjMat[j][k].dest;
					if (adjMat[j][k].maxPushForward() > 0 && adjMat[j][k].getCost()*adjMat[j][k].maxPushForward() + distances[j] < distances[to]) {
						distances[to] = adjMat[j][k].getCost()*adjMat[j][k].maxPushForward() + distances[j];
						prev[to] = new direction(j, true);
						change = true;
					}

					if (adjMat[j][k].maxPushBackward() > 0 && distances[to] - adjMat[j][k].getCost()*adjMat[j][k].maxPushBackward() < distances[j]) {
						distances[j] = distances[to] - adjMat[j][k].getCost()*adjMat[j][k].maxPushBackward();
						prev[j] = new direction(to, false);
						change = true;
					}

				}
			}

			// Try to detect a cycle early.
			int vertex = getCycleStart(prev);
			if (vertex >= 0)
				return getCycle(vertex, prev);

			// No improvements means no negative cycle, since we have all best distances.
			if (!change) return null;
		}

		boolean negcycle = false;
		int vertex = -1;

		// Try to find a negative weight cycle.
		for (int j=0; j<n; j++) {
			for (int k=0; k<adjMat[j].length; k++) {

				int to = adjMat[j][k].dest;
				if (adjMat[j][k].maxPushForward() > 0 && adjMat[j][k].getCost()*adjMat[j][k].maxPushForward() + distances[j] < distances[to]) {
					distances[to] = adjMat[j][k].getCost()*adjMat[j][k].maxPushForward() + distances[j];
					prev[to] = new direction(j, true);
					negcycle = true;
					vertex = j;
				}

				if (adjMat[j][k].maxPushBackward() > 0 && distances[to] - adjMat[j][k].getCost()*adjMat[j][k].maxPushBackward() < distances[j]) {
					distances[j] = distances[to] - adjMat[j][k].getCost()*adjMat[j][k].maxPushBackward();
					prev[j] = new direction(to, false);
					negcycle = true;
					vertex = to;
				}

			}
		}

		// No negative weight cycles.
		if (!negcycle) return null;

		return getCycle(vertex, prev);
	}

	// Given a list of each vertices' previous vertices, this function returns a vertex that is part of a cycle.
	// If no such cycle exists, -1 is returned.
	public static int getCycleStart(direction[] prev) {

		int n = prev.length;

		// Test each vertex.
		for (int i=0; i<n; i++) {

			boolean[] used = new boolean[n];
			if (!used[i] && prev[i] != null) {

				used[i] = true;
				direction place = prev[i];

				// Follow the previous vertices and see if we end up back at i.
				while (place != null && place.prev != i && place.prev != -1 && !used[place.prev]) {
					used[place.prev] = true;
					place = prev[place.prev];
				}

				// A cycle!
				if (place != null && place.prev == i) return i;
			}

		}

		// Never found a cycle.
		return -1;
	}

	// Return the cycle starting at vertex indicated by the previous array prev.
	public static ArrayList<direction> getCycle(int vertex, direction[] prev) {

		ArrayList<direction> path = new ArrayList<direction>();

		direction place = prev[vertex];

		direction dummy = new direction(vertex, true);
		path.add(dummy);

		// Build the path backwards.
		while (place.prev != vertex) {
			path.add(place);
			place = prev[place.prev];
		}
		path.add(place);

		// Reverse it now.
		Collections.reverse(path);

		return path;
	}
}