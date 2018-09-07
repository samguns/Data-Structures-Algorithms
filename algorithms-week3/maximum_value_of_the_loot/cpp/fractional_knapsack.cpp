//
// Created by Sam on 8/7/2018.
//

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  size_t items_left = values.size();

  map<double, int, std::greater<>> ratios;
  for (int i = 0; i < values.size(); i++) {
    double key = double(values[i]) / weights[i];
    ratios[key] = i;
  }

  map<double, int, std::greater<>>::iterator it;
  for (it = ratios.begin(); it != ratios.end(); ++it) {
    double r = it->first;
    int idx = it->second;

    if (capacity > 0 && items_left > 0) {
      int pieces = capacity / weights[idx];
      int space = capacity % weights[idx];

      if (0 == pieces && space == capacity) {
        value += (r * space);
      } else {
        value += values[idx];
      }

      capacity -= weights[idx];
      items_left--;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
