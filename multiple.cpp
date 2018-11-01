//
// Created by Enrico M. Crisostomo on 03/09/2018.
//

#include "multiple.h"
#include <stdexcept>
#include <cmath>

unsigned int multiple::of_all(unsigned int from, unsigned int to)
{
  if (to < from) throw std::invalid_argument("last must be equal to or greater than first");
  if (from == to) return from;

  if (from == 1) from = 2;

  unsigned int lcm = from;

  for (auto i = from; i <= to; ++i)
  {
    auto sum = lcm;

    while (sum % i != 0) sum += lcm;

    lcm = sum;
  }

  return lcm;
}

unsigned long long multiple::largest_prime_factor_of(unsigned long long number)
{
  if (number == 0) return 0;

  auto n = number;

  for (auto i = 2; i <= n / 2; ++i)
  {
    if (n % i == 0)
    {
      n /= i;
      i = 1;
    }
  }

  return n;
}