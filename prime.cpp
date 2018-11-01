//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#include "prime.h"
#include <cmath>

unsigned long prime::upper_bound_of_nth_prime(unsigned int n)
{
  return static_cast<unsigned long>(ceil(n * (log(n) + log(log(n)))));
}