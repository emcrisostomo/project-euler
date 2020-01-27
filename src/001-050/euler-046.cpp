#include <iostream>
#include <cmath>
#include "prime.h"

// It was proposed by Christian Goldbach that every odd composite number can be
// written as the sum of a prime and twice a square.
//
//   9 = 7 + 2×1^2
//   15 = 7 + 2×2^2
//   21 = 3 + 2×3^2
//   25 = 7 + 2×3^2
//   27 = 19 + 2×2^2
//   33 = 31 + 2×1^2
//
// It turns out that the conjecture was false.
//
// What is the smallest odd composite that cannot be written as the sum of a
// prime and twice a square?
//
int main(int argc, char *argv[])
{
  const auto& sieve = prime::sieve_of_erathostenes(1'000'000);

  for (unsigned int i = 35; i < sieve.size(); i += 2)
  {
    if (sieve[i]) continue;

    auto root = static_cast<unsigned long>(std::floor(std::sqrt(i / 2)));

    bool conjecture_satisfied{false};
    for (auto s = root; s >= 1; --s)
    {
      auto candidate_prime = i - (2 * s * s);

      if (sieve[candidate_prime])
      {
        conjecture_satisfied = true;
        break;
      }
    }

    if (!conjecture_satisfied)
    {
      std::cout << i << "\n";
      return 0;
    }
  }

  return 1;
}
