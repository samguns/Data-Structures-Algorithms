import java.util.ArrayList;
import java.util.Scanner;

public class Acyclicity {
    private static int hasCycle = 0;

    private static int acyclic(ArrayList<Integer>[] adj) {
        int n = adj.length;
        boolean[] visited = new boolean[n];
        boolean[] onStack = new boolean[n];

        for (int v = 0; v < n; v++) {
            if (hasCycle == 1) {
                break;
            }

            if (!visited[v]) {
                dfs(adj, visited, onStack, v);
            }
        }
        return hasCycle;
    }

    private static void dfs(ArrayList<Integer>[] adj,
                            boolean[] visited,
                            boolean[] onStack,
                            int v) {
        visited[v] = true;
        onStack[v] = true;

        for (int w : adj[v]) {
            if (hasCycle == 1) {
                return;
            } else if (!visited[w]) {
                dfs(adj, visited, onStack, w);
            } else if (onStack[w]) {
                hasCycle = 1;
            }
        }

        onStack[v] = false;
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
        System.out.println(acyclic(adj));
    }
}

