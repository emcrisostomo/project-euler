#include <iostream>
#include <vector>
#include "../number.h"

void add_digits(unsigned int n, std::vector<unsigned short>& vector);

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
  const unsigned int limit{1000000};
  std::vector<unsigned short> digits;
  digits.reserve(limit + 1);
  digits.push_back(0);

  for (unsigned int i = 1; digits.size() <= limit; ++i)
  {
    add_digits(i, digits);
  }

  std::cout << (digits[1]
                * digits[10]
                * digits[100]
                * digits[1000]
                * digits[10000]
                * digits[100000]
                * digits[1000000])
            << "\n";

  return 0;
}

void add_digits(unsigned int n, std::vector<unsigned short>& vector)
{
  std::vector<unsigned short> digits = number::get_digits(n);
  vector.insert(vector.end(), digits.rbegin(), digits.rend());
}
