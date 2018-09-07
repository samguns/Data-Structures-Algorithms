//
// Created by Sam on 8/7/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
  int n = 0;
  vector<int> denominations({10, 5, 1});

  for (int& d : denominations) {
    n += (m / d);
    m %= d;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
