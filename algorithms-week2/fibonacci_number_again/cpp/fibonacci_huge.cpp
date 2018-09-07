//
// Created by Sam on 8/3/2018.
//

#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}

long long pisano_period(long long m) {
  if (m == 2) {
    return 3;
  }

  long long previous = 0;
  long long current = 1;

  for (long long i = 2; i < m * m; i++) {
    long long tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % m;

    if (previous == 0 && current == 1) {
      return i+1;
    }
  }
}

long long get_fibonacci_huge(long long n, long long m) {
  if (n <= 1)
    return n;

  long long new_n = n % pisano_period(m);
  long long previous = 0;
  long long current = 1;

  if (new_n <= 1)
    return new_n;

  for (long long i = 1; i < new_n; i++) {
    long long tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % m;
  }

  return current;
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::cout << get_fibonacci_huge(n, m) << '\n';
}
