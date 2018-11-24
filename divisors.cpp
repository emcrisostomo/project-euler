//
// Created by enrico on 11/24/18.
//

#include "divisors.h"
#include <cmath>

std::vector<unsigned int> divisors::proper_divisors_of(unsigned int n)
{
  if (n == 0) return {};

  std::vector<unsigned int> d;
  d.push_back(1);
  const auto s = static_cast<const unsigned int>(sqrt(n));

  for (unsigned int i = 2; i < s; ++i)
  {
    if (n % i == 0)
    {
      d.push_back(i);
      d.push_back(n / i);
    }
  }

  if (n % s == 0) d.push_back(s);

  return d;
}