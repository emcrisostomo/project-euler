#include <iostream>
#include "prime.h"
#include "number.h"

bool is_truncatable(int n, std::vector<bool>& sieve);

// The number 3797 has an interesting property. Being prime itself, it is
// possible to continuously remove digits from left to right, and remain prime
// at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
// left: 3797, 379, 37, and 3.
//
// Find the sum of the only eleven primes that are both truncatable from left to
// right and right to left.
//
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
//
int main()
{
  // The limit is arbitrary
  const unsigned int limit{1000000};
  const unsigned int to_find{11};
  unsigned long sum{0};
  unsigned int count{0};
  std::vector<bool> sieve = prime::sieve_of_erathostenes(limit);

  for (auto i = 23; i < limit && count < to_find; i += 2)
  {
    if (!sieve[i]) continue;
    if (!is_truncatable(i, sieve)) continue;

    sum += i;
    ++count;
  }

  if (count != to_find)
    return 1;

  std::cout << sum << "\n";

  return 0;
}

bool is_truncatable(int n, std::vector<bool>& sieve)
{
  for (auto i = 10; i <= n; i *= 10)
  {
    if (!sieve[n % i]) return false;
    if (!sieve[n / i]) return false;
  }

  return true;
}