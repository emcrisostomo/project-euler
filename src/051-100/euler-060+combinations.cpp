#include <iostream>
#include <cassert>
#include <numeric>
#include <number.h>
#include <set>
#include "prime.h"
#include "combinations.h"

static const int FAMILY_SIZE = 5;

unsigned long find_min_sum_of_family_of_size(const std::vector<unsigned long>& candidates, size_t family_size);
bool is_concatenated_pair_prime(const unsigned long& f, const unsigned long& s);
bool is_concatenated_family(const std::vector<unsigned long>& primes, size_t last_changed, size_t& last_match);
std::vector<unsigned long> find_pairs_of(const unsigned long& p, size_t index, const std::vector<unsigned long>& primes);
bool check_concatenated_family(const std::vector<unsigned long>& primes, size_t last_changed);

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
  std::vector<unsigned long> primes = prime::get_primes_smaller_than(9000);

  // Remove 2 and 5
  primes.erase(primes.begin());
  primes.erase(primes.begin() + 1);

  unsigned long sum{std::numeric_limits<unsigned long>::max()};

  for (auto i = 0; i < primes.size(); ++i)
  {
    const auto& p = primes[i];
    const auto& candidate_pairs = find_pairs_of(p, i, primes);

    auto ret = find_min_sum_of_family_of_size(candidate_pairs, FAMILY_SIZE);

    if (ret > 0)
      sum = std::min(ret, sum);
  }

  std::cout << sum << '\n';
  return 0;
}

std::vector<unsigned long>
find_pairs_of(const unsigned long& p, size_t index, const std::vector<unsigned long>& primes)
{
  std::vector<unsigned long> candidate_pairs;
  candidate_pairs.push_back(p);

  for (auto j = index + 1; j < primes.size(); ++j)
  {
    const auto& s = primes[j];
    if (is_concatenated_pair_prime(p, s))
      candidate_pairs.push_back(s);
  }

  return candidate_pairs;
}

unsigned long
find_min_sum_of_family_of_size(const std::vector<unsigned long>& candidates, size_t family_size)
{
  if (candidates.size() < family_size)
    return 0;

  unsigned long ret{std::numeric_limits<unsigned long>::max()};
  const size_t k = family_size;
  const size_t n = candidates.size();

  std::vector<size_t> comb_index = combinations::init_combination(k);
  size_t last_changed{0};

  while (combinations::hast_next(comb_index, n, k))
  {
    const auto& prime_family = combinations::get_elements_by_index(candidates, comb_index);

    size_t last_match{0};

    if (is_concatenated_family(prime_family, last_changed, last_match))
    {
      unsigned long family_sum{std::accumulate(prime_family.begin(), prime_family.end(), 0UL)};
      ret = std::min(ret, family_sum);
      last_changed = combinations::next_combination(comb_index, n, k);
    }
    else
    {
      // we have to skip all the combinations that have the first last_match
      // elements in common
      last_changed = combinations::next_combination_starting_from(comb_index, n, k, last_match);
    }
  }

  return ret;
}

bool
is_concatenated_family(const std::vector<unsigned long>& primes, size_t last_changed, size_t& last_match)
{
  if (primes.size() < 2)
    throw std::runtime_error("Invalid size");

  if (last_changed >= primes.size())
    throw std::runtime_error("last changed index not in range");

  for (auto i = last_changed; i < primes.size(); ++i)
    if (!check_concatenated_family(primes, i))
    {
      last_match = i;
      return false;
    }

  return true;
}

bool check_concatenated_family(const std::vector<unsigned long>& primes, size_t last_changed)
{
  static std::set<std::pair<unsigned long, unsigned long>> discarded_pairs;
  static std::set<std::pair<unsigned long, unsigned long>> concatenated_pairs;

  // This function assumes that the family in the range f = [0, last_changed[ is
  // a concatenated family.  Elements in the [last_changed, primes.size()[
  // range will be checked against the f family one by one.
  std::vector<unsigned long> verified_family;
  verified_family.reserve(last_changed);

  for (auto i = 0; i < last_changed; ++i)
    verified_family.push_back(primes[i]);

  const auto& not_verified = primes[last_changed];

  for (const auto& verified : verified_family)
  {
    const auto pair = std::make_pair(verified, not_verified);

    if (discarded_pairs.find(pair) != discarded_pairs.end())
      return false;

    if (concatenated_pairs.find(pair) != concatenated_pairs.end())
      continue;

    if (!is_concatenated_pair_prime(pair.first, pair.second))
    {
      discarded_pairs.insert(pair);
      return false;
    }

    concatenated_pairs.insert(pair);
  }

  return true;
}

bool
is_concatenated_pair_prime(const unsigned long& f, const unsigned long& s)
{
  // TODO: profile usage of a sieve vs.
//  static const std::vector<bool>& sieve =
//    prime::sieve_of_erathostenes(100000000);

  unsigned long left_candidate = (f * static_cast<unsigned long>(std::pow(10, number::digits_in_number(s))) + s);
  unsigned long right_candidate = (s * static_cast<unsigned long>(std::pow(10, number::digits_in_number(f))) + f);

  return prime::is_prime(left_candidate) && prime::is_prime(right_candidate);
//  return sieve[left_candidate] && sieve[right_candidate];
}