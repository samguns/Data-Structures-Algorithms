//
// Created by Sam on 8/31/2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  vector<int> ops = {0, 0};
  vector<int> divider = {2, 3};

  for (int i = 2; i <= n; i++) {
    ops.push_back(ops[i-1] + 1);

    for (const int& div : divider) {
      if ((i % div) == 0) {
        int min = ops[i / div];
        if (min < ops[i]) {
          ops[i] = min + 1;
        }
      }
    }
  }

  vector<int> sequence;
  sequence.push_back(n);
  while (n > 1) {
    int min_op = ops[n-1];
    int m = n - 1;

    for (const int& div : divider) {
      if ((n % div) == 0) {
        int op = ops[n / div];
        if (op < min_op) {
          min_op = op;
          m = n / div;
        }
      }
    }

    sequence.push_back(m);
    n = m;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (int i : sequence) {
    std::cout << i << " ";
  }
}
