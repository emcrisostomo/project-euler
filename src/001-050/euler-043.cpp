#include <iostream>
#include <algorithm>
#include "number.h"

bool
satisfy_divisibility(unsigned long d_2,
                     unsigned long d_3,
                     unsigned long d_5,
                     unsigned long d_7,
                     unsigned long d_11,
                     unsigned long d_13,
                     unsigned long d_17);

// The number, 1406357289, is a 0 to 9 pandigital number because it is made up
// of each of the digits 0 to 9 in some order, but it also has a rather
// interesting sub-string divisibility property.
//
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on.  In this way, we
// note the following:
//
//   d2d3d4=406 is divisible by 2
//   d3d4d5=063 is divisible by 3
//   d4d5d6=635 is divisible by 5
//   d5d6d7=357 is divisible by 7
//   d6d7d8=572 is divisible by 11
//   d7d8d9=728 is divisible by 13
//   d8d9d10=289 is divisible by 17
//
// Find the sum of all 0 to 9 pandigital numbers with this property.
//
int main(int argc, char *argv[])
{
  unsigned long sum{0};

  std::vector<unsigned int> permutation = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  do
  {
    unsigned long number{0};

    for (const auto& d : permutation)
    {
      number *= 10;
      number += d;
    }

    auto d_2 = (number / 1000000) % 1000;
    auto d_3 = (number / 100000) % 1000;
    auto d_5 = (number / 10000) % 1000;
    auto d_7 = (number / 1000) % 1000;
    auto d_11 = (number / 100) % 1000;
    auto d_13 = (number / 10) % 1000;
    auto d_17 = (number / 1) % 1000;

    if (satisfy_divisibility(d_2, d_3, d_5, d_7, d_11, d_13, d_17)) sum += number;

  } while (std::next_permutation(permutation.begin(), permutation.end()));

  std::cout << sum << "\n";

  return 0;
}

bool satisfy_divisibility(unsigned long d_2,
                          unsigned long d_3,
                          unsigned long d_5,
                          unsigned long d_7,
                          unsigned long d_11,
                          unsigned long d_13,
                          unsigned long d_17)
{
  return (d_2 % 2 == 0)
         && (d_3 % 3 == 0)
         && (d_5 % 5 == 0)
         && (d_7 % 7 == 0)
         && (d_11 % 11 == 0)
         && (d_13 % 13 == 0)
         && (d_17 % 17 == 0);
}
