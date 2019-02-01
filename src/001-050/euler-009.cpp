#include <iostream>

const unsigned int SUM_OF_TRIPLET = 1000;

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
//   a2 + b2 = c2
//
// For example, 32 + 42 = 9 + 16 = 25 = 52.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
//
int main()
{

  for (auto a = 0; a < SUM_OF_TRIPLET / 3; ++a)
  {
    for (auto b = a + 1; b < SUM_OF_TRIPLET / 2; ++b)
    {
      auto c = SUM_OF_TRIPLET - a - b;

      if (a * a + b * b == c * c)
      {
        std::cout << a * b * c << "\n";
        return 0;
      }
    }
  }

  return 1;
}