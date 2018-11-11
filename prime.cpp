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

std::map<unsigned long, unsigned int> prime::factorize(unsigned long number)
{
  auto v = std::map<unsigned long, unsigned int>();

  // Return empty factorizations for non-composite numbers.
  if (number == 0) return v;
  if (number == 1) return v;

  auto n = number;

  for (auto i = 2; i <= n / 2; ++i)
  {
    if (n % i == 0)
    {
      v[i] += 1;

      n /= i;
      i = 1;
    }
  }

  if (n != 1) v[n] += 1;

  return v;
}
