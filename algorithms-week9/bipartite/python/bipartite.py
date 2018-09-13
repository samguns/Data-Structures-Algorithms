#Uses python3

import sys
import queue

isBipartite = 1

def bipartite(adj):
    global isBipartite
    n = len(adj)
    visited = [False] * n
    color = [False] * n

    for v in range(n):
        if isBipartite == 0:
            break
        if visited[v] == False:
            bfs(adj, visited, color, v)

    return isBipartite

def bfs(adj, visited, color, s):
    global isBipartite
    q = queue.Queue()
    visited[s] = True
    color[s] = True

    q.put(s)

    while not q.empty():
        v = q.get()

        for w in adj[v]:
            if visited[w] == False:
                visited[w] = True
                color[w] = not color[v]
                q.put(w)
            elif color[v] == color[w]:
                isBipartite = 0
                return

    return

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(bipartite(adj))
