#include <iostream>
#include <algorithm>
#include <vector>
#include "number.h"
#include "prime.h"

// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
// increases by 3330, is unusual in two ways:
//
//   (i) each of the three terms are prime, and,
//   (ii) each of the 4-digit numbers are permutations of one another.
//
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
// exhibiting this property, but there is one other 4-digit increasing sequence.
//
// What 12-digit number do you form by concatenating the three terms in this
// sequence?
//
int main(int argc, char *argv[])
{
  const unsigned int limit = 9999;
  const auto sieve = prime::sieve_of_erathostenes(limit);
  unsigned long sequence{0};

  for (unsigned short f = 0; f <= 9; ++f)
  {
    for (unsigned short s = f; s <= 9; ++s)
    {
      for (unsigned short t = s; t <= 9; ++t)
      {
        for (unsigned short fo = t; fo <= 9; ++fo)
        {
          std::vector<unsigned short> digits{f, s, t, fo};
          std::vector<unsigned int> primes;
          primes.reserve(24);

          do
          {
            unsigned int n = number::number_from_digits<unsigned short, unsigned int>(digits);
            if (sieve[n])
              primes.push_back(n);
          } while (std::next_permutation(digits.begin(), digits.end()));

          if (primes.size() < 3)
            continue;
        }
      }
    }
  }

  std::cout << sequence << "\n";
  return 0;
}
