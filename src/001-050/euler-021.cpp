#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <numeric>
#include "../divisors.h"

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

  // Since amicable numbers are pairs (a,b) where a != b, we could collapse the
  // two loops into a single one using the following algorithm:
  //   * Find the set s of divisors of i.
  //   * Calculate sum d(i) of elements of d.
  //   * If d(i) < i we can continue the loop because this case has been checked
  //     by a previous iteration, when j = d(i) has been processed.
  //   * If d(i) == i we can continue since i cannot be amicable with itself by
  //     definition.
  //   * If j = d(i) > i, then calculate d(j) and if d(j) == d(i) then (i,j) are
  //     an amicable pair.
  //
  // However, I'll keep this implementation because it's easier to read and
  // performs well enough.
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
