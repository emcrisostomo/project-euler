#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "../number.h"

unsigned short digit_at(unsigned int digit);

// An irrational decimal fraction is created by concatenating the positive
// integers:
//
//   0.123456789101112131415161718192021...
//
// It can be seen that the 12th digit of the fractional part is 1.
//
// If dn represents the nth digit of the fractional part, find the value of the
// following expression.
//
// d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000
//
int main()
{
  // The number generated this way can be segmented in groups numbers with i
  // digits:
  //
  //   0. 123456789 101112131415161718192021...979899 100101...
  //     |---------|---------------------------------|---------
  //         i=i                 i=2                    i=3
  //
  // Each group contains numbers x with i digits:
  //
  //   10^(i-1) <= x < 10^i
  //
  // thus, each group contains (10^i - 10^(i-1)) numbers with i digits, for a
  // total of i (10^i - 10^(i-1)) digits.
  //
  // To solve the problem more efficiently, we can use this observation to find
  // more quickly where the k-th digit lies:
  //
  //   - We find the group it belongs to.
  //   - We then find the number it belongs to.
  //   - We then the digit of that number it corresponds to.
  //
  // The algorithm is implemented in digit_at.

  const short max_power{6};
  unsigned int product{1};

  for (auto i = 0; i <= max_power; ++i)
    product *= digit_at(static_cast<unsigned int>(pow(10, i)));

  std::cout << product << "\n";

  return 0;
}

unsigned short digit_at(unsigned int digit)
{
  if (digit == 0) throw std::invalid_argument("Digit must be greater than 0");

  unsigned int i{0};
  unsigned int previous_block{0};
  unsigned int current_block{0};

  // Finding the group it belongs to, by iteratively shifting the boundary of
  // the previous_block forward by the size of the i-th block.  At the end of
  // the loop, previous_block will contain the number of digits that come before
  // the start of the block where the digit belongs to.
  while (current_block < digit)
  {
    ++i;
    previous_block = current_block;
    current_block += (i * static_cast<unsigned int>(pow(10, i) - pow(10, i - 1)));
  }

  // Finding the digit coordinate in the block, by shifting back digit by the
  // number of digits in all the blocks that come before it.  We also subtract 1
  // to make the coordinate inside a block 0-based (the problem statement is
  // 1-based).
  unsigned int position_in_block = digit - previous_block - 1;

  // Finding the index of the number in the group the digit belongs to.  Since
  // each number in the group has i digits, we can divide the coordinate by i:
  unsigned int digit_idx_in_group = position_in_block / i;

  // Finding the number in the group the digit belongs to, by adding the index
  // number to the digit that starts the index.
  unsigned int number_in_group = static_cast<unsigned int>(pow(10, i - 1)) + digit_idx_in_group;

  // Finding the digit in the number.
  std::vector<unsigned short> number_digits = number::get_digits(number_in_group);
  std::reverse(number_digits.begin(), number_digits.end());

  return number_digits[digit_idx_in_group % i];
}


