//
// Created by Sam on 2018/8/2.
//

#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd(int a, int b) {
  if (a > b) {
    if (b == 0) {
      return a;
    } else {
      return gcd(b, a % b);
    }
  } else if (a < b) {
    if (a == 0) {
      return b;
    } else {
      return gcd(a, b % a);
    }
  } else {
    return a;
  }
}

long long lcm(int a, int b) {
  int d = gcd(a, b);

  return (a / d) * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
//  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
