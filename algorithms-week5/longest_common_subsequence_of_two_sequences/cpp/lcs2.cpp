//
// Created by Sam on 2018/9/2.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

void backtrace(vector<int> &a, vector<int> &b, int n, int m, int *l) {
  vector<int> lcs;
  int (*L)[m+1] = (int (*)[(m + 1)])l;

  while (n > 0 || m > 0) {
    if (a[n-1] == b[m-1]) {
      lcs.push_back(a[n-1]);
      n--;
      m--;
    } else {
      if (L[n][m-1] < L[n-1][m]) {
        n--;
      } else {
        m--;
      }
    }
  }

  reverse(lcs.begin(), lcs.end());
  for (int& i : lcs) {
    printf("%d, ", i);
  }
  printf("\n");
}

int lcs2(vector<int> &a, vector<int> &b) {
  size_t n = a.size();
  size_t m = b.size();
  int L[n+1][m+1];

  for (int j = 0; j <= m; j++) {
    for (int i = 0; i <= n; i++) {
      if (i == 0 || j == 0) {
        L[i][j] = 0;
      } else if (a[i-1] == b[j-1]) {
        L[i][j] = L[i-1][j-1] + 1;
      } else {
        int left = L[i-1][j];
        int top = L[i][j-1];
        L[i][j] = max(left, top);
      }
    }
  }

  backtrace(a, b, n, m, (int *)L);
  return L[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
