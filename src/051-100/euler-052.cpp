#include <iostream>
#include <algorithm>
#include "number.h"

// It can be seen that the number, 125874, and its double, 251748, contain
// exactly the same digits, but in a different order.
//
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
// contain the same digits.
//
int main(int argc, char *argv[])
{
  size_t start = 10;

  while (true)
  {
    size_t end = (start * 10 / 6);

    for (auto i = start; i <= end; ++i)
    {
      bool found = true;
      unsigned long nx1 = i;
      std::vector<unsigned short> dx1 = number::get_digits(nx1);
      std::sort(dx1.begin(), dx1.end());

      for (auto m = 2; m <= 6; ++m)
      {
        unsigned long nxm = nx1 * m;
        std::vector<unsigned short> dxm = number::get_digits(nxm);
        std::sort(dxm.begin(), dxm.end());

        if (dx1 != dxm)
        {
          found = false;
          break;
        }
      }

      if (found)
      {
        std::cout << i << '\n';
        return 0;
      }
    }

    start *= 10;
  }
}
