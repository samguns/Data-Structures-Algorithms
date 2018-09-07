//
// Created by Sam on 2018/9/5.
//

#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  size_t n = A.size();
  if (n < 3) {
    return 0;
  }

  int total = 0;
  for (auto& a : A) {
    total += a;
  }
  if (total % 3 != 0) {
    return 0;
  }

  int mean = total / 3;
  vector<vector<int>> m(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    m[i][i] = A[i];
  }

  for (int s = 1; s < n; s++) {
    for (int i = 0; i < (n-s); i++) {
      int j = i + s;

      m[i][j] = A[j] + m[i][j-1];
    }
  }

  printf("Total: %d  average: %d\n", total, mean);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%5d", m[i][j]);
    }
    std::cout << std::endl;
  }

  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
