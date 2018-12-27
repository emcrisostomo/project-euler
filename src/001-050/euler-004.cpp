
#include <iostream>
#include "../palindrome.h"

int main(int argc, char *argv[])
{
  auto max = 0;
  auto a = 0;
  auto b = 0;

  for (auto f = 100; f <= 999; ++f)
  {
    for (auto s = f; s <= 999; ++s)
    {
      auto m = s * f;

      if (palindrome::is(m))
      {
        if (max <= m)
        {
          max = m;
          a = f;
          b = s;
        }
      }
    }
  }

  std::cout << max << "\n";
  return 0;
}