# Uses python3

import sys

sys.setrecursionlimit(200000)


def topological(digraph):
    n = len(digraph)
    visited = [False] * n
    order = []

    for v in range(n):
        if visited[v] == False:
            dfs(digraph, visited, v, order)

    return reversed(order)


def dfs(adj, visited, v, order=None):
    visited[v] = True

    for w in adj[v]:
        if visited[w] == False:
            dfs(adj, visited, w, order)

    if order is not None:
        order.append(v)


def number_of_strongly_connected_components(adj):
    result = 0
    n = len(adj)
    visited = [False] * n
    reverse = [[] for _ in range(n)]
    for v in range(n):
        for w in adj[v]:
            reverse[w].append(v)

    topo = topological(reverse)

    for v in topo:
        if visited[v] == False:
            dfs(adj, visited, v)
            result += 1

    return result


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(number_of_strongly_connected_components(adj))
