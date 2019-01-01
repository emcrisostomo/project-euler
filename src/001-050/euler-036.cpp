#include <iostream>
#include "../number.h"

// The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
//
// Find the sum of all numbers, less than one million, which are palindromic in
// base 10 and base 2.
//
// (Please note that the palindromic number, in either base, may not include
// leading zeros.)
//
int main()
{
  const unsigned int limit = 1000000;
  unsigned long sum{0};

  for (auto i = 1; i < limit; ++i)
  {
    if (number::is_palindrome(i, 2) && number::is_palindrome(i)) sum += i;
  }

  std::cout << sum << "\n";

  return 0;
}

