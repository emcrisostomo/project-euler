#include <iostream>
#include "number.h"

int main(int argc, char *argv[])
{
  unsigned long max = 0;

  for (unsigned long f = 100; f <= 999; ++f)
  {
    for (unsigned long s = f; s <= 999; ++s)
    {
      unsigned long m = s * f;

      if (number::is_palindrome(m))
      {
        if (max <= m)
        {
          max = m;
        }
      }
    }
  }

  std::cout << max << "\n";
  return 0;
}