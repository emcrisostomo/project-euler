#include <iostream>
#include <gmpxx.h>
#include <string>

mpz_class factorial(const mpz_class& n);

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
  n = factorial(n);

  const auto& n_str = n.get_str(10);
  unsigned long sum{0};
  for (auto c : n_str)
  {
    sum += std::stoul(std::string(1, c), nullptr);
  }

  std::cout << sum << "\n";
  return 0;
}

mpz_class factorial(const mpz_class& n)
{
  if (n <= 1) return 1;

  return n * factorial(n - 1);
}
