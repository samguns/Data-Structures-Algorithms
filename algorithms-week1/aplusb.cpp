//
// Created by Sam on 2018/8/1.
//

#include <iostream>

int sum_of_two_digits(int first_digit, int second_digit) {
  return first_digit + second_digit;
}

int main() {
  int a = 0;
  int b = 0;
  std::cin >> a;
  std::cin >> b;
  std::cout << sum_of_two_digits(a, b);
  return 0;
}