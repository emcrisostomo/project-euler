#include <iostream>
#include <vector>
#include "prime.h"

const unsigned int upper_limit = 2'000'000;

void prime_sum(unsigned long i, void *context)
{
  auto *sum_of_primes = static_cast<unsigned long *>(context);

  *sum_of_primes += i;
}

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.
//
int main()
{
  unsigned long sum_of_primes = 0;

  prime::sieve_of_erathostenes(upper_limit, &prime_sum, &sum_of_primes);

  std::cout << sum_of_primes << "\n";
  return 0;
}