#include <iostream>
#include <vector>
#include "factorial.h"

void calculate_factorials(std::vector<unsigned int>& vector, int limit);
unsigned long sum_of_factorial_digits(unsigned int i, const std::vector<unsigned int>& factorials);

// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
//
// Find the sum of all numbers which are equal to the sum of the factorial of
// their digits.
//
// Note: as 1! = 1 and 2! = 2 are not sums they are not included.
//
int main()
{
  std::vector<unsigned int> digit_factorial(10, 0);
  calculate_factorials(digit_factorial, 9);

  // Finding a bound: given a number n with d digits, we have:
  //
  //   10^{d-1} <= n < 10^d
  //
  // The biggest n for any d is formed with all 9s:
  //
  //   10^{d-1}        <= d 9! < 10^d
  //   (d-1) log(10)   <= log(d) + log(9!)           < d log(10)
  //   (d-1)           <= log_{10}(d) + log_{10}(9!) < d
  //   (d-1)           <= log_{10}(d) + 5.56         < d
  //   d               <= log_{10}(d) + 6.56         < d + 1
  //   d - log_{10}(d) <= 6.56                       < d - log_{10}(d) + 1
  //   d = 7
  const unsigned int limit = digit_factorial[9] * 7;

  unsigned long sum{0};
  for (unsigned int i = 10; i < limit; ++i)
  {
    if (i == sum_of_factorial_digits(i, digit_factorial)) sum += i;
  }

  std::cout << sum << "\n";

  return 0;
}

unsigned long sum_of_factorial_digits(unsigned int i, const std::vector<unsigned int>& factorials)
{
  unsigned long sum{0};

  do
  {
    sum += factorials[i % 10];
  } while (i /= 10);

  return sum;
}

void calculate_factorials(std::vector<unsigned int>& vector, int limit)
{
  for (unsigned int i = 0; i <= limit; ++i)
  {
    vector[i] = emc::factorial::of(i);
  }
}
