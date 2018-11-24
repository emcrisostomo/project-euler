#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <numeric>
#include "divisors.h"

// Let d(n) be defined as the sum of proper divisors of n (numbers less than n
// which divide evenly into n).  If d(a) = b and d(b) = a, where a ≠ b, then a
// and b are an amicable pair and each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
// 55 and 110; therefore d(220) = 284.  The proper divisors of 284 are 1, 2, 4,
// 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 10000.
//
int main()
{
  std::map<unsigned int, unsigned int> sum_of_divisors_by_n;
  std::vector<unsigned int> amicable_numbers;

  for (unsigned int i = 1; i < 10000; ++i)
  {
    std::vector<unsigned int> d = divisors::proper_divisors_of(i);
    sum_of_divisors_by_n[i] = std::accumulate(d.begin(), d.end(), 0u);
  }

  for (unsigned int i = 1; i < 10000; ++i)
  {
    const auto& d = sum_of_divisors_by_n[i];
    if (i == d) continue;
    if (i == sum_of_divisors_by_n[d])
      amicable_numbers.push_back(i);
  }

  unsigned int sum = std::accumulate(amicable_numbers.begin(), amicable_numbers.end(), 0u);

  std::cout << sum << "\n";
  return 0;
}
