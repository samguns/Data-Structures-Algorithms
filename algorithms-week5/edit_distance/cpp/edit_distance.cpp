//
// Created by Sam on 2018/9/1.
//

#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  size_t n = str1.length();
  size_t m = str2.length();
  int D[n+1][m+1];

  for (int i = 0; i <= n; i++) {
    D[i][0] = i;
  }

  for (int j = 0; j <= m; j++) {
    D[0][j] = j;
  }

  for (size_t j = 1; j <= m; j++) {
    for (size_t i = 1; i <= n; i++) {
      int insertion = D[i][j-1] + 1;
      int deletion = D[i-1][j] + 1;
      int match = D[i-1][j-1];
      int mismatch = D[i-1][j-1] + 1;

      D[i][j] = min(insertion, deletion);
      if (str1.at(i-1) == str2.at(j-1)) {
        D[i][j] = min(D[i][j], match);
      } else {
        D[i][j] = min(D[i][j], mismatch);
      }
    }
  }

  return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
