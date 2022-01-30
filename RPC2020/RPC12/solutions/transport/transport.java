import java.util.*;
import java.io.*;

public class transport {

    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        long money = sc.nextLong();
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] edges = new int[4][m];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < 4; j++)
                edges[j][i] = sc.nextInt();
            edges[0][i]--;
            edges[1][i]--;
        }
        double ans = 0;

        double lo = 0;
        double hi = money;

        Edmonds ed = new Edmonds();
        while (!eq(lo, hi)){
            double mid = (lo + hi) / 2;
            ArrayList<Edge>[] adj = new ArrayList[n];
            ArrayList<Edge>[] jda = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<Edge>();
                jda[i] = new ArrayList<Edge>();
            }
            for (int i = 0; i < m; i++) {
                if (edges[0][i] == 0) continue;
                int s = edges[0][i];
                int e = edges[1][i];
                double w = edges[2][i] + mid * edges[3][i];
                Edge fwd = new Edge(e, w);
                Edge bck = new Edge(s, w);
                fwd.rev = bck;
                bck.rev = fwd;
                adj[s].add(fwd);
                jda[e].add(bck);
            }
            double val = mid + ed.getMinBranching(0, adj, jda);
            // System.out.println(val +" " + (val - mid));
            if (val > money)
                hi = mid;
            else
                lo = ans = mid;
            //System.out.println();
        }
        // System.out.println(ans);
        System.out.printf("%.11f%n", ans);
    }


    public static double EPS = 1e-11;
    public static boolean eq(double a, double b) {
        double diff = Math.abs(a - b);
        if (diff < EPS) return true;
        double max = Math.max(Math.abs(a), Math.abs(b));
        return (diff < EPS * max);
    }


    // Thanks to mlbright!!!
    public static class Edge implements Comparable<Edge> {
        int dest;
        double weight;
        double oWeight;
        Edge rev;
        boolean used;

        public Edge(int dest, double weight) {
            this.dest = dest;
            this.weight = weight;
            this.oWeight = weight;
            rev = null;
            used = false;
        }
    
        public int compareTo(final Edge o) {
            return Double.compare(weight, o.weight);
        }

        public String toString() {
            return String.format("%s %.2f", dest, weight);
        }
    }
    public static class DS {
        int[] p;
        DS(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++)
                p[i] = i;
        }
        int find(int x) {
            return (p[x] == x) ? x : (p[x] = find(p[x]));
        }
        boolean union(int a, int b) {
            int aa = find(a);
            int bb = find(b);
            if (aa == bb) return false;
            p[bb] = aa;
            return true;
        }
    }
    public static class Edmonds {
    
        public double getMinBranching(int root, ArrayList<Edge>[] adj, ArrayList<Edge>[] jda) {
            int n = adj.length;
            int trees = n;
            double ret = 0;
            
            DS forest = new DS(n);
            DS cycle = new DS(n);

            ArrayList<Edge>[] result = new ArrayList[n];
            Edge[] inComingEdge = new Edge[n];
            TreeSet<Integer>[] mergedNodes = new TreeSet[n];

            for (int i = 0; i < n; i++) {
                mergedNodes[i] = new TreeSet<Integer>();
                mergedNodes[i].add(i);
                result[i] = new ArrayList<Edge>();
            }
            // System.out.println("****************");
            ArrayList<ArrayList<Edge>> cycles = new ArrayList<ArrayList<Edge>>();
            while (trees >  1) { // will run at most ??? times
                // for each node, select the edge entering it with smallest weight
                // System.out.println();
                // System.out.println(num + " ");
                for (int i = 0; i < n; i++) {
                    int majorNode = forest.find(i);
                    if (forest.find(majorNode) != i) continue;
                    // System.out.println(Arrays.toString(inComingEdge));
                    if (inComingEdge[majorNode] != null) continue;
                    // System.out.println("Major node is " + i );
                    Edge best = null;
                    for (Integer j : mergedNodes[majorNode]) {
                        // System.out.println("   " + j);
                        for (Edge e : adj[j]) {

                            // System.out.println("      " + e);
                            int dest = e.dest;
                            if (mergedNodes[i].contains(dest)) continue;
                            if (best == null || (e.weight < best.weight))
                                best = e;
                        }
                    }
                    //System.out.println(best);

                    if (best == null) continue;
                    inComingEdge[i] = best;
                    result[best.dest].add(best.rev);
                    best.rev.used = best.used = true;
                    // System.out.println( best.dest + " " + best.rev.dest);
                    // System.out.println(Arrays.toString(inComingEdge));
                    // Try to merge the trees
                    if (forest.union(best.dest, i)) {
                        // System.out.println(best.dest + " " + i);
                        // System.out.println("different trees " + i +" " +forest.find(i));
                        trees--;
                    } else {
                        // Loop found a loop
                        ArrayList<Edge> curCycle = new ArrayList<Edge>();
                        cycles.add(curCycle);
                        int cur = best.dest;
                        int newLeader = forest.find(i);
                        // System.out.println("Loop " + cur + " " + i);
                        // System.out.println("new Leader is " + newLeader);
                        // System.out.println(Arrays.toString(inComingEdge));
                        double reduction = inComingEdge[newLeader].weight;
                        for (Integer extra : mergedNodes[newLeader]) {
                            for (Edge e : adj[extra]) {
                                e.weight -= reduction;
                                // System.out.println("Adjusting " + e.dest + " " + extra);
                            }
                        }
                        cur = cycle.find(cur);
                        for (;;) {
                            // edit incoming edges
                            // System.out.println("merging " + newLeader + " " + cur);
                            //cur = forest.find(cur);
                            reduction = inComingEdge[cur].weight;

                            // udpate the nodes in the current group
                            if (newLeader != cur) {
                                for (Integer extra : mergedNodes[cur]) {
                                    mergedNodes[newLeader].add(extra);
                                    for (Edge e : adj[extra]) {
                                        if (!e.used)
                                            e.weight -= reduction;
                                        // System.out.println("Adjusting " + e.dest + " " + extra);
                                    }
                                }
                            }

                            cycle.union(newLeader, cur);

                            // Check terminating condition
                            int next = inComingEdge[cur].dest;
                            curCycle.add(inComingEdge[cur]);
                            inComingEdge[cur] = null;
                            cur=next;
                            cur = cycle.find(cur);
                            if (inComingEdge[cur] == null) break;
                        }
                        inComingEdge[newLeader] = null;
                    }
                }
            }
            //System.out.println(trees);

            // BFS and update the answer
            for (int k = cycles.size() - 1; k >= 0; k--) {
                ArrayList<Edge> curCycle = cycles.get(k);
                // System.out.println(curCycle);
                Edge worst = null;
                for (Edge e : curCycle) {
                    if ((worst == null || worst.rev.weight < e.rev.weight) && bfs(result, e.rev.dest, e.dest, root)) {
                        worst = e;
                    }
                }
                result[worst.dest].remove(worst.rev);
                // result[worst.rev.dest].remove(worst);
                // System.out.println(worst.dest +" " +worst.rev.dest);
            }
            for (int i = 0; i < n; i++){
                for (Edge e : result[i]){
                    // System.out.println(i +" " + e.dest);
                    ret += e.oWeight;
                }
            }
            return ret;
        }
        public static boolean bfs(ArrayList<Edge>[] result, int st, int en, int root) {
            int n = result.length;
            int total = 1;
            int[] q = new int[n];
            boolean[] vis = new boolean[n];
            int fptr = 0, bptr = 0;
            vis[q[bptr++] = root] = true;
            while (fptr != bptr) {
                int cur = q[fptr++];
                for (Edge e : result[cur]) {
                    if (!vis[e.dest] && (cur != en || e.dest != st)) {
                        // System.out.println(cur +" " + e.dest );
                        total++;
                        vis[q[bptr++] = e.dest] = true;
                    }
                }
            }
            
            return (total == n);
        }
    /*
        private void getCycle(Node n, AdjacencyList outEdges) {
            System.out.println(n);
            n.visited = true;
            cycle.add(n);
            if (outEdges.getAdjacent(n) == null) {
                return;
            }
            for (Edge e : outEdges.getAdjacent(n)) {
                if (!e.to.visited) {
                    getCycle(e.to, outEdges);
                }
            }
        }
    
        private void mergeCycles(ArrayList<Node> cycle, AdjacencyList list,
                AdjacencyList reverse, AdjacencyList outEdges, AdjacencyList outEdgesReverse) {
            ArrayList<Edge> cycleAllInEdges = new ArrayList<Edge>();
            Edge minInternalEdge = null;
            // find the minimum internal edge weight
            for (Node n : cycle) {
                for (Edge e : reverse.getAdjacent(n)) {
                    if (cycle.contains(e.to)) {
                        if (minInternalEdge == null || minInternalEdge.weight > e.weight) {
                            minInternalEdge = e;
                            continue;
                        }
                    } else {
                        cycleAllInEdges.add(e);
                    }
                }
            }
            // find the incoming edge with minimum modified cost
            Edge minExternalEdge = null;
            double minModifiedWeight = 0;
            for (Edge e : cycleAllInEdges) {
                double w = e.weight - (outEdgesReverse.getAdjacent(e.from).get(0).weight - minInternalEdge.weight);
                if (minExternalEdge == null || minModifiedWeight > w) {
                    minExternalEdge = e;
                    minModifiedWeight = w;
                }
            }
            // add the incoming edge and remove the inner-circuit incoming edge
            Edge removing = outEdgesReverse.getAdjacent(minExternalEdge.from).get(0);
            outEdgesReverse.getAdjacent(minExternalEdge.from).clear();
            outEdgesReverse.addEdge(minExternalEdge.to, minExternalEdge.from, minExternalEdge.weight);
            ArrayList<Edge> adj = outEdges.getAdjacent(removing.to);
            for (int i=0; i < adj.size(); i++) {
                if (adj.get(i).to == removing.from) {
                    adj.remove(i);
                    break;
                }
            }
            outEdges.addEdge(minExternalEdge.to, minExternalEdge.from, minExternalEdge.weight);
        }
        */
    }
}
