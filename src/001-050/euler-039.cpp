#include <iostream>
#include <algorithm>
#include <cmath>

// If p is the perimeter of a right angle triangle with integral length sides,
// {a,b,c}, there are exactly three solutions for p = 120.
//
//   {20,48,52}, {24,45,51}, {30,40,50}
//
// For which value of p ≤ 1000, is the number of solutions maximised?
//
int main()
{
  // We're looking for the integral solutions of:
  //
  //   x^2 + y^2 = z^2
  //   x + y + z = p
  //
  // If we substitute z into the first equation, we get:
  //
  //   z = p - x - y                                 =>
  //   x^2 + y^2 = (p - x - y)^2                     =>
  //   x^2 + y^2 = p^2 + x^2 + y^2 - 2px - 2py + 2xy =>
  //   0 = p^2 - 2px - 2py + 2xy                     =>
  //   0 = p^2 - 2px +y(2x - 2p)                     =>
  //   y = p^2 - 2px / 2(p - x)
  //
  // Hence, finding integral solutions y to the previous equation yields a
  // solution to the problem.  Integral solutions can be checked with:
  //
  //   (p^2 - 2px) % (2(p - x)) == 0
  //
  // As in the brute force case, we can make the following assumptions:
  //
  //   - x <= y < z
  //   - x < p/3
  unsigned long max{0};
  unsigned long max_p{0};

  for (unsigned int p = 1; p <= 1000; ++p)
  {
    unsigned long solutions{0};

    for (unsigned int x = 1; x < p / 3; ++x)
    {
      if (((p * p - 2 * p * x) % (2 * (p - x))) == 0) ++solutions;
      if (solutions > max)
      {
        max = solutions;
        max_p = p;
      }
    }
  }

  std::cout << max_p << "\n";

  return 0;
}
