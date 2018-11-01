//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#include "squares.h"
#include <stdexcept>

unsigned long long squares::sum_range(unsigned int start, unsigned int end)
{
  if (end < start) throw std::invalid_argument("end must be equal to or greater than start");

  unsigned long long sum = 0;

  for (auto i = start; i <= end; ++i)
    sum += (i * i);

  return sum;
}