#include <iostream>
#include <utility>
#include "multiple.h"

// The fraction 49/98 is a curious fraction, as an inexperienced mathematician
// in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
// is correct, is obtained by cancelling the 9s.
//
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
//
// There are exactly four non-trivial examples of this type of fraction, less
// than one in value, and containing two digits in the numerator and
// denominator.
//
// If the product of these four fractions is given in its lowest common terms,
// find the value of the denominator.
//
int main()
{
  unsigned int numerator{1};
  unsigned int denominator{1};

  for (int i = 10; i <= 99; ++i)
  {
    auto u = (i % 10);
    if (u == 0) continue;

    auto d = u * 10;
    for (int j = d + 1; j <= d + 9; ++j)
    {
      if (i >= j) continue;

      if ((i * (j % 10)) == (j * (i / 10)))
      {
        numerator *= i;
        denominator *= j;
      }
    }
  }

  std::cout << denominator / multiple::gcd(numerator, denominator) << "\n";

  return 0;
}
