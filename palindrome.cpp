//
// Created by Enrico M. Crisostomo on 03/09/2018.
//

#include <string>
#include "palindrome.h"

bool palindrome::is(unsigned long n)
{
  const std::string& s = std::to_string(n);
  unsigned long length = s.length();

  for (auto i = 0; i < length / 2; ++i)
  {
    if (s[i] != s[length - 1 - i]) return false;
  }
  
  return true;
}
