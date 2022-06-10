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

size_t ceil_odd(size_t num)
{
  if (num % 2 == 0)
    return num + 1;

  return num;
}

size_t to_odd_coord(size_t num)
{
  return ((num - 1) / 2);
}
//
//std::vector<bool> prime::sieve_of_erathostenes(size_t size,
//                                               prime::prime_found_callback prime_found_callback,
//                                               void *context)
//{
//  std::vector<bool> primes(size / 2, true);
//  primes[0] = false;
//
//  if (prime_found_callback != nullptr)
//    prime_found_callback(2, context);
//
//  const size_t sqrt_n = ceil_odd(std::sqrtl(static_cast<long double>(size)));
//
//  // Process the sieve
//  for (auto i = 3; i < sqrt_n; i += 2)
//  {
//    if (!primes[to_odd_coord(i)])
//      continue;
//
//    if (prime_found_callback != nullptr)
//      prime_found_callback(i, context);
//
//    for (auto j = i * i; j < size; j += 2 * i)
//      primes[to_odd_coord(j)] = false;
//  }
//
//  if (prime_found_callback != nullptr)
//    for (auto i = sqrt_n; i < size; i += 2)
//      if (primes[to_odd_coord(i)])
//        prime_found_callback(i, context);
//
//  return primes;
//}

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

bool prime::is_prime(const unsigned long number)
{
  // Return empty factorizations for non-composite numbers.
  if (number == 0) return false;
  if (number == 1) return false;
  if (number == 2) return true;
  if (number % 2 == 0) return false;

  auto end = std::sqrt(number);

  for (auto i = 3; i <= end; i += 2)
  {
    if (number % i == 0)
    {
      return false;
    }
  }

  return true;
}

prime::sieve_of_erathostenes::sieve_of_erathostenes(size_t size) : sieve_size{size}
{
  build_sieve(size, nullptr, nullptr);
}

prime::sieve_of_erathostenes::sieve_of_erathostenes(size_t size,
                                                    prime::prime_found_callback prime_found_callback,
                                                    void *context) : sieve_size{size}
{
  build_sieve(size, prime_found_callback, context);
}

void prime::sieve_of_erathostenes::build_sieve(
  size_t size,
  prime::prime_found_callback callback,
  void *context)
{
  std::vector<bool> primes(size / 2, true);
  primes[0] = false;

  if (callback != nullptr)
    callback(2, context);

  const size_t sqrt_n = ceil_odd(sqrtl(static_cast<long double>(size)));

  // Process the sieve
  for (auto i = 3; i < sqrt_n; i += 2)
  {
    if (!primes[to_odd_coord(i)])
      continue;

    if (callback != nullptr)
      callback(i, context);

    for (auto j = i * i; j < size; j += 2 * i)
      primes[to_odd_coord(j)] = false;
  }

  if (callback != nullptr)
    for (auto i = sqrt_n; i < size; i += 2)
      if (primes[to_odd_coord(i)])
        callback(i, context);

  this->sieve = std::move(primes);
}

size_t prime::sieve_of_erathostenes::size() const
{
  return this->sieve_size;
}

const bool prime::sieve_of_erathostenes::operator[](std::size_t idx) const
{
  if (idx == 0 || idx == 1)
    return false;

  if (idx % 2 == 0)
    return (idx == 2);

  return this->sieve[to_odd_coord(idx)];
}
