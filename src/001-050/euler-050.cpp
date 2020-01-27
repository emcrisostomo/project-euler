#include <iostream>
#include "prime.h"

// The prime 41, can be written as the sum of six consecutive primes:
//
//   41 = 2 + 3 + 5 + 7 + 11 + 13
//
// This is the longest sum of consecutive primes that adds to a prime below
// one-hundred.
//
// The longest sum of consecutive primes below one-thousand that adds to a
// prime, contains 21 terms, and is equal to 953.
//
// Which prime, below one-million, can be written as the sum of the most
// consecutive primes?
//
int main(int argc, char *argv[])
{
  const unsigned int limit = 999999;
  const auto& sieve = prime::sieve_of_erathostenes(limit);
  const std::vector<unsigned long> primes = prime::get_primes_smaller_than(limit);

  std::vector<unsigned long> sum_of_primes(primes.size() + 1);
  sum_of_primes[0];

  for (auto i = 0; i < primes.size(); ++i)
  {
    sum_of_primes[i + 1] = sum_of_primes[i] + primes[i];
  }

  // Iterate on all the possible sequences of consecutive prime numbers of
  // length i, from longest to shortest.
  for (auto i = primes.size(); i >= 1; --i)
  {
    // Calculate the sum of all the possible sequences of length i, from the
    // lowest to the highest.
    for (auto begin = 0; begin < sum_of_primes.size() - i; ++begin)
    {
      auto end{begin + i};
      auto sum{sum_of_primes[end] - sum_of_primes[begin]};

      if (sum > limit) break;
      if (sieve[sum])
      {
        std::cout << sum << "\n";
        return 0;
      }
    }
  }

  return 0;
}
