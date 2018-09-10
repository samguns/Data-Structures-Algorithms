//
// Created by Sam on 9/10/2018.
//

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

static void dfs(vector<vector<int>>& adj, vector<int>& visited, int v) {
  visited[v] = 1;

  for (int& w : adj[v]) {
    if (visited[w] == 0) {
      dfs(adj, visited, w);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  size_t n = adj.size();
  vector<int> visited(n);

  for (int v = 0; v < n; v++) {
    if (visited[v] == 0) {
      dfs(adj, visited, v);
      res++;
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
