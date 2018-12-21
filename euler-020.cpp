#include <iostream>
#include <gmpxx.h>
#include <string>
#include "factorial.h"

// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!
//
int main()
{
  mpz_class n{100};
  n = factorial::of(n);

  const auto& n_str = n.get_str(10);
  unsigned long sum{0};
  for (auto c : n_str)
  {
    sum += c - '0';
  }

  std::cout << sum << "\n";
  return 0;
}
