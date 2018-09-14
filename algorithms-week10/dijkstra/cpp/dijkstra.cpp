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

struct indexWeight {
  int index;
  int weight;
};

class weight_comp {
 public:
  bool operator() (const indexWeight& lhs, const indexWeight& rhs) const {
    return (lhs.weight > rhs.weight);
  }
};

typedef priority_queue<int, weight_comp> indexMinPQ;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  size_t n = adj.size();
  vector<int> dist(n, INT_MAX);
  indexMinPQ pq(weight_comp);

  dist[s] = 0;
  pq.
  return -1;
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
