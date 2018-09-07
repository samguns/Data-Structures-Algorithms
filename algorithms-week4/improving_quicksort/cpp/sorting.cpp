//
// Created by Sam on 8/16/2018.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int>& a, int l, int r, int& lt, int& gt) {
  int x = a[l];
  int i = l + 1;

  while (i <= gt) {
    if (a[i] < x) {
      swap(a[lt], a[i]);
      i++;
      lt++;
    } else if (a[i] > x) {
      swap(a[i], a[gt]);
      gt--;
    } else {
      i++;
    }
  }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  int lt = l;
  int gt = r;
  partition3(a, l, r, lt, gt);
  randomized_quick_sort(a, l, lt-1);
  randomized_quick_sort(a, gt+1, r);
//  int m = partition2(a, l, r);
//
//  randomized_quick_sort(a, l, m - 1);
//  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
