//
// Created by enrico on 11/24/18.
//

#ifndef PROJECT_EULER_DIVISORS_H
#define PROJECT_EULER_DIVISORS_H

#include <vector>
#include <cmath>

namespace divisors
{
  template<typename T>
  std::vector<T> proper_divisors_of(T n);
};

template<typename T>
std::vector<T> divisors::proper_divisors_of(T n)
{
  if (n == 0) return {};

  std::vector<T> d;
  d.push_back(1);
  const auto s = static_cast<const T>(sqrt(n));

  for (T i = 2; i <= s; ++i)
  {
    if (n % i == 0)
    {
      d.push_back(i);
      d.push_back(n / i);
    }
  }

  // sqrt(n) is inserted twice when n is a square number.
  if (s * s == n) d.pop_back();

  return d;
}

#endif //PROJECT_EULER_DIVISORS_H
