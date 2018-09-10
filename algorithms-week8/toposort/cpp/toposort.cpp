//
// Created by Sam on 9/11/2018.
//

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  used[x] = 1;

  for (int w : adj[x]) {
    if (used[w] == 0) {
      dfs(adj, used, order, w);
    }
  }

  order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj) {
  size_t n = adj.size();
  vector<int> used(n, 0);
  vector<int> order;

  for (int v = 0; v < n; v++) {
    if (used[v] == 0) {
      dfs(adj, used, order, v);
    }
  }

  std::reverse(order.begin(), order.end());
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
