#include <iostream>
#include <cassert>
#include "number.h"

// Triangle, square, pentagonal, hexagonal, heptagonal, and octagonal numbers
// are all figurate (polygonal) numbers and are generated by the following
// formulae:
//
// Triangle    P_{3,n} = n(n+1)/2   1, 3, 6, 10, 15, ...
// Square      P_{4,n} = n^2        1, 4, 9, 16, 25, ...
// Pentagonal  P_{5,n} = n(3n−1)/2  1, 5, 12, 22, 35, ...
// Hexagonal   P_{6,n} = n(2n−1)    1, 6, 15, 28, 45, ...
// Heptagonal  P_{7,n} = n(5n−3)/2  1, 7, 18, 34, 55, ...
// Octagonal   P_{8,n} = n(3n−2)    1, 8, 21, 40, 65, ...
//
// The ordered set of three 4-digit numbers: 8128, 2882, 8281, has three
// interesting properties.
//
//   The set is cyclic, in that the last two digits of each number is the first
//   two digits of the next number (including the last number with the first).
//
//   Each polygonal type: triangle (P_{3,127} = 8128), square (P_{4,91} = 8281),
//   and pentagonal (P_{5,44} = 2882), is represented by a different number in
//   the set.
//
//   This is the only set of 4-digit numbers with this property.
//
// Find the sum of the only ordered set of six cyclic 4-digit numbers for which
// each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and
// octagonal, is represented by a different number in the set.
//
int
main(int argc, char *argv[])
{
  unsigned long sum{0};

  std::cout << sum << '\n';
  return 0;
}