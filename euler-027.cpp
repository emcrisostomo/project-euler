#include <iostream>
#include "prime.h"
#include <cstdlib>

long get_next_f(unsigned int n, const long& ac, const unsigned long& bc);

// Euler discovered the remarkable quadratic formula:
//
//   n^2+n+41
//
// It turns out that the formula will produce 40 primes for the consecutive
// integer values 0≤n≤39.  However, when n=40, 402+40+41=40(40+1)+41 is
// divisible by 41, and certainly when n=41, 412+41+41 is clearly divisible by
// 41.
//
// The incredible formula n2−79n+1601 was discovered, which produces 80 primes
// for the consecutive values 0≤n≤79.  The product of the coefficients, −79 and
// 1601, is −126479.
//
// Considering quadratics of the form:
//
//   n^2+an+b, where |a|<1000 and |b|≤1000
//
//   where |n| is the modulus/absolute value of n
//   e.g. |11|=11 and |−4|=4
//
// Find the product of the coefficients, a and b, for the quadratic expression
// that produces the maximum number of primes for consecutive values of n,
// starting with n=0.
//
int main()
{
  // Given f(n) = n^2 + an + b, we have:
  //
  //   f(0) = b
  //   f(1) = 1 + a + b
  //
  // from which we infer that:
  //
  //   - b must be a prime number -> b is prime and > 0.
  //   - 1 + a + b must be a prime number -> a is odd and a > -b
  auto b_range = prime::get_primes_smaller_than(1000);
  std::vector<long> a_range;
  a_range.reserve(b_range.size() * 2);

  for (auto iter = b_range.rbegin(); iter != b_range.rend(); ++iter)
  {
    a_range.push_back(*iter * -1);
  }

  for (auto& b : b_range)
  {
    a_range.push_back(b);
  }

  unsigned int consecutive_prime_count{0};
  long coefficient_product{0};

  for (auto b = 0; b < b_range.size(); ++b)
  {
    for (auto a = (a_range.size() - 1) / 2 - b; a < a_range.size(); ++a)
    {
      unsigned int n{0};

      const auto& ac = a_range[a];
      const auto& bc = b_range[b];

      while (prime::is_prime(static_cast<unsigned long>(get_next_f(n, ac, bc))))
      {
        ++n;
      }

      if (n > consecutive_prime_count)
      {
        consecutive_prime_count = n;
        coefficient_product = a_range[a] * b_range[b];
      }
    }
  }

  std::cout << coefficient_product << "\n";
  return 0;
}

long get_next_f(unsigned int n, const long& ac, const unsigned long& bc)
{
  long f = n * n + ac * n + bc;

  return std::abs(f);
}

