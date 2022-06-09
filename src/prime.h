//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#ifndef PROJECT_EULER_PRIME_H
#define PROJECT_EULER_PRIME_H

#include <vector>
#include <map>
#include <cstddef>

namespace prime
{
typedef void (*prime_found_callback)(unsigned long i, void *context);

class sieve_of_erathostenes
{
public:
  explicit sieve_of_erathostenes(size_t size);
  sieve_of_erathostenes(size_t size, prime_found_callback prime_found_callback, void *context);
  size_t size() const;
  const bool operator[](std::size_t idx) const;
private:
  std::vector<bool> sieve;
  std::size_t sieve_size;
  void build_sieve(size_t size, prime_found_callback callback, void *context);
};

unsigned long upper_bound_of_nth_prime(unsigned int nth_prime);
std::map<unsigned long, unsigned int> factorize(unsigned long number);
unsigned long long largest_prime_factor_of(unsigned long long number);
std::vector<unsigned long> get_primes_smaller_than(size_t limit);
bool is_prime(unsigned long p);
};


#endif //PROJECT_EULER_PRIME_H
