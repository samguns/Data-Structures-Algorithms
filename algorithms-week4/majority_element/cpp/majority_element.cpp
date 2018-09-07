//
// Created by Sam on 8/14/2018.
//

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

//int get_majority_element(vector<int> &a, int left, int right) {
//  if (left == right) return -1;
//  if (left + 1 == right) return a[left];
//  //write your code here
//  return -1;
//}
//static int get_majority_element(vector<int>& a, int left, int right) {
//  map<int, int> count_map;
//  for (int i = left; i < right; i++) {
//    count_map[a[i]]++;
//  }
//
//  int middle = right / 2;
//  int mod = right % 2;
//  if (count_map.size() <= (middle + mod)) {
//    return 1;
//  }
//
//  return -1;
//}

static int get_majority_element(vector<int>& a, int left, int right) {
  int maj_index = left;
  int count = 1;

  for (int i = 1; i < right; i++) {
    if (a[maj_index] == a[i]) {
      count++;
    } else {
      count--;
    }

    if (count == 0) {
      maj_index = i;
      count = 1;
    }
  }

  count = 0;
  for (int i = left; i < right; i++) {
    if (a[i] == a[maj_index]) {
      count++;
    }
  }

  if (count > right/2) {
    return 1;
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  //std::cout << (get_majority_element(a, n) != -1) << '\n';
}
