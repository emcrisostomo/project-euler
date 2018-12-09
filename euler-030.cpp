#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

bool is_sum_of_fifths_powers(int number, const std::vector<unsigned int>& powers);
std::vector<unsigned int> calculate_fifth_powers();

// Surprisingly there are only three numbers that can be written as the sum of
// fourth powers of their digits:
//
//   1634 = 1^4 + 6^4 + 3^4 + 4^4
//   8208 = 8^4 + 2^4 + 0^4 + 8^4
//   9474 = 9^4 + 4^4 + 7^4 + 4^4
//
// As 1 = 1^4 is not a sum it is not included.
//
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth
// powers of their digits.
//
int main()
{
  // Given the biggest number n = d * 9^5 we can produce with d digits, it
  // follows that:
  //
  //   10^{d - 1}          <= d 9^5                       < 10^d
  //   (d - 1) log(10)     <= log(d) + 5 log(9)           < d log(10)
  //   d - 1               <= log_{10}(d) + 5 log_{10}(9) < d
  //   d - 1 - log_{10}(d) <= 5 log_{10}(9)               < d - log_{10}(d)
  //   d - log_{10}(d)     <= 5 log_{10}(9) + 1           < d + 1 - log_{10}(d)
  //   d - log_{10}(d)     <= 5.7712...                   < d + 1 - log_{10}(d)
  //   d - log_{10}(5)     <= 5.7712...                   < d + 1 - log_{10}(5)
  //   d                   <= 6.47                        < d + 1
  //
  // hence d = 6.  The upper bound of the search is then:
  //
  //   6 9^5 = 354294
  const unsigned int limit = 354294;

  std::vector<unsigned int> powers = calculate_fifth_powers();
  std::vector<unsigned int> numbers;

  // Lower bound can be improved
  for (unsigned int i = 2; i < limit; ++i)
  {
    if (is_sum_of_fifths_powers(i, powers)) numbers.push_back(i);
  }

  std::cout << std::accumulate(numbers.begin(), numbers.end(), 0u) << "\n";
  return 0;
}

std::vector<unsigned int> calculate_fifth_powers()
{
  std::vector<unsigned int> powers;
  powers.reserve(10);

  for (auto i = 0; i <= 9; ++i)
  {
    powers[i] = static_cast<unsigned int>(std::pow(i, 5));
  }

  return powers;
}

bool is_sum_of_fifths_powers(int number, const std::vector<unsigned int>& powers)
{
  unsigned int sum{0};
  auto n = number;

  while (n > 0)
  {
    sum += powers[n % 10];
    n /= 10;
  }

  return (sum == number);
}
