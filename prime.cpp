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
  std::vector<bool> primes(size, true);
  primes[0] = false;
  primes[1] = false;

  for (unsigned long i = 2; i < primes.size(); ++i)
  {
    if (!primes[i])
      continue;

    for (unsigned long j = i * i; j < primes.size(); j += i)
    {
      primes[j] = false;
    }
  }

  return primes;
}


std::vector<bool> prime::sieve_of_erathostenes(size_t size,
                                               prime::A prime_found_callback,
                                               void *context)
{
  std::vector<bool> primes(size, true);
  primes[0] = false;
  primes[1] = false;

  for (unsigned long i = 2; i < primes.size(); ++i)
  {
    if (!primes[i])
      continue;

    prime_found_callback(i, context);

    for (unsigned long j = i * i; j < primes.size(); j += i)
    {
      primes[j] = false;
    }
  }

  return primes;
}