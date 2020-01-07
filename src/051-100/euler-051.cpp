#include <iostream>
#include <algorithm>
#include <cassert>
#include "number.h"
#include "prime.h"

std::vector<std::vector<bool>> permute(std::vector<bool>& pattern);

std::vector<unsigned short>
fill_pattern_with_number(const std::vector<bool>& pattern, unsigned long number);

void
fill_repeating_digits(const std::vector<bool>& pattern,
                      unsigned short repeating_digit,
                      std::vector<unsigned short>& candidate);

size_t
get_prime_family_size(const std::vector<bool>& pattern,
                      std::vector<unsigned short>& candidate,
                      unsigned short repeating_digit);

// By replacing the 1st digit of the 2-digit number *3, it turns out that six
// of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
//
// By replacing the 3rd and 4th digits of 56**3 with the same digit, this
// 5-digit number is the first example having seven primes among the ten
// generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663,
// 56773, and 56993.  Consequently 56003, being the first member of this family,
// is the smallest prime with this property.
//
// Find the smallest prime which, by replacing part of the number (not
// necessarily adjacent digits) with the same digit, is part of an eight prime
// value family.
//
int main(int argc, char *argv[])
{
  // Improve logic to detect that a candidate result has been found
  unsigned long result = 1000000;
  bool result_found = false;

  // Generate patterns for numbers of variable length
  for (auto num_of_digits = 5; num_of_digits < 7; ++num_of_digits)
  {
    // Generate number patterns:
    //   - true: repeating number
    //   - false: non-repeating number
    std::vector<bool> last_pattern(3, true);
    last_pattern.resize(num_of_digits, false);

    std::vector<std::vector<bool>> patterns = permute(last_pattern);

    const unsigned long last = std::pow(10, num_of_digits - 3);
    const unsigned long first = last / 10;

    for (auto i = first + 1; i < last; i += 2)
    {
      if (i % 5 == 0) continue;

      for (const auto& pattern : patterns)
      {
        std::vector<unsigned short> candidate = fill_pattern_with_number(pattern, i);

        for (unsigned short r = 0; r < 3; ++r)
        {
          if (pattern.back() && r == 0) continue;

          fill_repeating_digits(pattern, r, candidate);
          unsigned long candidate_prime = number::number_from_digits<unsigned short, unsigned long>(candidate);

          if (candidate_prime >= result) continue;

          if (prime::is_prime(candidate_prime))
          {
            if (get_prime_family_size(pattern, candidate, r) == 8)
            {
              result = candidate_prime;
              result_found = true;
            }
          }
        }
      }
    }
  }

  if (!result_found) throw std::runtime_error("No result was found.");

  std::cout << result << '\n';
  return 0;
}

size_t get_prime_family_size(const std::vector<bool>& pattern,
                             std::vector<unsigned short>& candidate,
                             unsigned short repeating_digit)
{
  size_t family_size = 1;
  unsigned short current_digit = repeating_digit;

  while (++current_digit < 10)
  {
    for (auto i = 0; i < pattern.size(); ++i)
    {
      if (!pattern[i]) continue;

      candidate[i] = current_digit;
    }

    unsigned long candidate_prime = number::number_from_digits<unsigned short, unsigned long>(candidate);

    if (prime::is_prime(candidate_prime)) ++family_size;
  }

  return family_size;
}

void
fill_repeating_digits(const std::vector<bool>& pattern,
                      unsigned short repeating_digit,
                      std::vector<unsigned short>& candidate)
{
  assert (repeating_digit < 10);

  for (auto i = 0; i < pattern.size(); ++i)
  {
    if (!pattern[i]) continue;
    candidate[i] = repeating_digit;
  }
}

std::vector<unsigned short>
fill_pattern_with_number(const std::vector<bool>& pattern, unsigned long number)
{
  std::vector<unsigned short> ret(pattern.size(), 0);

  for (auto i = 0; i < pattern.size(); ++i)
  {
    if (pattern[i]) continue;

    ret[i] = (number % 10);
    number /= 10;
  }

  assert(number == 0);

  return ret;
}

std::vector<std::vector<bool>> permute(std::vector<bool>& pattern)
{
  std::vector<std::vector<bool>> patterns;

  do
  {
    // discarding numbers where the repeating number is a unity
    if (pattern[0]) continue;
    patterns.push_back(pattern);
  } while (std::prev_permutation(pattern.begin(), pattern.end()));

  return patterns;
}
