#include <iostream>
#include "number.h"

unsigned long get_next_number();

// Triangle, pentagonal, and hexagonal numbers are generated by the following
// formulae:
//
//   Triangle    Tn=n(n+1)/2   1, 3, 6, 10, 15, ...
//   Pentagonal  Pn=n(3n−1)/2  1, 5, 12, 22, 35, ...
//   Hexagonal 	 Hn=n(2n−1)    1, 6, 15, 28, 45, ...
//
// It can be verified that T_285 = P_165 = H_143 = 40755.
//
// Find the next triangle number that is also pentagonal and hexagonal.
//
int main(int argc, char *argv[])
{
  // From the problem statement it seems that Tn generates Hn when n is odd.
  // To prove it:
  //
  //   Tn = (2x - 1)(2x - 1 + 1)/2
  //      = (2x - 1)2x/2
  //      = (2x - 1)x
  //      = Hx
  //
  // Hence, we can generated Tn when n is odd and check if it's pentagonal.
  std::cout << get_next_number() << "\n";

  return 0;
}

unsigned long get_next_number()
{
  // Starting from H_143
  for (unsigned long i = 144;; ++i)
  {
    auto h = (2 * i * i) - i;
    if (number::is_pentagonal(h)) return h;
  }
}
