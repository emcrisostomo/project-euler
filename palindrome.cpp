//
// Created by Enrico M. Crisostomo on 03/09/2018.
//

#include <string>
#include "palindrome.h"

bool palindrome::is(unsigned long n)
{
 return palindrome::is(n, 10);
}

bool palindrome::is(unsigned long n, unsigned int base)
{
  unsigned long reversed{0};
  auto num = n;

  while (num != 0)
  {
    auto u = num % base;
    reversed *= base;
    reversed += u;
    num /= base;
  }

  return (n == reversed);
}