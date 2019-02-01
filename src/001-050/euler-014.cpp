#include <iostream>
#include <string>

unsigned long collatz(unsigned int i);

// The following iterative sequence is defined for the set of positive integers:
//
//   n → n/2 (n is even)
//   n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following
// sequence:
//
//   13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//
// It can be seen that this sequence (starting at 13 and finishing at 1)
// contains 10 terms.  Although it has not been proved yet (Collatz Problem), it
// is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.
//
int main()
{
  unsigned long max = 1;
  unsigned int current = 0;

  for (unsigned int i = 2; i < 1000000; ++i)
  {
    auto collatz_steps = collatz(i);

    if (collatz_steps > max)
    {
      current = i;
      max = collatz_steps;
    }
  }

  std::cout << current << "\n";
  return 0;
}

unsigned long collatz(unsigned int i)
{
  unsigned long max = 1;

  while (i != 1)
  {
    ++max;
    if (i % 2 == 0) i /= 2;
    else i = 3 * i + 1;
  }

  return max;
}

