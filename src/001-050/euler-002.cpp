#include <iostream>
#include "fibonacci.h"

int main()
{
  unsigned long long sum = 0;
  unsigned long current = 0;
  unsigned int index = 1;

  while ((current = fibonacci::n(index++)) <= 4000000)
  {
    if (current % 2 == 0) sum += current;
  }

  std::cout << sum << "\n";

  return 0;
}