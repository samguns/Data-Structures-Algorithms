//
// Created by Sam on 9/18/2018.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  size_t n = adj.size();
  vector<bool> updated(n, false);

  for (int s = 0; s < n; s++) {
    if (updated[s]) {
      continue;
    }
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[s] = 0;
    q.emplace(s);
    int count = 0;

    while (!q.empty()) {
      if (count == n) {
        return 1;
      }

      int v = q.front();
      q.pop();

      for (int i = 0; i < adj[v].size(); i++) {
        int w = adj[v][i];
        int weight = dist[v] + cost[v][i];

        if (dist[w] > weight) {
          count++;
          updated[w] = true;
          if (w == s) {
            return 1;
          }
          dist[w] = weight;
          q.emplace(w);
        }

      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
