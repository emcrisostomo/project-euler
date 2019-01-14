//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#include "prime.h"
#include <cmath>

unsigned long prime::upper_bound_of_nth_prime(unsigned int n)
{
  return static_cast<unsigned long>(ceil(n * (log(n) + log(log(n)))));
}

std::vector<unsigned long> prime::get_primes_smaller_than(size_t limit)
{
  std::vector<unsigned long> primes;
  auto sieve = prime::sieve_of_erathostenes(limit);

  for (unsigned long i = 0; i < sieve.size(); ++i)
  {
    if (sieve[i]) primes.push_back(i);
  }

  return primes;
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

  // Since even numbers account for half of the sieve size, we treat them as a
  // special case
  primes[2] = true;

  if (prime_found_callback != nullptr) prime_found_callback(2, context);

  for (auto i = 4; i < primes.size(); i += 2)
    primes[i] = false;

  // Process the sieve
  for (unsigned long i = 3; i < primes.size(); i += 2)
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
  if (number == 2) return {{2, 1}};

  auto n = number;

  for (auto i = 2; i <= std::sqrt(n); ++i)
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

unsigned long long prime::largest_prime_factor_of(unsigned long long number)
{
  const auto& factorization = prime::factorize(number);

  return factorization.empty() ? 0 : factorization.rbegin()->first;
}

bool prime::is_prime(unsigned long number)
{
  // Return empty factorizations for non-composite numbers.
  if (number == 0) return false;
  if (number == 1) return false;
  if (number == 2) return true;

  auto n = number;

  for (auto i = 2; i <= std::sqrt(n); ++i)
  {
    if (n % i == 0)
    {
      return false;
    }
  }

  return true;
}