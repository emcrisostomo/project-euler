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
  const unsigned int limit = digit_factorial[9] * 7;

  unsigned long sum{0};
  for (auto i = 10; i < limit; ++i)
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
    vector[i] = factorial::of(i);
  }
}
