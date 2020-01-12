#include <iostream>
#include "number.h"
#include <gmpxx.h>

// A googol (10^{100}) is a massive number: one followed by one-hundred zeros;
// 100100 is almost unimaginably large: one followed by two-hundred zeros.
// Despite their size, the sum of the digits in each number is only 1.
//
// Considering natural numbers of the form, a^b, where a, b < 100, what is the
// maximum digital sum?
//
int main(int argc, char *argv[])
{
  unsigned long max_sum{0};

  for (int a = 99; a > 1; --a)
  {
    for (int b = 99; b > 1; --b)
    {
      size_t sum{0};

      mpz_class base{a};
      mpz_class ret{a};
      mpz_pow_ui(ret.get_mpz_t(), base.get_mpz_t(), b);

      const std::string& number_str = ret.get_str(10);

      for (auto i = 0; i < number_str.size(); ++i)
      {
        sum += std::stoi(number_str.substr(i, 1));
      }

      max_sum = std::max(max_sum, sum);
    }
  }

  std::cout << max_sum << '\n';
  return 0;
}
