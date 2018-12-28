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
  unsigned long max{0};
  unsigned long max_p{0};

  for (unsigned int p = 1; p <= 1000; ++p)
  {
    unsigned long solutions{0};

    for (unsigned int x = 1; x < p / 3; ++x)
    {
      for (unsigned int y = x; y < p - x; ++y)
      {
        auto z = (p - x - y);

        auto z2 = (x * x) + (y * y);

        if ((z * z) == z2)
        {
          ++solutions;
        }
      }
    }

    if (solutions > max)
    {
      max = solutions;
      max_p = p;
    }
  }

  std::cout << max_p << "\n";

  return 0;
}
