#include <iostream>
#include <vector>

const unsigned int upper_limit = 2'000'000;

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.
//
int main()
{
  std::vector<bool> primes(upper_limit, true);
  primes[0] = false;
  primes[1] = false;

  unsigned long sum_of_primes = 0;

  for (auto i = 2; i < primes.size(); ++i)
  {
    if (!primes[i])
      continue;

    sum_of_primes += i;
    for (auto j = i + i; j < primes.size(); j += i)
    {
      primes[j] = false;
    }
  }

  std::cout << sum_of_primes << "\n";
  return 0;
}