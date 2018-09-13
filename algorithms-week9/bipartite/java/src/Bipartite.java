import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Bipartite {
    static int isBipartite = 1;
    private static int bipartite(ArrayList<Integer>[] adj) {
        int n = adj.length;
        boolean[] color = new boolean[n];
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();

        for (int v = 0; (v < n) && (isBipartite == 1); v++) {
            if (!visited[v]) {
                bfs(adj, visited, color, v);
            }
        }
        return isBipartite;
    }

    private static void bfs(ArrayList<Integer>[] adj, boolean[] visited, boolean[] color, int s) {
        Queue<Integer> q = new LinkedList<>();
        visited[s] = true;
        color[s] = true;

        q.add(s);
        while (!q.isEmpty()) {
            int v = q.poll();
            for (int w : adj[v]) {
                if (!visited[w]) {
                    q.add(w);
                    color[w] = !color[v];
                    visited[w] = true;
                } else if (color[w] == color[v]) {
                    isBipartite = 0;
                    return;
                }
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
            adj[y - 1].add(x - 1);
        }
        System.out.println(bipartite(adj));
    }
}

