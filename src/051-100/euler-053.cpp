#include <iostream>
#include <algorithm>
#include "combinations.h"

// There are exactly ten ways of selecting three from five, 12345:
//
//   123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
//
// In combinatorics, we use the notation, \binom{5}{3}=10.  In general,
//
//   \binom{n}{r} = \frac{n!}{r! (n−r)!},
//
// where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.  It is not until n = 23,
// that a value exceeds one-million:
//
//   \binom{23}{10} = 1144066.
//
// How many, not necessarily distinct, values of \binom{n}{r} for 1 ≤ n ≤ 100,
// are greater than one-million?
//
int main(int argc, char *argv[])
{
  size_t counter{0};

  for (auto n = 23; n <= 100; ++n)
  {
    for (auto r = 2; r <= n / 2; ++r)
    {
      if (combinations::binom<unsigned long>(n, r) > 1000000)
      {
        // When we find that \binom{n}{r} > x, we can break since
        //   \binom{n}{r + 1} > \binom{n}{r} iff (r + 1) < floor(n/r + 1)
        counter += ((((n - 1) / 2) - r + 1) * 2 + (n - 1) % 2);
        break;
      }
    }
  }

  std::cout << counter << '\n';
  return 0;
}
