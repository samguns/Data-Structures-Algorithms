import java.util.*;

public class Dijkstra {
    public static class IndexMinPQ<Key extends Comparable<Key>> {
        private int maxN;
        private int n;
        private int[] pq;
        private int[] qp;
        private Key[] keys;

        public IndexMinPQ(int maxN) {
            this.maxN = maxN;
            n = 0;
            keys = (Key[]) new Comparable[maxN+1];
            pq = new int[maxN + 1];
            qp = new int[maxN + 1];
            for (int i = 0; i <= maxN; i++) {
                qp[i] = -1;
            }
        }

        public void insert(int i, Key key) {
            if (i < 0 || i >= maxN) {
                throw new IllegalArgumentException();
            }

            if (contains(i)) {
                throw new IllegalArgumentException("index is already in the priority queue");
            }

            n++;
            qp[i] = n;
            pq[n] = i;
            keys[i] = key;
            swim(n);
        }

        public int delMin() {
            if (n == 0) {
                throw new NoSuchElementException("Priority queue underflow");
            }

            int min = pq[1];
            exch(1, n--);
            sink(1);
            assert min == pq[n+1];
            qp[min] = -1;
            keys[min] = null;
            pq[n+1] = -1;
            return min;
        }

        public boolean isEmpty() {
            return n == 0;
        }

        public boolean contains(int i) {
            if (i < 0 || i >= maxN) {
                throw new IllegalArgumentException();
            }

            return qp[i] != -1;
        }

        public void decreaseKey(int i, Key key) {
            if (keys[i].compareTo(key) <= 0) {
                throw new IllegalArgumentException();
            }

            keys[i] = key;
            swim(qp[i]);
        }

        private boolean greater(int i, int j) {
            return keys[pq[i]].compareTo(keys[pq[j]]) > 0;
        }

        private void exch(int i, int j) {
            int swap = pq[i];
            pq[i] = pq[j];
            pq[j] = swap;
            qp[pq[i]] = i;
            qp[pq[j]] = j;
        }

        private void swim(int k) {
            while (k > 1 && greater(k/2, k)) {
                exch(k, k/2);
                k = k / 2;
            }
        }

        private void sink(int k) {
            while (2 * k <= n) {
                int j = 2 * k;
                if (j < n && greater(j, j+1)) {
                    j++;
                }

                if (!greater(k, j)) {
                    break;
                }

                exch(k, j);
                k = j;
            }
        }
    }

    private static int distance(ArrayList<Integer>[] adj, ArrayList<Integer>[] cost, int s, int t) {
        int n = adj.length;
        int[] dist = new int[n];
        int[] prev = new int[n];
        IndexMinPQ<Integer> pq = new IndexMinPQ<>(n);

        for (int u = 0; u < n; u++) {
            dist[u] = Integer.MAX_VALUE;
            prev[u] = -1;
        }

        dist[s] = 0;
        pq.insert(s, dist[s]);

        while (!pq.isEmpty()) {
            int v = pq.delMin();

            for (int i = 0; i < adj[v].size(); i++) {
                int w = adj[v].get(i);

                if (dist[w] > dist[v] + cost[v].get(i)) {
                    dist[w] = dist[v] + cost[v].get(i);
                    prev[w] = v;

                    if (pq.contains(w)) {
                        pq.decreaseKey(w, dist[w]);
                    } else {
                        pq.insert(w, dist[w]);
                    }
                }
            }
        }

        if (dist[t] == Integer.MAX_VALUE) {
            return -1;
        }
        return dist[t];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        ArrayList<Integer>[] cost = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
            cost[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y, w;
            x = scanner.nextInt();
            y = scanner.nextInt();
            w = scanner.nextInt();
            adj[x - 1].add(y - 1);
            cost[x - 1].add(w);
        }
        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        System.out.println(distance(adj, cost, x, y));
    }
}

