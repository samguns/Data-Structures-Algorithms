//
// Created by Sam on 2018/9/10.
//

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

static int hasCycle = 0;

static void dfs(vector<vector<int>>& adj,
    vector<bool>& visited, vector<bool>& onStack, int v) {
  visited[v] = true;
  onStack[v] = true;

  for (int& w : adj[v]) {
    if (hasCycle == 1) {
      return;
    }

    if (!visited[w]) {
      dfs(adj, visited, onStack, w);
    } else if (onStack[w]) {
      hasCycle = 1;
      return;
    }
  }

  onStack[v] = false;
}

int acyclic(vector<vector<int> > &adj) {
  size_t n = adj.size();
  vector<bool> visited(n);
  vector<bool> onStack(n);

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

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
