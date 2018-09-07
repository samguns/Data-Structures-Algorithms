//
// Created by Sam on 2018/9/6.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using std::vector;
using std::string;
using std::stoll;
using std::numeric_limits;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void MinAndMax(int i, int j, const vector<vector<long long>>& m,
               const vector<vector<long long>>& M, const vector<char>& op,
               long long& min, long long& max) {
  for (int k = i; k < j; k++) {
    long long a = eval(M[i][k], M[k+1][j], op[k]);
    long long b = eval(M[i][k], m[k+1][j], op[k]);
    long long c = eval(m[i][k], M[k+1][j], op[k]);
    long long d = eval(m[i][k], m[k+1][j], op[k]);

    min = std::min(min, a);
    min = std::min(min, b);
    min = std::min(min, c);
    min = std::min(min, d);
    max = std::max(max, a);
    max = std::max(max, b);
    max = std::max(max, c);
    max = std::max(max, d);
  }
}

long long get_maximum_value(const string &exp) {
  vector<long long> d;
  vector<char> op;
  size_t exp_len = exp.length();
  size_t n = (exp_len + 1) / 2;
  vector<vector<long long>> m(n, vector<long long>(n));
  vector<vector<long long>> M(n, vector<long long>(n));

  for (int i = 0; i < exp_len; i++) {
    if (i % 2 == 0) {
      d.push_back(exp[i] - '0');
    } else {
      op.push_back(exp[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    m[i][i] = d[i];
    M[i][i] = d[i];
  }

  for (int s = 1; s < n; s++) {
    for (int i = 0; i < (n-s); i++) {
      int j = i + s;
      long long min = numeric_limits<long long>::max();
      long long max = -numeric_limits<long long>::max();

      MinAndMax(i, j, m, M, op, min, max);
      m[i][j] = min;
      M[i][j] = max;
    }
  }

  return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
