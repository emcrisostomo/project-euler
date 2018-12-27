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

  // Numbers are concatenated from left to right, so the first product will
  // provide the most significant digits of the resulting pandigital number.
  // Since we're given a number starting with 9 in the problem statement, and
  // since the first product i * n is given by n = 1, the search space can be
  // reduced to the following sets:
  //
  //   [90,99]
  //   [900,999]
  //   [9000,9999]
  //
  // If i \in [90,99], then the first products will be in the ranges:
  //
  //   [90,99], [180,198], [270,297], [360,396],
  //
  // hence 9 digits concatenations are not possible.
  //
  // If i \in [900,999], then the first products will be in the ranges:
  //
  //   [900,999], [1800,1998], [2700,2997]
  //
  // hence 9 digits concatenations are not possible.
  //
  // If i \in [9000,9999], the the first products will be in the ranges:
  //
  //   [9000,9999], [18000,19998]
  //
  // and 9 digits concatenations will be possible when n <= 2.
  //
  // Since we know that the second product will have a 1 in it, we reduce the
  // search space by stopping at 9234 instead of 9123.
  for (unsigned long i = 9876; i >= 9234; --i)
  {
    // Since we now i * 2 will have 5 digits, we're shifting i * 1 to make room
    unsigned long number = 100000 * i;
    number += (i * 2);

    if (!number::is_pandigital(number)) continue;

    max = number;
    break;
  }

  std::cout << max << "\n";

  return 0;
}
