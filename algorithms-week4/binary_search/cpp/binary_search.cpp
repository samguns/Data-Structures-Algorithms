//
// Created by Sam on 8/13/2018.
//

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size();
  int middle = right / 2;

  if (a[left] > x || a[right-1] < x) {
    return -1;
  }

  if (a[middle] == x) {
    return middle;
  } else if (middle == 0) {
    return -1;
  }

  if (a[middle] > x) {
    return binary_search(vector<int>(a.begin(), a.begin()+middle), x);
  } else {
    int found = binary_search(vector<int>(a.begin()+middle+1, a.end()), x);
    if (found != -1) {
      found += (middle + 1);
    }

    return found;
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
