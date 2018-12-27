#include <iostream>
#include "../prime.h"
#include <gmpxx.h>

unsigned int get_repeating_decimal_length(unsigned long prime);

// A unit fraction contains 1 in the numerator.  The decimal representation of
// the unit fractions with denominators 2 to 10 are given:
//
//   1/2	= 	0.5
//   1/3	= 	0.(3)
//   1/4	= 	0.25
//   1/5	= 	0.2
//   1/6	= 	0.1(6)
//   1/7	= 	0.(142857)
//   1/8	= 	0.125
//   1/9	= 	0.(1)
//   1/10	= 	0.1
//
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.  It can
// be seen that 1/7 has a 6-digit recurring cycle.
//
// Find the value of d < 1000 for which 1/d contains the longest recurring
// cycle in its decimal fraction part.
//
int main()
{
  auto primes = prime::get_primes_smaller_than(1000);

  unsigned int max_length_prime;
  unsigned int max_length{0};

  for (unsigned long prime : primes)
  {
    auto p = prime;
    auto length = get_repeating_decimal_length(p);

    if (length > max_length)
    {
      max_length = length;
      max_length_prime = prime;
    }
  }

  std::cout << max_length_prime << "\n";
  return 0;
}

unsigned int get_repeating_decimal_length(unsigned long prime)
{
  // The length of the repetend of 1/p when p is prime is x satisfying:
  //
  //   10^x \equiv 1 (\mod p)
  for (unsigned int i = 1; i < prime; ++i)
  {
    mpz_class ten{10};
    mpz_pow_ui(ten.get_mpz_t(), ten.get_mpz_t(), i);
    ten = ten - 1;

    if (ten % prime == 0)
      return i;
  }

  return 0;
}
