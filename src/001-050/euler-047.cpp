#include <iostream>
#include <cmath>
#include "prime.h"

// The first two consecutive numbers to have two distinct prime factors are:
//
//   14 = 2 × 7
//   15 = 3 × 5
//
// The first three consecutive numbers to have three distinct prime factors are:
//
//   644 = 2^2 × 7 × 23
//   645 = 3 × 5 × 43
//   646 = 2 × 17 × 19.
//
// Find the first four consecutive integers to have four distinct prime factors
// each.  What is the first of these numbers?
//
int main(int argc, char *argv[])
{
  unsigned short counter{0};

  for (unsigned int p = 2000;; ++p)
  {
    auto factorization = prime::factorize(p);
    if (factorization.size() != 4)
    {
      counter = 0;
      continue;
    }

    ++counter;

    if (counter == 4)
    {
      std::cout << p - 3 << "\n";
      return 0;
    };
  }
}
