#include <iostream>
#include <vector>
#include <cmath>
#include "prime.h"

bool rotations_are_prime(int prime, std::vector<bool> sieve);

// The number, 197, is called a circular prime because all rotations of the
// digits: 197, 971, and 719, are themselves prime.
//
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
// 73, 79, and 97.
//
// How many circular primes are there below one million?
//
int main()
{
  unsigned int count{0};
  unsigned int limit{1000000};
  std::vector<bool> sieve = prime::sieve_of_erathostenes(limit);

  for (auto i = 2; i < limit; ++i)
  {
    if (!sieve[i]) continue;
    if (rotations_are_prime(i, sieve)) ++count;
  }

  std::cout << count << "\n";

  return 0;
}

bool rotations_are_prime(int prime, std::vector<bool> sieve)
{
  auto digits = static_cast<unsigned int>(log10(prime)) + 1;

  for (auto i = 1; i < digits; ++i)
  {
    auto d = static_cast<unsigned int>((prime % 10) * pow(10, digits - 1));
    prime /= 10;
    prime += d;

    if (!sieve[prime]) return false;
  }

  return true;
}

