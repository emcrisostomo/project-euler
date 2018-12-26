#include <iostream>
#include "prime.h"
#include "number.h"

bool are_left_truncations_prime(int n, std::vector<bool>& sieve);
bool are_right_truncations_prime(int n, std::vector<bool>& sieve);

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
  const unsigned int limit{1000000};
  unsigned long sum{0};
  std::vector<bool> sieve = prime::sieve_of_erathostenes(limit);

  for (auto i = 11; i < limit; ++i)
  {
    if (are_left_truncations_prime(i, sieve)
        && are_right_truncations_prime(i, sieve))
    {
      sum += i;
    }
  }

  std::cout << sum << "\n";

  return 0;
}

bool are_left_truncations_prime(int n, std::vector<bool>& sieve)
{
  bool ret = true;

  try
  {
    while (true)
    {
      if (!sieve[n]) return false;
      n = number::truncate_msd(n);
    }
  }
  catch (const std::runtime_error& e)
  {
    return ret;
  }
}

bool are_right_truncations_prime(int n, std::vector<bool>& sieve)
{
  bool ret = true;

  try
  {
    while (true)
    {
      if (!sieve[n]) return false;
      n = number::truncate_lsd(n);
    }
  }
  catch (const std::runtime_error& e)
  {
    return ret;
  }
}

