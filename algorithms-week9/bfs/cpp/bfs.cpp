//
// Created by Sam on 9/12/2018.
//

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

static void bfs(vector<vector<int>>& adj, vector<int>& dist, queue<int>& q) {
  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int& w : adj[v]) {
      if (dist[w] == -1) {
        q.push(w);
        dist[w] = dist[v] + 1;
      }
    }
  }
}

int distance(vector<vector<int> > &adj, int s, int t) {
  size_t n = adj.size();
  vector<int> dist(n, -1);
  queue<int> q;

  dist[s] = 0;
  q.push(s);

  bfs(adj, dist, q);
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
