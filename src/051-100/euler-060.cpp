#include <iostream>
#include <cassert>
#include <numeric>
#include <number.h>
#include <set>
#include "prime.h"
#include "combinations.h"

static const int FAMILY_SIZE = 4;

std::vector<bool> init_primes_mask(const std::vector<unsigned long>& primes);
bool is_concatenated_family(const std::vector<unsigned long>& primes);
bool is_concatenated_pair_prime(const unsigned long& f, const unsigned long& s);

// The primes 3, 7, 109, and 673, are quite remarkable.  By taking any two
// primes and concatenating them in any order the result will always be prime.
// For example, taking 7 and 109, both 7109 and 1097 are prime.  The sum of
// these four primes, 792, represents the lowest sum for a set of four primes
// with this property.
//
// Find the lowest sum for a set of five primes for which any two primes
// concatenate to produce another prime.
//
int
main(int argc, char *argv[])
{
  // I've tried an approach where permutations where
  std::vector<unsigned long> primes = prime::get_primes_smaller_than(1000);
  // Remove 2 and 5
  primes.erase(primes.begin());
  primes.erase(primes.begin() + 1);

  unsigned long sum{0};
  std::vector<bool> primes_mask = init_primes_mask(primes);

  do
  {
    const std::vector<unsigned long>& masked_primes = combinations::with_permutation::get_masked_elements(primes,
                                                                                                          primes_mask);

    if (is_concatenated_family(masked_primes))
    {
      sum = std::accumulate(masked_primes.begin(), masked_primes.end(), sum);
      break;
    }
  } while (std::next_permutation(primes_mask.rbegin(), primes_mask.rend()));

  std::cout << sum << '\n';
  return 0;
}

bool
is_concatenated_family(const std::vector<unsigned long>& primes)
{
  static std::set<std::pair<unsigned long, unsigned long>> discarded_pairs;

  if (primes.size() < 2)
    throw std::runtime_error("Invalid size");

  std::vector<bool> mask(primes.size());
  mask[0] = true;
  mask[1] = true;

  do
  {
    const std::vector<unsigned long>& prime_pair = combinations::with_permutation::get_masked_elements(primes, mask);
    const auto& f = prime_pair[0];
    const auto& s = prime_pair[1];

    if (discarded_pairs.find(std::make_pair(f, s)) != discarded_pairs.end())
      return false;

    if (!is_concatenated_pair_prime(f, s))
    {
      discarded_pairs.insert(std::make_pair(f, s));
      return false;
    }
  } while (std::next_permutation(mask.rbegin(), mask.rend()));

  return true;
}

bool
is_concatenated_pair_prime(const unsigned long& f, const unsigned long& s)
{
  const auto& sieve = prime::sieve_of_erathostenes(10'000'000);
  unsigned long left_candidate = (f * static_cast<unsigned long>(std::pow(10, number::digits_in_number(s))) + s);
  unsigned long right_candidate = (s * static_cast<unsigned long>(std::pow(10, number::digits_in_number(f))) + f);

  return sieve[left_candidate] && sieve[right_candidate];
}

std::vector<bool>
init_primes_mask(const std::vector<unsigned long>& primes)
{
  assert(primes.size() >= FAMILY_SIZE);

  std::vector<bool> primes_mask(primes.size());
  for (int i = 0; i < FAMILY_SIZE; ++i)
    primes_mask[i] = true;

  return primes_mask;
}
