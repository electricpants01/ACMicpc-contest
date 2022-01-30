import java.util.*;

class birth {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        // O(1) for add, remove, and lookup
        Set<String> results = new HashSet<>();

        int n = in.nextInt();

        for (int i = 0; i < n; i++) {
            // add or replace if element already exists
            results.add(in.next());
        }

        System.out.println(results.size());
    }
}