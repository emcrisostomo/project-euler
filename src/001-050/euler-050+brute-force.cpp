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
  unsigned long longest_prime{0};
  unsigned long max_consecutive_primes{0};

  for (auto k = 1; k < sieve.size(); ++k)
  {
    unsigned long prime{0};
    unsigned long consecutive_primes{0};

    for (auto i = k; i < sieve.size(); ++i)
    {
      if (!sieve[i]) continue;
      prime += i;
      consecutive_primes++;

      if (prime > limit) break;

      if (sieve[prime] && consecutive_primes > max_consecutive_primes)
      {
        longest_prime = prime;
        max_consecutive_primes = consecutive_primes;
      }
    }
  }

  std::cout << longest_prime << "\n";
  return 0;
}
