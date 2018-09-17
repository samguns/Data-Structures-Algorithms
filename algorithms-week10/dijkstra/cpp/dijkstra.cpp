//
// Created by Sam on 9/14/2018.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

class indexWeight {
 public:
  int index;
  int weight;
  indexWeight(int i, int w) {
    index = i;
    weight = w;
  }
};

class weight_comp {
 public:
  bool operator() (const indexWeight& lhs, const indexWeight& rhs) const {
    return (lhs.weight > rhs.weight);
  }
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  size_t n = adj.size();
  vector<int> dist(n, INT_MAX);
  priority_queue<indexWeight, vector<indexWeight>, weight_comp> pq;

  dist[s] = 0;
  pq.emplace(indexWeight(s, dist[s]));

  while (!pq.empty()) {
    indexWeight iw = pq.top();
    pq.pop();
    int v = iw.index;

    for (int i = 0; i < adj[v].size(); i++) {
      int w = adj[v][i];
      int d = dist[v] + cost[v][i];

      if (dist[w] > d) {
        dist[w] = d;
        pq.push(indexWeight(w, dist[w]));
      }
    }
  }

  if (dist[t] == INT_MAX) {
    return -1;
  }
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
