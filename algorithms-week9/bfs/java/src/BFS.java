import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
    private static int distance(ArrayList<Integer>[] adj, int s, int t) {
        int n = adj.length;
        int[] dist = new int[n];
        Queue<Integer> q = new LinkedList<>();

        for (int v = 0; v < n; v++) {
            dist[v] = -1;
        }

        dist[s] = 0;
        q.add(s);

        bfs(adj, dist, q);
        return dist[t];
    }

    private static void bfs(ArrayList<Integer>[] adj, int[] dist, Queue<Integer> q) {
        while (!q.isEmpty()) {
            int v = q.poll();

            for (int w : adj[v]) {
                if (dist[w] == -1) {
                    q.add(w);
                    dist[w] = dist[v] + 1;
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
        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        System.out.println(distance(adj, x, y));
    }
}

