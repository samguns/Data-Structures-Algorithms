//
// Created by Sam on 9/11/2018.
//

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

static void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v, vector<int>& order) {
  visited[v] = true;

  for (int& w : adj[v]) {
    if (!visited[w]) {
      dfs(adj, visited, w, order);
    }
  }

  order.push_back(v);
}

static void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v) {
  visited[v] = true;

  for (int& w : adj[v]) {
    if (!visited[w]) {
      dfs(adj, visited, w);
    }
  }
}

static vector<int> topological(vector<vector<int>>& digraph) {
  size_t n = digraph.size();
  vector<int> order(n);
  vector<bool> visited(n);

  for (int v = 0; v < n; v++) {
    if (!visited[v]) {
      dfs(digraph, visited, v, order);
    }
  }

  std::reverse(order.begin(), order.end());
  return order;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  size_t n = adj.size();
  vector<bool> visited(n, false);
  vector<vector<int>> reverseAdj(n, vector<int>());
  for (int v = 0; v < n; v++) {
    for (int w : adj[v]) {
      reverseAdj[w].push_back(v);
    }
  }

  vector<int> topo = topological(reverseAdj);
  for (int& v : topo) {
    if (!visited[v]) {
      dfs(adj, visited, v);
      result++;
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
