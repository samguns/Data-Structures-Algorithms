//
// Created by Sam on 9/13/2018.
//

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

static int isBipartite = 1;

static void bfs(vector<vector<int>>& adj,
    vector<bool>& visited,
    vector<bool>& color,
    int s) {
  visited[s] = true;
  color[s] = true;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int& w : adj[v]) {
      if (!visited[w]) {
        visited[w] = true;
        color[w] = !color[v];
        q.push(w);
      } else if (color[v] == color[w]) {
        isBipartite = 0;
        return;
      }
    }
  }
}

int bipartite(vector<vector<int> > &adj) {
  size_t n = adj.size();
  vector<bool> visited(n);
  vector<bool> color(n);

  for (int v = 0; (v < n) && (isBipartite == 1); v++) {
    if (!visited[v]) {
      bfs(adj, visited, color, v);
    }
  }
  return isBipartite;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
