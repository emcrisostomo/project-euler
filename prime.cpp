//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#include "prime.h"
#include <cmath>

unsigned long prime::upper_bound_of_nth_prime(unsigned int n)
{
  return static_cast<unsigned long>(ceil(n * (log(n) + log(log(n)))));
}

std::vector<bool> prime::sieve_of_erathostenes(size_t size)
{
  return sieve_of_erathostenes(size, nullptr, nullptr);
}


std::vector<bool> prime::sieve_of_erathostenes(size_t size,
                                               prime::prime_found_callback prime_found_callback,
                                               void *context)
{
  std::vector<bool> primes(size, true);
  primes[0] = false;
  primes[1] = false;

  for (unsigned long i = 2; i < primes.size(); ++i)
  {
    if (!primes[i])
      continue;

    if (prime_found_callback != nullptr) prime_found_callback(i, context);

    for (unsigned long j = i * i; j < primes.size(); j += i)
    {
      primes[j] = false;
    }
  }

  return primes;
}