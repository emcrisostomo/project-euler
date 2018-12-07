#include <iostream>

// Starting with the number 1 and moving to the right in a clockwise direction a
// 5 by 5 spiral is formed as follows:
//
//   21 22 23 24 25
//   20  7  8  9 10
//   19  6  1  2 11
//   18  5  4  3 12
//   17 16 15 14 13
//
// It can be verified that the sum of the numbers on the diagonals is 101.
//
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
// formed in the same way?
//
int main()
{
  // The numbers in the diagonals are the corners of 500 concentric squares,
  // centered on 1.  The length of the side of the n-th square is (1 + 2n), and
  // the distance between the corners is 2n.  Starting from 1, we can iterate
  // n in the range 0 <= n < 500 and add the last number plus the current
  // increment.
  unsigned long sum{1};
  unsigned long current{1};
  unsigned long increment{0};

  for (auto n = 0; n < 500; ++n)
  {
    increment += 2;

    for (auto r = 0; r < 4; ++r)
    {
      current += increment;
      sum += current;
    }
  }

  std::cout << sum << "\n";
  return 0;
}
