#Uses python3

import sys
import queue


def distance(adj, cost, s, t):
    n = len(adj)
    dist = [sys.maxsize] * n
    pq = queue.PriorityQueue(n)

    dist[s] = 0
    pq.put([dist[s], s])

    while not pq.empty():
        _, v = pq.get()

        for i in range(len(adj[v])):
            w = adj[v][i]
            d = dist[v] + cost[v][i]
            if dist[w] > d:
                dist[w] = d
                pq.put([dist[w], w])

    if dist[t] == sys.maxsize:
        return -1
    return dist[t]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    s, t = data[0] - 1, data[1] - 1
    print(distance(adj, cost, s, t))
