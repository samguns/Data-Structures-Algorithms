//
// Created by Sam on 2018/8/1.
//

#include <iostream>
#include <vector>
#include <algorithm>


int64_t MaxPairwiseProduct(std::vector<int64_t >& numbers) {
  int64_t max_product = 0;
  size_t n = numbers.size();

  std::sort(numbers.begin(), numbers.end());

  max_product = numbers[n-1] * numbers[n-2];

  return max_product;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int64_t > numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  int64_t result = MaxPairwiseProduct(numbers);
  std::cout << result << "\n";
  return 0;
}
