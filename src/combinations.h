//
// Created by enrico.m.crisostomo on 31/12/2019.
//

#ifndef PROJECT_EULER_COMBINATIONS_H
#define PROJECT_EULER_COMBINATIONS_H

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

namespace combinations
{
template<typename T, typename R = T>
R binom(T n, T r);

std::vector<size_t> init_combination(size_t k);
bool hast_next(const std::vector<size_t>& vector, size_t n, size_t k);
unsigned long next_combination(std::vector<size_t>& vector, size_t n, size_t k);
size_t next_combination_starting_from(std::vector<size_t>& vector, size_t n, size_t k, size_t last_match);
std::vector<unsigned long>
get_elements_by_index(const std::vector<unsigned long>& vector, const std::vector<size_t>& indexes);

template<typename T, typename R>
R binom(T n, T r)
{
  static std::map<std::pair<T, T>, R> cache;

  if (n < 0 || r < 0) throw std::runtime_error("n and r must be positive");

  if (r > n) return 0;
  if (r == n) return 1;

  const auto& pair = std::make_pair(n, r);

  if (cache.find(pair) == cache.end())
    cache[pair] = binom<T, R>(n - 1, r) + binom<T, R>(n - 1, r - 1);

  return cache[pair];
}

std::vector<size_t>
init_combination(size_t k)
{
  std::vector<size_t> comb_index(k);
  for (auto i = 0; i < k; ++i)
    comb_index[i] = i;

  return comb_index;
}

bool
hast_next(const std::vector<size_t>& vector, size_t n, size_t k)
{
  return vector[k - 1] < n;
}

// TODO: k could be deduced from the vector size
unsigned long
next_combination(std::vector<size_t>& vector, size_t n, size_t k)
{
  size_t idx = k - 1;

  while (idx != 0 && vector[idx] == n - k + idx)
    --idx;

  const size_t changed_index = idx;
  ++vector[idx];

  for (auto i = idx + 1; i < k; ++i)
    vector[i] = vector[i - 1] + 1;

  return changed_index;
}

size_t
next_combination_starting_from(std::vector<size_t>& vector,
                               const size_t n,
                               const size_t k,
                               size_t last_match)
{
  if (last_match >= vector.size())
    throw std::runtime_error("last_match out of range");

  size_t idx = k - 1;

  while (idx != 0 && vector[idx] == n - k + idx)
    --idx;

  if (idx > last_match)
    idx = last_match;

  const size_t changed_index = idx;
  ++vector[idx];

  for (auto i = idx + 1; i < k; ++i)
    vector[i] = vector[i - 1] + 1;

  return changed_index;
}

std::vector<unsigned long>
get_elements_by_index(const std::vector<unsigned long>& vector, const std::vector<size_t>& indexes)
{
  std::vector<unsigned long> ret;
  ret.reserve(indexes.size());

  for (const auto& i : indexes)
    ret.push_back(vector[i]);

  return ret;
}

namespace with_permutation
{
std::vector<bool> init(size_t k, size_t n);

template<typename T>
std::vector<T> get(const std::vector<T>& set, std::vector<bool>& combination_mask);

bool next(std::vector<bool>& combination_mask);

template<typename T>
std::vector<T>
get_masked_elements(const std::vector<T>& elements, const std::vector<bool>& mask);

std::vector<bool> init(size_t k, size_t n)
{
  if (k <= 0) throw std::runtime_error("k must be greater than 0");
  if (k > n) throw std::runtime_error("n must be greater than or equal to n");

  std::vector<bool> combination_mask(k, true);
  combination_mask.resize(n, false);

  return combination_mask;
}

template<typename T>
std::vector<T> get(const std::vector<T>& set, std::vector<bool>& combination_mask)
{
  std::vector<T> ret;

  for (int i = 0; i < set.size(); ++i)
  {
    if (combination_mask[i]) ret.push_back(set[i]);
  }
  return ret;
}

bool next(std::vector<bool>& combination_mask)
{
  return std::prev_permutation(combination_mask.begin(), combination_mask.end());
}

template<typename T>
std::vector<T>
get_masked_elements(const std::vector<T>& elements, const std::vector<bool>& mask)
{
  assert(elements.size() == mask.size());

  std::vector<T> ret;
//  ret.reserve(mask.size());

  for (auto i = 0; i < mask.size(); ++i)
  {
    if (mask[i])
      ret.push_back(elements[i]);
    if (ret.size() == 5)
      break;
  }

  return ret;
}
}
}

#endif //PROJECT_EULER_COMBINATIONS_H
