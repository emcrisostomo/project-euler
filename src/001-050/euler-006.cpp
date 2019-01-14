#include <iostream>
#include "squares.h"
#include "sum.h"

int main()
{
  unsigned long long sum_of_squares = squares::sum_range(1, 100);
  unsigned long long sum = sum::range(1, 100);
  unsigned long long square_of_sums = sum * sum;

  std::cout << square_of_sums - sum_of_squares << "\n";

  return 0;
}