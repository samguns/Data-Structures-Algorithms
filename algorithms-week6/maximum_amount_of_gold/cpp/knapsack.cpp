//
// Created by Sam on 2018/9/4.
//

#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  size_t n = w.size();
  vector<vector<int>> values(n+1, vector<int>(W+1));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
      if ((i == 0) || (j == 0)) {
        values[i][j] = 0;
        continue;
      }

      values[i][j] = values[i-1][j];
      int wi = w[i-1];
      if (wi <= j) {
        int val = values[i-1][j-wi] + wi;

        if (values[i][j] < val) {
          values[i][j] = val;
        }
      }
    }
  }

  return values[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
