import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class StronglyConnected {
    private static int numberOfStronglyConnectedComponents(ArrayList<Integer>[] adj) {
        int n = adj.length;
        ArrayList<Integer>[] reverseAdj = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            reverseAdj[i] = new ArrayList<>();
        }
        for (int v = 0; v < n; v++) {
            for (int w : adj[v]) {
                reverseAdj[w].add(v);
            }
        }
        ArrayList<Integer> order = toposort(reverseAdj);

        boolean[] used = new boolean[n];
        int scc = 0;

        for (int v : order) {
            if (!used[v]) {
                dfs(adj, used, v);
                scc++;
            }
        }
        return scc;
    }

    private static ArrayList<Integer> toposort(ArrayList<Integer>[] adj) {
        int n = adj.length;
        boolean[] used = new boolean[n];
        ArrayList<Integer> order = new ArrayList<>(n);

        for (int v = 0; v < n; v++) {
            if (!used[v]) {
                dfs(adj, used, order, v);
            }
        }

        Collections.reverse(order);
        return order;
    }

    private static void dfs(ArrayList<Integer>[] adj,
                            boolean[] used,
                            ArrayList<Integer> order,
                            int v) {
        used[v] = true;

        for (int w : adj[v]) {
            if (!used[w]) {
                dfs(adj, used, order, w);
            }
        }

        order.add(v);
    }

    private static void dfs(ArrayList<Integer>[] adj,
                            boolean[] used,
                            int v) {
        used[v] = true;

        for (int w : adj[v]) {
            if (!used[w]) {
                dfs(adj, used, w);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
        }
        System.out.println(numberOfStronglyConnectedComponents(adj));
    }
}

