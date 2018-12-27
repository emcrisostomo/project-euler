//
// Created by Enrico M. Crisostomo on 03/09/2018.
//

#include "fibonacci.h"
#include <cmath>

double SQRT_5;
double PHI;

void init_constants();

void init_constants()
{
  SQRT_5 = sqrt(5);
  PHI = (1 + SQRT_5) / 2;
}

// F_n = floor(phi^n / sqrt(5) + 1/2)
unsigned long fibonacci::n(unsigned int index)
{
  // No overflows checks
  init_constants();

  if (index == 0) return 0;
  if (index == 1) return 1;

  double fibonacci_n = pow(PHI, index);
  fibonacci_n /= SQRT_5;
  fibonacci_n += 0.5;

  return static_cast<unsigned long>(floor(fibonacci_n));
}
