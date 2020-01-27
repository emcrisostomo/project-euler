#include <iostream>
#include "prime.h"
#include "number.h"

// We shall say that an n-digit number is pandigital if it makes use of all the
// digits 1 to n exactly once.  For example, 2143 is a 4-digit pandigital and is
// also prime.
//
// What is the largest n-digit pandigital prime that exists?
//
int main()
{
  const auto& sieve = prime::sieve_of_erathostenes(7'654'321);

  for (long i = sieve.size() - 1; i >= 0; --i)
  {
    if (!sieve[i]) continue;
    if (!number::is_pandigital(i)) continue;

    std::cout << i << "\n";
    return 0;
  }

  return 1;
}
