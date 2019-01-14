#include <iostream>
#include <vector>

const unsigned int SUM_OF_TRIPLET_LIMIT = 1000;

// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9.  The sum of these multiples is 23.
//
//  Find the sum of all the multiples of 3 or 5 below 1000.
//
int main()
{
  unsigned int sum_of_multiples = 0;

  for (auto i = 0; i < SUM_OF_TRIPLET_LIMIT; ++i)
  {
    if (i % 3 == 0 || i % 5 == 0) sum_of_multiples += i;
  }

  std::cout << sum_of_multiples << "\n";

  return 0;
}