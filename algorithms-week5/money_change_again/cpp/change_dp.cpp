//
// Created by Sam on 8/29/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
  int NumCoins = 0;
  int MinNumCoins[m+1];
  MinNumCoins[0] = 0;

  vector<int> denominator = {1, 3, 4};

  for (int i = 1; i <= m; i++) {
    MinNumCoins[i] = i + 1;

    for (const int& coin : denominator) {
      if (i >= coin) {
        NumCoins = MinNumCoins[i - coin] + 1;
        if (NumCoins < MinNumCoins[i]) {
          MinNumCoins[i] = NumCoins;
        }
      }
    }
  }

  return MinNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
