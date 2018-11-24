#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<unsigned int> proper_divisors(unsigned int n);
unsigned int sum_of(std::vector<unsigned int> v);

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
    std::vector<unsigned int> d = proper_divisors(i);
    sum_of_divisors_by_n[i] = sum_of(d);
  }

  for (unsigned int i = 1; i < 10000; ++i)
  {
    const auto& d = sum_of_divisors_by_n[i];
    if (i == d) continue;
    if (i == sum_of_divisors_by_n[d])
      amicable_numbers.push_back(i);
  }

  unsigned int sum{0};
  std::for_each(amicable_numbers.begin(),
                amicable_numbers.end(),
                [&sum](auto n)
                { sum += n; });

  std::cout << sum << "\n";
  return 0;
}

std::vector<unsigned int> proper_divisors(unsigned int n)
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

unsigned int sum_of(std::vector<unsigned int> v)
{
  unsigned int sum_of_divisors{0};
  std::for_each(v.begin(),
                v.end(),
                [&sum_of_divisors](auto f)
                { sum_of_divisors += f; });

  return sum_of_divisors;
}
