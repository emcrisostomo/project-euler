#include <iostream>
#include <numeric>
#include <set>
#include "divisors.h"

// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number.  For example, the sum of the proper divisors of
// 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper divisors is less than
// n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
// number that can be written as the sum of two abundant numbers is 24.  By
// mathematical analysis, it can be shown that all integers greater than 28123
// can be written as the sum of two abundant numbers.  However, this upper limit
// cannot be reduced any further by analysis even though it is known that the
// greatest number that cannot be expressed as the sum of two abundant numbers
// is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the sum
// of two abundant numbers.
//
int main()
{
  const unsigned int limit = 28123;
  std::vector<unsigned int> abundant_numbers;
  std::vector<bool> sums_of_abundant_numbers(limit + 1, false);

  for (unsigned int i = 2; i <= limit; ++i)
  {
    auto d = divisors::proper_divisors_of(i);
    auto sum = std::accumulate(d.begin(), d.end(), 0u);

    if (sum > i) abundant_numbers.push_back(i);
  }

  for (auto i = 0; i < abundant_numbers.size(); ++i)
  {
    for (auto j = i; j < abundant_numbers.size(); ++j)
    {
      auto sum = abundant_numbers[i] + abundant_numbers[j];

      if (sum > limit) break;

      sums_of_abundant_numbers[sum] = true;
    }
  }

  unsigned int sum{0};
  for (auto i = 1; i < sums_of_abundant_numbers.size(); ++i)
  {
    if (!sums_of_abundant_numbers[i])
      sum += i;
  }

  std::cout << sum << "\n";
  return 0;
}
