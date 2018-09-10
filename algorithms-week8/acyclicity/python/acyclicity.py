#Uses python3

import sys

hasCycle = 0

def acyclic(adj):
    global hasCycle
    n = len(adj)
    visited = [False] * n
    onStack = [False] * n

    for v in range(n):
        if hasCycle == 1:
            return hasCycle

        if not visited[v]:
            dfs(adj, visited, onStack, v)

    return 0

def dfs(adj, visited, onStack, v):
    global hasCycle
    visited[v] = True
    onStack[v] = True

    for w in adj[v]:
        if hasCycle == 1:
            return

        if not visited[w]:
            dfs(adj, visited, onStack, w)
        elif onStack[w]:
            hasCycle = 1
            return

    onStack[v] = False

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))
