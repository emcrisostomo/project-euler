#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../number.h"

// Take the number 192 and multiply it by each of 1, 2, and 3:
//
//   192 × 1 = 192
//   192 × 2 = 384
//   192 × 3 = 576
//
// By concatenating each product we get the 1 to 9 pandigital, 192384576.  We
// will call 192384576 the concatenated product of 192 and (1,2,3)
//
// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
// and 5, giving the pandigital, 918273645, which is the concatenated product of
// 9 and (1,2,3,4,5).
//
// What is the largest 1 to 9 pandigital 9-digit number that can be formed as
// the concatenated product of an integer with (1,2, ... , n) where n > 1?
//
int main()
{
  unsigned long max{0};

  for (auto i = 9999; i >= 1; --i)
  {
    unsigned long number{0};
    unsigned int digits{0};

    for (auto j = 1; digits < 9; ++j)
    {
      auto product = i * j;
      auto d = number::digits_in_number(product);
      digits += d;
      number *= static_cast<unsigned long>(pow(10, d));
      number += product;
    }

    if (digits != 9) continue;
    if (!number::is_pandigital(number)) continue;

    max = number;
    break;
  }

  std::cout << max << "\n";

  return 0;
}
