//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#include "sum.h"
#include <stdexcept>

unsigned long long sum::range(unsigned int start, unsigned int end)
{
  if (end < start) throw std::invalid_argument("end must be equal to or greater than start");

  return (start + end) * ((end - start + 1)/2);
}