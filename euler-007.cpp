#include <iostream>
#include <vector>
#include "prime.h"

int main()
{
  const unsigned int nth = 10001;
  auto upper_bound = prime::upper_bound_of_nth_prime(nth);

  // Let's create one element more to address the nth prime without shifting by one
  std::vector<bool> primes(upper_bound + 1, true);
  primes[0] = false;
  primes[1] = false;

  for (auto i = 2; i < primes.size(); ++i)
  {
    if (!primes[i])
      continue;

    for (auto j = i + i; j < primes.size(); j += i)
    {
      primes[j] = false;
    }
  }

  unsigned int counter = 0;
  unsigned int nth_prime = 0;

  for (unsigned int i = 2; i < primes.size(); ++i)
  {
    if (!primes[i]) continue;
    ++counter;

    if (counter == nth)
    {
      nth_prime = i;
      break;
    }
  }

  std::cout << nth_prime << "\n";

  return 0;
}