#include <iostream>
#include <cmath>

// The 5-digit number, 16807=7^5, is also a fifth power.  Similarly, the 9-digit
// number, 134217728=8^9, is a ninth power.
//
// How many n-digit positive integers exist which are also an nth power?
//
int
main(int argc, char *argv[])
{
  // The problem asks how many integer powers a^n have n digits.  Intuition
  // suggests that if a >= 10, then no such number exists.  In fact, being L(x)
  // the number of digits in x, then:
  //
  //   L(a^n) = floor(1 + log_{10} a^n) = floor(1 + n log_{10} a)
  //   L(a^n) > n => floor(1 + n log_{10} a) > n
  //              => floor(n log_{10} a) > n - 1
  //              => log_{10} a > 1
  //              => a > 10
  //
  // To find an upper bound for the exponent, when a^n has n digits then:
  //
  //   10^{n - 1} <= a^n < 10^n
  //
  // Since a < 10, the exponential in base 10 will eventually outgrow a^n:
  //
  //   lim_{n \goto \infty} \frac{10^{n - 1}}{a^n} = \infty
  //
  // Hence, the number of integer powers a^n with n digits, for each given base
  // a \in \N, will be the maximum n for which the following is true:
  //
  //      10^{n - 1} <= a^n
  //   => 10^n / 10 <= a^n
  //   => log(10^n / 10) <= log(a^n)
  //   => n log(10) - log(10) <= n log(a)
  //   => n <= \frac{log(10)}{log(10) - log(a)}
  //
  // Summing over a \in [1, 9] gives the solution:
  //
  //   \sum_{a=1}^9 \frac{log(10)}{log(10) - log(a)}
  //
  size_t count{0};

  for (int a = 1; a <= 9; ++a)
  {
    count += log(10) / (log(10) - log(a));
  }

  std::cout << count << '\n';
}
