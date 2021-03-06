#include <iostream>
#include "number.h"

// Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2.  The first ten
// pentagonal numbers are:
//
//   1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
//
// It can be seen that P_4 + P_7 = 22 + 70 = 92 = P_8.  However, their
// difference, 70 − 22 = 48, is not pentagonal.
//
// Find the pair of pentagonal numbers, Pj and Pk, for which their sum and
// difference are pentagonal and D = |Pk − Pj| is minimised; what is the value
// of D?
//
int main(int argc, char *argv[])
{
  std::vector<unsigned long> pentagonal_numbers;
  pentagonal_numbers.push_back(1);

  unsigned int n = 1;
  unsigned long previous = 1;

  while (true)
  {
    // P_{n+1} - P_{n} = ((n+1)(3n + 3 - 1) - (n(3n-1)))/2
    //   = (6n + 2)/2
    //   = 3n + 1
    previous += (3 * n + 1);
    ++n;
    pentagonal_numbers.push_back(previous);

    for (const auto& p : pentagonal_numbers)
    {
      // For each pentagonal number p already processed, let's see whether p can
      // be considered part of a sum and a difference of pentagonal numbers
      // whose result is a pentagonal number:
      //
      //   P_j = previous - p
      //   P_k = p
      //
      // so that:
      //
      //   P_j + P_k = previous
      //   | P_j - P_k | = | previous - p - p |
      //
      // The sum is a pentagonal number because it's the latest generated
      // number, so that we have to check that both P_j itself and the
      // difference is pentagonal.
      auto p_j = previous - p;
      auto diff = (p_j > p ? p_j - p : p - p_j);

      if (number::is_pentagonal(p_j) && number::is_pentagonal(diff))
      {
        std::cout << diff << "\n";
        return 0;
      }
    }
  }
}

